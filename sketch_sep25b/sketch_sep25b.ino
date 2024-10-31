#include <Servo.h>

Servo sl;
Servo sr;

const int piezo = 4; 
const int ledPin = 10;

int melody[] = {262, 294, 330, 349, 392, 440, 494, 523}; 
int noteDurations[] = {4, 8, 4, 8, 4, 4, 8, 4};

void setup() {
  sl.attach(12);
  sr.attach(13); 
  pinMode(piezo, OUTPUT);
  pinMode(ledPin, OUTPUT); 
  Serial.begin(9600); 
}

void loop() {
  playMelody();
}


void playMelody() {
  for (int i = 0; i < 8; i++) {
    int duration = 1000 / noteDurations[i]; 
    tone(piezo, melody[i], duration);
    digitalWrite(ledPin, HIGH);
    delay(duration);
    digitalWrite(ledPin, LOW);
    delay(duration * 0.3);
    
    performDance(i); 
  }
}

void performDance(int index) {
  switch (index % 4) {
    case 0:
      forward(1000);
      break;
    case 1:
      backward(1000);
      break;
    case 2:
      turnLeft(1000);
      break;
    case 3:
      turnRight(1000);
      break;
  }

  stopMotors();
}

void forward(int time) {
  sl.write(1700);
  sr.write(1300);
  delay(time);
}

void turnLeft(int time) {
  sl.write(1300);
  sr.write(1300);
  delay(time);
}

void turnRight(int time) {
  sl.write(1700);
  sr.write(1700);
  delay(time);
}


void backward(int time) {
  sl.write(1300); 
  sr.write(1700); 
  delay(time);
}


void stopMotors() {
  sl.write(1500); 
  sr.write(1500);
}
