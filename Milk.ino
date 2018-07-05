//Made by Parth Ghumatkar
#include <Adafruit_Sensor.h>
#include <DHT.h>
#define DHTPIN 2     
#define DHTTYPE DHT11  
#define buzzer 6
#define led 5
#define greenled 7
int maxTemp = 43;
int minTemp = 25;

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);
   pinMode(greenled, OUTPUT);
  Serial.begin(9600); 
  dht.begin();
}

void loop() {
  
  delay(2000);
    
  float t = dht.readTemperature();
  
  if ( isnan(t)) {
    Serial.println("DHT sensor not working!");
    return;
  }
  
  if( t > maxTemp) {
      digitalWrite(buzzer, HIGH);
      digitalWrite(led, HIGH);
      digitalWrite(greenled,HIGH); 
   
  } else {
     digitalWrite(buzzer, LOW); 
     digitalWrite(led,LOW); 
     digitalWrite(greenled,HIGH); 
  }
  Serial.print(" %\t");
  Serial.print("Temperature: "); 
  Serial.print(t);
  Serial.println();
  
}
