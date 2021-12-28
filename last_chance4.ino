#include <SoftwareSerial.h>

#только для двух плат

SoftwareSerial mySerial(10, 11);
void setup() {
  pinMode(10, INPUT);
  pinMode(11, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  Serial.begin(9600);
  mySerial.begin(4800);
  delay(50);
}


void loop() {
  if (Serial.available() >= 3) {
    int16_t red6 = Serial.read();
    int16_t green3 = Serial.read();
    int16_t blue5 = Serial.read();
    
    analogWrite(3, green3);
    analogWrite(5, blue5);
    analogWrite(6, red6);
    while (Serial.available() > 0) {
      mySerial.write(Serial.read());
    } 
  }
  delay(100);
}
