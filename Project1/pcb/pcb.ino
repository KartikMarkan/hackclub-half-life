
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

// ===================================
// OLED SCREEN SETTINGS
// ===================================

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define OLED_ADDRESS 0x3C

Adafruit_SSD1306 display(
  SCREEN_WIDTH,
  SCREEN_HEIGHT,
  &Wire,
  OLED_RESET
);

// ===================================
// PIN CONNECTIONS FROM KICAD
// ===================================

// Left button SW1
const int LEFT_BUTTON = D2;

// Right button SW2
const int RIGHT_BUTTON = D3;

// LED
const int LED_PIN = D6;

// DHT11 temperature/humidity sensor
const int DHT_PIN = D1;

// ===================================
// DHT11 SENSOR SETTINGS
// ===================================

#define DHT_TYPE DHT11

DHT dht(DHT_PIN, DHT_TYPE);

// ===================================
// PROGRAM VARIABLES
// ===================================

// 0 = Startup
// 1 = Hello mode
// 2 = Temperature/humidity mode

int currentMode = 0;

// Track previous button states
bool previousLeft = HIGH;
bool previousRight = HIGH;

// Track sensor update time
unsigned long lastUpdate = 0;

// ===================================
// DISPLAY STARTUP SCREEN
// ===================================

void showStartup() {
  display.clearDisplay();

  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);

  display.setCursor(15, 25);
  display.println("Starbie!");

  display.display();
}

// ===================================
// LEFT BUTTON: DISPLAY HELLO
// ===================================

void showHello() {
  display.clearDisplay();

  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);

  display.setCursor(25, 25);
  display.println("Hello!");

  display.display();
}

// ===================================
// RIGHT BUTTON: WEATHER
// ===================================

void showWeather() {

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  display.setCursor(0, 0);

  display.println("STARBIE WEATHER");
  display.println("----------------");

  if (isnan(humidity) || isnan(temperature)) {

    display.println("Sensor error!");

  } else {

    display.print("Temp: ");
    display.print(temperature, 1);
    display.println(" C");

    display.print("Humidity: ");
    display.print(humidity, 1);
    display.println(" %");
  }

  display.display();
}

// ===================================
// SETUP - RUNS ONCE
// ===================================

void setup() {

  Serial.begin(115200);

  // Set buttons as inputs
  pinMode(LEFT_BUTTON, INPUT_PULLUP);
  pinMode(RIGHT_BUTTON, INPUT_PULLUP);

  // Set LED as output
  pinMode(LED_PIN, OUTPUT);

  // LED starts OFF
  digitalWrite(LED_PIN, LOW);

  // Start DHT11 sensor
  dht.begin();

  // Start I2C
  // SDA = D5
  // SCL = D4
  Wire.begin(D5, D4);

  // Initialize OLED
  if (!display.begin(
    SSD1306_SWITCHCAPVCC,
    OLED_ADDRESS
  )) {

    Serial.println("OLED initialization failed!");

    while (true) {
      delay(1000);
    }
  }

  // Show startup screen
  showStartup();
}

// ===================================
// LOOP - RUNS REPEATEDLY
// ===================================

void loop() {

  // Read both buttons
  bool leftState = digitalRead(LEFT_BUTTON);
  bool rightState = digitalRead(RIGHT_BUTTON);

  // ---------------------------------
  // LEFT BUTTON PRESSED
  // ---------------------------------

  if (leftState == LOW && previousLeft == HIGH) {

    currentMode = 1;

    // Turn LED ON
    digitalWrite(LED_PIN, HIGH);

    // Display Hello!
    showHello();
  }

  // ---------------------------------
  // RIGHT BUTTON PRESSED
  // ---------------------------------

  if (rightState == LOW && previousRight == HIGH) {

    currentMode = 2;

    // Turn LED OFF
    digitalWrite(LED_PIN, LOW);

    // Display sensor readings
    showWeather();

    lastUpdate = millis();
  }

  // Save button states
  previousLeft = leftState;
  previousRight = rightState;

  // ---------------------------------
  // UPDATE WEATHER EVERY 2 SECONDS
  // ---------------------------------

  if (currentMode == 2) {

    if (millis() - lastUpdate >= 2000) {

      lastUpdate = millis();

      showWeather();
    }
  }

  // Small delay for button stability
  delay(30);
}

