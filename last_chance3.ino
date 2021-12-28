//slave
#define SENSOR1 A0
#define SENSOR2 A1
#define SENSOR3 A2
#define SENSOR4 A3
#define SENSOR5 A4
#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); 
void setup() 
{ 
  Serial.begin(9600);
  mySerial.begin(4800);
  Serial.println("hello, world!");
}

void loop() 
{ 
  Serial.println(analogRead(SENSOR1));
  Serial.println(analogRead(SENSOR2)); 
  Serial.println(analogRead(SENSOR3));
  Serial.println(analogRead(SENSOR4));
  Serial.println(analogRead(SENSOR5));
  
  delay(2400);
  if (mySerial.available()) {
    while (mySerial.available()) {
   		Serial.print(mySerial.read());
  	}
  }   
}

//master
#define PHOTO1 A0
#define PHOTO2 A1
#define PHOTO3 A2
#define PHOTO4 A3
#define PHOTO5 A4
#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX
void setup() 
{ 
  Serial.begin(9600);
  mySerial.begin(4800);
  Serial.println("hello, world?");
}

void loop() 
{ 
  Serial.println(analogRead(PHOTO1));
  Serial.println(analogRead(PHOTO2));
  Serial.println(analogRead(PHOTO3));
  Serial.println(analogRead(PHOTO4));
  Serial.println(analogRead(PHOTO5));
  
  delay(1000);
  
  if (mySerial.available()) {
    while (mySerial.available()) {
   		Serial.print(mySerial.read());
  	}
  }   
}