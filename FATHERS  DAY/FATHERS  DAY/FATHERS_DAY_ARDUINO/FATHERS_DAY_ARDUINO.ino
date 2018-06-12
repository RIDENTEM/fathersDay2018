#include <SD.h>
#include <SPI.h>
#include <Audio.h>

const int trigPin = 9;
const int echoPin = 10;

long duration;
int distance;

void setup() {
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
Serial.begin(9600);
//Sd card stuff
if(!SD.begin(4))
Serial.println("failed");
Audio.begin(88200, 100);


}

void loop() {
File myFile = SD.open("SEINFELD1WAV.wav");
if(!myFile){
  Serial.println("error opening wav file");
  while(true);
}


digitalWrite(trigPin, LOW);
delayMicroseconds(2);

digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);
distance = duration * 0.034f / 2;
Serial.print("Distance: ");
Serial.println(distance);

}
