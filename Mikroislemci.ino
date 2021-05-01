#include "DHT.h"
#define DHTPIN 7 

#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);

char gelen_karakter;
const int yesil=2,kirmizi=3;

void setup() {
  Serial.begin(9600);
  pinMode(yesil,OUTPUT);
  pinMode(kirmizi,OUTPUT);
  digitalWrite(yesil,LOW);
  digitalWrite(kirmizi,HIGH);
  dht.begin();
}

void loop() {
    
// Veri girilirse yesil isik surekli yanacak
  while(Serial.available() > 0){
    
    float h = dht.readHumidity();
    float t = dht.readTemperature();
    float f = dht.readTemperature(true);
    
    gelen_karakter = Serial.read();
    digitalWrite(yesil,HIGH);
    digitalWrite(kirmizi,LOW);
    
    if(gelen_karakter == '0'){
      Serial.print("Sıcaklık Ölçüldü: ");
      Serial.print(t);
      Serial.println(" C");
    } else if(gelen_karakter == '1'){
      Serial.print("Nem Ölçüldü: % ");
      Serial.println(h);
    } else if(gelen_karakter == '2'){
      Serial.print("Sıcaklık ve Nem Ölçüldü: ");
      Serial.print(t);
      Serial.print(" C, % ");
      Serial.println(h);
    } else {
      Serial.println("Yanlış Girdi.");
    }
  }

 
}
