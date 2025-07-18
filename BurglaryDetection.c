#include <Keypad.h>
#include <SoftwareSerial.h>

// Keypad setup
const byte ROWS = 4;
const byte COLS = 3;
char keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};
byte rowPins[ROWS] = {9, 8, 7, 6};  
byte colPins[COLS] = {5, 4, 3};    

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Motion sensor and GSM setup
#define motionSensorPin 10
#define passwordLength 5  // 4 digits + null terminator
char correctPassword[passwordLength] = "1234";
char enteredPassword[passwordLength];
byte passwordIndex = 0;

SoftwareSerial gsm(11, 12);  // GSM TX -> pin 11, GSM RX -> pin 12

void setup() {
  Serial.begin(9600);
  gsm.begin(9600);
  pinMode(motionSensorPin, INPUT);
  Serial.println("System Initialized. Waiting for event...");
}

void loop() {
  if (digitalRead(motionSensorPin) == HIGH) {
    Serial.println("Motion Detected!");
    passwordIndex = 0;
    memset(enteredPassword, 0, sizeof(enteredPassword));
    bool accessGranted = getPasswordFromKeypad();

    if (!accessGranted) {
      Serial.println("Wrong password or timeout!");
      Serial.println("GSM Module is dialing the number...");
      triggerCall();
    } else {
      Serial.println("Access Granted. No call made.");
    }
    delay(5000);  
  }
}

bool getPasswordFromKeypad() {
  Serial.println("Enter Password:");
  unsigned long startTime = millis();

  while (millis() - startTime < 60000) {  
    char key = keypad.getKey();
    if (key) {
      Serial.print(key);
      if (key == '#') {
        enteredPassword[passwordIndex] = '\0';
        return strcmp(enteredPassword, correctPassword) == 0;
      } else if (passwordIndex < passwordLength - 1) {
        enteredPassword[passwordIndex++] = key;
      }
    }
  }
  Serial.println("\nTimeout!");
  return false;
}

void triggerCall() {
  Serial.println("Dialing...");
  gsm.println("ATD+7997264354;");  //replace it with your Number 
  delay(10000);  
  gsm.println("ATH"); 
  Serial.println("Call ended.");
}
