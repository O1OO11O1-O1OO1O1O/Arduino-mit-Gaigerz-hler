#include <SPI.h>
#include <SD.h>

const int chipSelect = 10;
String zahlenreihe[8];
unsigned long zeit; 
unsigned long milliseks;
int index;
long int laenge = 0;

void setup() {

  delay(3000);

  bool check = false;
  Serial.begin(9600);
  
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);

  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  
  Serial.println("Suche SD Karte ...");
  delay(3000);
  
  if (!SD.begin(chipSelect)) {

    Serial.println("SD Karte nicht gefunden!");
    return;
  }
  Serial.println("SD Karte gefunden!");
  delay(3000);
  Serial.println("clear");
  delay(3000);
  
  Serial.println("Anzahl KeySets:");
  delay(1500);
  Serial.print(laenge);
  Serial.println("                ");

  while (!check) {

    if (digitalRead(9) == HIGH) {
      laenge = laenge + 1;
      Serial.print(laenge);
      Serial.println("                ");
      delay(1500);
    }

    if (digitalRead(7) == HIGH) {

      if (laenge != 0) {
        laenge = laenge - 1;
      }
      Serial.print(laenge);
      Serial.println("                ");
      delay(1500);
    }

    if (digitalRead(8) == HIGH) {
      check = true;
      Serial.print(laenge);
      Serial.println("                Q");
      delay(500);
    }
  }
  laenge = laenge * 312;
  delay(2000);
  attachInterrupt(digitalPinToInterrupt(2), counter_hit, FALLING);
}

void loop() {
  
}

void counter_hit() {
  
  int storage;
  String zwischenergebnis;

  digitalWrite(3,HIGH);

  zeit = millis() - milliseks;
    milliseks = millis();

    if (zeit != 0){
      storage = zeit % 100;

      if (storage < 10) {
        zwischenergebnis = String(0) + String(storage);
      }
      else {
        zwischenergebnis = String(storage);
      }
      zahlenreihe[index] = zwischenergebnis;
      index = (index + 1) % 8;
    }

  if (digitalRead(6) == 1) && laenge > 0{
    
    if (index == 0){
    
      for(int i = 0; i < 8; i++) {
        write_data(zahlenreihe[i]);
        Serial.print(zahlenreihe[i]);
        zahlenreihe[i] = "";
        laenge = laenge - 8;
      }
      Serial.println("X");
    }
    
  }
  else {
    Serial.println("OFF");
  }
  digitalWrite(3,LOW);
}



void write_data(String Zahl) {

  digitalWrite(4,HIGH);
  String Daten = String(Zahl); 
  File Datei = SD.open("speicher.txt", FILE_WRITE);

  if (Datei) {
      Datei.print(Daten);
      Datei.close();
      //Serial.println(Daten);
    
  } else {
      Serial.println("Fehler beim Öffnen der Datei!");
  }
  digitalWrite(4,LOW);
}
