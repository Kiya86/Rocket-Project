#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_BMP280.h>
#include <DHT.h>
#include <SPI.h>
#include <SD.h>
#include <WiFi.h>
#include <esp_now.h>

// Sensors
Adafruit_MPU6050 mpu;
Adafruit_BMP280 bmp;
#define DHTPIN 15
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// SD card
#define SD_CS 5
File dataFile;
int flightNumber = 1;
bool isLogging = false;

// LEDs
#define ORANGE_LED 2
#define BLUE_LED 4
#define GREEN_LED 12

// Button and debounce parameters
#define BUTTON_PIN 25
bool lastButtonState = HIGH;
bool buttonState = HIGH;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

// Serial input buffer
String serialInput = "";

// ESP-NOW
uint8_t groundStationMAC[] = {0x5C, 0x01, 0x3B, 0x4A, 0x27, 0xF4}; // Ground station MAC
typedef struct struct_message {
  char command[20]; // Changed to match ground station
} struct_message;

String currentFilename = ""; // Global variable to store filename

void setup() {
  Serial.begin(115200);

  // LED setup
  pinMode(ORANGE_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  // Button
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  // Standby LED ON
  digitalWrite(ORANGE_LED, HIGH);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(BLUE_LED, LOW);

  // Init sensors
  Wire.begin(21, 22); // SDA, SCL

  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050");
    signalError();
  }

  if (!bmp.begin(0x76)) {
    Serial.println("Failed to find BMP280");
    signalError();
  }

  dht.begin();

  // Blink blue LED to indicate sensor setup success
  for (int i = 0; i < 6; i++) {
    digitalWrite(BLUE_LED, i % 2);
    delay(250);
  }
  digitalWrite(BLUE_LED, LOW);

  // Initialize SD card
  if (!SD.begin(SD_CS)) {
    Serial.println("SD Card initialization failed!");
    signalError();
  }

  // ESP-NOW setup
  WiFi.mode(WIFI_STA);
  if (esp_now_init() != ESP_OK) {
    Serial.println("ESP-NOW init failed");
    signalError();
  }
  esp_now_register_recv_cb(OnDataRecv);
  esp_now_peer_info_t peerInfo;
  memcpy(peerInfo.peer_addr, groundStationMAC, 6);
  peerInfo.channel = 1;
  peerInfo.encrypt = false;
  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Failed to add peer");
    signalError();
  }

  Serial.println("System Ready. Type 'start' or press button to begin logging.");
}

void loop() {
  handleSerialInput();
  handleButton();

  if (isLogging) {
    logData();
    delay(200);
  }
}

void handleSerialInput() {
  while (Serial.available()) {
    char c = Serial.read();
    if (c == '\n' || c == '\r') {
      if (serialInput == "start") startLogging();
      else if (serialInput == "stop") stopLogging();
      serialInput = "";
    } else {
      serialInput += c;
    }
  }
}

void handleButton() {
  bool reading = digitalRead(BUTTON_PIN);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading == LOW && buttonState == HIGH) {
      if (isLogging) stopLogging();
      else startLogging();
    }
    buttonState = reading;
  }
  lastButtonState = reading;
}

void startLogging() {
  do {
    currentFilename = "/Flight" + String(flightNumber++) + ".txt";
  } while (SD.exists(currentFilename));

  dataFile = SD.open(currentFilename, FILE_WRITE);
  if (!dataFile) {
    Serial.println("Failed to open file on SD");
    signalError();
  }

  Serial.println("Logging started: " + currentFilename);
  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(ORANGE_LED, LOW);
  isLogging = true;

  dataFile.println("Time(ms),AccelX,AccelY,AccelZ,GyroX,GyroY,GyroZ,Temp(*C),Press(hPa),Humidity(%)");
  sendFilename(currentFilename.c_str()); // Send filename to ground station
}

void stopLogging() {
  if (dataFile) {
    dataFile.close();
    Serial.println("Logging stopped and file closed.");
  }
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(ORANGE_LED, HIGH);
  isLogging = false;
}

void logData() {
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  float pressure = bmp.readPressure() / 100.0;
  float temperature = bmp.readTemperature();
  float humidity = dht.readHumidity();

  unsigned long timestamp = millis();

  String entry = String(timestamp) + "," +
                 a.acceleration.x + "," + a.acceleration.y + "," + a.acceleration.z + "," +
                 g.gyro.x + "," + g.gyro.y + "," + g.gyro.z + "," +
                 temperature + "," + pressure + "," + humidity;

  dataFile.println(entry);
  dataFile.flush();
}

void signalError() {
  digitalWrite(ORANGE_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(BLUE_LED, HIGH);
  while (true);
}

void OnDataRecv(const esp_now_recv_info *recv_info, const uint8_t *incomingData, int len) {
  struct_message incomingMessage;
  memcpy(&incomingMessage, incomingData, sizeof(incomingMessage));
  Serial.print("Bytes received: ");
  Serial.println(len);
  Serial.print("Command: ");
  Serial.println(incomingMessage.command);

  if (strcmp(incomingMessage.command, "START") == 0) {
    startLogging();
  } else if (strcmp(incomingMessage.command, "STOP") == 0) {
    stopLogging();
  }
}

void sendFilename(const char* filename) {
  struct_message filenameMessage;
  strcpy(filenameMessage.command, filename);
  esp_err_t result = esp_now_send(groundStationMAC, (uint8_t*)&filenameMessage, sizeof(filenameMessage));
  if (result != ESP_OK) {
    Serial.println("Failed to send filename");
  }
}