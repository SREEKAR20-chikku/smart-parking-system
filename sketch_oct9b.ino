#include <Servo.h>

// IR sensor pins
#define SLOT1 13
#define SLOT2 12
#define SLOT3 14
#define SLOT4 27
#define SLOT5 26

Servo gate;

void setup() {
  Serial.begin(115200);

  pinMode(SLOT1, INPUT);
  pinMode(SLOT2, INPUT);
  pinMode(SLOT3, INPUT);
  pinMode(SLOT4, INPUT);
  pinMode(SLOT5, INPUT);

  gate.attach(4);   // Servo connected to GPIO 4
  gate.write(0);    // Start with gate closed

  Serial.println("Smart Parking System Ready");
}

void loop() {
  int slot1 = digitalRead(SLOT1); // HIGH = empty, LOW = occupied (depends on IR sensor type)
  int slot2 = digitalRead(SLOT2);
  int slot3 = digitalRead(SLOT3);
  int slot4 = digitalRead(SLOT4);
  int slot5 = digitalRead(SLOT5);

  int occupied = 0;
  if (slot1 == LOW) occupied++;
  if (slot2 == LOW) occupied++;
  if (slot3 == LOW) occupied++;
  if (slot4 == LOW) occupied++;
  if (slot5 == LOW) occupied++;

  int available = 5 - occupied;

  Serial.print("Slots Available: ");
  Serial.println(available);

  // Example: open gate if a car is at entry and slots available
  if (available > 0) {
    gate.write(90); // open gate
    delay(2000);
    gate.write(0);  // close gate
  }

  delay(1000);
}

}