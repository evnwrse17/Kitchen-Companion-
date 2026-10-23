

#include <LiquidCrystal.h>

// Initialize LCD pins based on your physical layout (RS, E, D4, D5, D6, D7)
// Connected via Row A (Pins: 10A->12, 12A->11, 17A->5, 18A->4, 19A->3, 20A->2)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Pin Definitions matching your component placements
const int btnNext = 7;         // Button at Column 25
const int btnClaim = 8;        // Button at Column 30
const int buzzerPin = 9;       // Buzzer at Column 36
const int ledRed = 10;         // Red LED at Column 53
const int ledGreen = 6;        // Green LED at Column 50
const int lightSensorPin = A0; // Photoresistor at Column 44

// Task List
const char* tasks[] = {
  "1. Fold Laundry",
  "2. Wash Dishes",
  "3. Water Plants",
  "4. Prep Dinner"
};
const int totalTasks = 4;
int currentTaskIndex = 0;

// Hydration/Break Tracker Variables
unsigned long activeWorkTime = 0;
unsigned long lastCheckTime = 0;
const int lightThreshold = 400; // Adjust based on ambient room light
const unsigned long breakInterval = 30000; // 30 seconds for demo (set higher for real use)

void setup() {
  lcd.begin(16, 2);
  pinMode(btnNext, INPUT);
  pinMode(btnClaim, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);

  // Initial Screen Display
  lcd.clear();
  lcd.print("Smart Task Node");
  lcd.setCursor(0, 1);
  lcd.print("Ready...");
  delay(2000);
  displayTask();
}

void loop() {
  // 1. Task Navigation
  if (digitalRead(btnNext) == HIGH) {
    currentTaskIndex = (currentTaskIndex + 1) % totalTasks;
    displayTask();
    delay(250); // Simple debounce delay
  }

  // 2. Task Claim / Complete
  if (digitalRead(btnClaim) == HIGH) {
    lcd.clear();
    lcd.print("Task Claimed!");
    lcd.setCursor(0, 1);
    lcd.print("Thank You!");

    // Play chime and flash Green LED
    digitalWrite(ledGreen, HIGH);
    tone(buzzerPin, 1000, 200);
    delay(300);
    tone(buzzerPin, 1500, 300);
    delay(1000);
    digitalWrite(ledGreen, LOW);

    displayTask();
  }

  // 3. Hydration & Activity Tracker
  int lightLevel = analogRead(lightSensorPin);

  if (lightLevel > lightThreshold) {
    // Activity detected (e.g., room lights on / working area active)
    if (millis() - lastCheckTime >= 1000) {
      activeWorkTime += 1000;
      lastCheckTime = millis();
    }
  } else {
    // Reset or pause tracker if room is dark/inactive
    lastCheckTime = millis();
  }

  // Trigger hydration break reminder
  if (activeWorkTime >= breakInterval) {
    triggerBreakReminder();
    activeWorkTime = 0; // Reset timer after reminder
  }
}

void displayTask() {
  lcd.clear();
  lcd.print("Current Task:");
  lcd.setCursor(0, 1);
  lcd.print(tasks[currentTaskIndex]);
}

void triggerBreakReminder() {
  digitalWrite(ledRed, HIGH);
  lcd.clear();
  lcd.print("** TIME FOR A **");
  lcd.setCursor(0, 1);
  lcd.print("DRINK WATER / REST");

  // Gentle reminder tone sequence
  for (int i = 0; i < 3; i++) {
    tone(buzzerPin, 880, 150);
    delay(200);
  }

  delay(3000);
  digitalWrite(ledRed, LOW);
  displayTask();
}

