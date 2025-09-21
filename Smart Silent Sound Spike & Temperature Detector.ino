#include <LiquidCrystal.h>

// LCD (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int sensor = 7;         // KY-038 sound sensor (digital out)
int led = 9;            // LED pin
int buzzer = 8;         // Buzzer pin
int buttonPin = 6;      // Push button pin (mute)
bool is_on = false;     // Track LED/clap state
unsigned long lastBeepTime = 0;
bool beepState = false;
int lastButtonState = LOW; // for simple edge detection

// Temperature
#define LM35_PIN A3
unsigned long lastTempTime = 0;
float tempC = 0;

void setup() {
  pinMode(sensor, INPUT);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(buttonPin, INPUT); // assume you have stable wiring/pull-down

  lcd.begin(16, 2);
  lcd.setCursor(2, 0);
  lcd.print("Welcome Awsaf");
  delay(1000);

  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("NO ALERT");

  Serial.begin(9600);
}

void loop() {
  // ===== Read inputs =====
  int data = digitalRead(sensor);
  int buttonState = digitalRead(buttonPin);

  // ===== Clap Sensor =====
  if (data == 1) {
    is_on = !is_on;

    if (is_on) {
      lcd.setCursor(4, 0);
      lcd.print("  ALERT    ");  // Extra spaces to overwrite previous
    } else {
      lcd.setCursor(4, 0);
      lcd.print("NO ALERT   ");
      digitalWrite(buzzer, LOW);
      digitalWrite(led, LOW);
      beepState = false;
    }

    delay(300); // Debounce
  }

  // ===== Push button: mute ONLY when alert is active =====
  // Trigger on a LOW->HIGH or HIGH->LOW edge depending on wiring; here we handle a HIGH press
  if (is_on && buttonState == HIGH && lastButtonState == LOW) {
    // Mute and clear alert
    digitalWrite(buzzer, LOW);
    digitalWrite(led, LOW);
    beepState = false;
    lcd.setCursor(4, 0);
    lcd.print("  MUTED    ");
    delay(500); // show MUTED for a short moment
    lcd.setCursor(4, 0);
    lcd.print("NO ALERT   ");
    is_on = false; // clear alert
    delay(300); // debounce
  }

  lastButtonState = buttonState;

  // Beep-beep if ALERT is ON
  if (is_on) {
    unsigned long currentTime = millis();
    if (currentTime - lastBeepTime >= 185) {
      beepState = !beepState;
      digitalWrite(buzzer, beepState);
      digitalWrite(led, beepState);
      lastBeepTime = currentTime;
    }
  }

  // ===== Non-blocking Temperature Reading =====
  unsigned long now = millis();
  if (now - lastTempTime >= 1000) {  // Every 1 sec
    int raw = analogRead(LM35_PIN);
    float voltage = raw * (5.0 / 1023.0);
    tempC = voltage * 100;

    // Print to Serial
    Serial.print("Temp: ");
    Serial.println(tempC);

    // Update LCD (line 2 only)
    lcd.setCursor(0, 1);
    lcd.print("Temp: ");
    lcd.print(tempC);
    lcd.print((char)223); // °
    lcd.print("C   ");

    lastTempTime = now;
  }
}


