// defines pins numbers
#include <Wire.h>
#include "MMA7660.h"

MMA7660 accelemeter;

const int trigPin1 = 10;
const int echoPin1 = 9;
const int sda = A4;
const int scl = A5;
const int speaker = 12;

double newAcc, newTime, newVel;
double oldVel, oldAcc, oldTime = 0;

long d;
double distance1, lastDistance;
double duration1;

void setup() {
  accelemeter.init();
  pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin1, INPUT); // Sets the echoPin as an Input
  pinMode(sda, INPUT);
  pinMode(scl, INPUT);
 
  Serial.begin(9600); // Starts the serial communication
}

void loop() {
  float ax,ay,az;
  
  // Clears the trigPin
  delayMicroseconds(2);
  
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration1 = pulseIn(echoPin1, HIGH);
  
  // Calculating the distance
  distance1 = (int)(duration1 * 0.034 / 2.0);
  Serial.println(distance1);

  if(distance1 > 2000){
    noTone(speaker);
  } else if(distance1 < 1000 || (lastDistance < 2000 && distance1 > 2000)){
    tone(speaker, 500 - distance1);
  } else {
    noTone(speaker);
  }
  lastDistance = distance1;
  
//  if(distance1 <= 0.45){
//    //tone(speaker, 200);
//    Serial.println("45");
//  }
//  else if(distance1 > 0.45){
//    accelemeter.getAcceleration(&ax, &ay, &az);
//    newTime = millis() / 1000.0;
//    newAcc = (-ax) * 9.81;
//    newVel = oldVel + ((newAcc - oldAcc) * (newTime - oldTime));
//    double deltaT = (-newVel + sqrt((newVel * newVel) - (2 * newAcc * (distance1 - 0.45)))) / newAcc;
//    //tone(speaker, (magA *  * 200);
//    Serial.print(distance1);
//    Serial.print(" ");
//    Serial.print(newAcc);
//    Serial.print(" ");
//    Serial.println(deltaT);
//    oldVel = newVel;
//    oldAcc = newAcc;
//    oldTime = newTime;
//  }
}
