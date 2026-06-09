#define BLYNK_TEMPLATE_ID "TMPL3s7fYpOfI"
#define BLYNK_TEMPLATE_NAME "Smart plant and irrigation system"
#define BLYNK_AUTH_TOKEN "XM6wMSzX4TejbAKwTx6eBBoCQsuqQqJt"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <NewPing.h>

char ssid[] = "Sandeep";
char pass[] = "12312354";

// Pins
#define DHTPIN 4
#define DHTTYPE DHT11

#define SOIL_PIN 34
#define TRIG_PIN 18
#define ECHO_PIN 19

#define RELAY_PIN 26
#define BUZZER_PIN 25

#define TOUCH_PIN 27
#define IR_PIN 14

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define TANK_HEIGHT_CM 120
#define MAX_DISTANCE 120

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
DHT dht(DHTPIN, DHTTYPE);
NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);

BlynkTimer timer;

// Manual Pump Control
BLYNK_WRITE(V5)
{
  int state = param.asInt();
  digitalWrite(RELAY_PIN, state);
  Blynk.virtualWrite(V4, state);
}

void sendData()
{
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  int soilRaw = analogRead(SOIL_PIN);

  // Calibration adjust later if needed
  int soilPercent = map(soilRaw, 4095, 1500, 0, 100);
  soilPercent = constrain(soilPercent, 0, 100);

  int distance = sonar.ping_cm();

  if(distance == 0)
    distance = TANK_HEIGHT_CM;

  int waterLevel =
      ((TANK_HEIGHT_CM - distance) * 100) / TANK_HEIGHT_CM;

  waterLevel = constrain(waterLevel, 0, 100);

  // Auto irrigation
  if(soilPercent < 30)
  {
    digitalWrite(RELAY_PIN, HIGH);
    Blynk.virtualWrite(V4, 1);
  }
  else
  {
    digitalWrite(RELAY_PIN, LOW);
    Blynk.virtualWrite(V4, 0);
  }

  // Water low alarm
  if(waterLevel < 20)
  {
    digitalWrite(BUZZER_PIN, HIGH);
  }
  else
  {
    digitalWrite(BUZZER_PIN, LOW);
  }

  // Send to Blynk
  Blynk.virtualWrite(V0, soilPercent);
  Blynk.virtualWrite(V1, temperature);
  Blynk.virtualWrite(V2, humidity);
  Blynk.virtualWrite(V3, waterLevel);

  // OLED Display
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);

  display.setCursor(0,0);
  display.print("Temp: ");
  display.print(temperature);
  display.print(" C");

  display.setCursor(0,16);
  display.print("Hum : ");
  display.print(humidity);
  display.print(" %");

  display.setCursor(0,32);
  display.print("Soil: ");
  display.print(soilPercent);
  display.print(" %");

  display.setCursor(0,48);
  display.print("Tank: ");
  display.print(waterLevel);
  display.print(" %");

  display.display();

  Serial.print("Temp: ");
  Serial.print(temperature);

  Serial.print(" Hum: ");
  Serial.print(humidity);

  Serial.print(" Soil: ");
  Serial.print(soilPercent);

  Serial.print(" Water: ");
  Serial.println(waterLevel);
}

void setup()
{
  Serial.begin(115200);

  Serial.println("Setup Start");
  Serial.println("OLED OK");

  pinMode(RELAY_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  pinMode(TOUCH_PIN, INPUT);
  pinMode(IR_PIN, INPUT);

  digitalWrite(RELAY_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);

  dht.begin();

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    Serial.println("OLED Failed");
  }

  display.clearDisplay();
  display.display();

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  timer.setInterval(2000L, sendData);
}

void loop()
{
  Blynk.run();
  timer.run();
}
