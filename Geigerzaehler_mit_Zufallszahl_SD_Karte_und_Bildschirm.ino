#include <SPI.h>
#include <SD.h>
//#include <Wire.h> 
//#include <LiquidCrystal_I2C.h>

const int chipSelect = 10;
  String zahlenreihe[8];
  unsigned long zeit; 
  unsigned long milliseks;
  int storage;
  int index;
  String zwischenergebnis;


//LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {

  delay(3000);
  
  //lcd.setCursor(0,0);
  //lcd.begin();
	//lcd.backlight();
	//lcd.print("");
  //lcd.setCursor(0,1);
  //lcd.clear()
  

  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  //lcd.print("Suche SD Karte..");
  Serial.println("Suche SD Karte ..."); //ln
  delay(3000);
  
  if (!SD.begin(chipSelect)) {
    //lcd.clear();
    //lcd.print("SD Karte nicht");
    //lcd.setCursor(0,1);
    //lcd.print("gefunden!");
    Serial.println("SD Karte nicht gefunden!"); //ln
    return;
  }
  //lcd.clear();
  //lcd.print("SD Karte");
  //lcd.setCursor(0,1);
  //lcd.print("gefunden!");
  
  Serial.println("SD Karte gefunden!"); //ln

  attachInterrupt(digitalPinToInterrupt(2), counter_hit, FALLING);
}

void loop() {
  //String abc[100] = {"A", "Ä", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "Ö", "P", "Q", "R", "S", "T", "U", "Ü", "V", "W", "X", "Y", "Z", "a", "ä", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "ö", "p", "q", "r", "s", "t", "u", "ü", "v", "w", "x", "y", "z", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "!", "#", "$", "%", "&", "'", "(", ")", "*", "+", ",", "-", ".", "/", ":", ";", "<", "=", ">", "?", "@", "[", "]", "^", "_", "`", "{", "|", "}", "~", " ", "°"} ;
  //for(int i = 0; i < 8; i++) {
    //Serial.print(zahlenreihe[i]);
    //Serial.print(",");
  //}
  //Serial.println(" ");
}

void counter_hit() {

  digitalWrite(3,HIGH);

  //lcd.clear();
  //lcd.setCursor(0,0);
  //lcd.print("Berechnung läuft");
  //String zahlenreihe[8];
  
  //Serial.print("millis: ");
  //Serial.print(millis()); //ln

  zeit = millis() - milliseks;
  //Serial.print("zeit: ");
  //Serial.print(zeit); //ln
  milliseks = millis();
  storage = zeit % 100;

  if (storage < 10) {
    zwischenergebnis = String(0) + String(storage);
  }

  else {
    zwischenergebnis = String(storage);
  }

  //Serial.print("index: ");
  //Serial.println( index);

  zahlenreihe[index] = zwischenergebnis;
  index = (index + 1) % 8;

  //Serial.print("index: ");
  //Serial.println( index);

  Serial.print("X");

  for(int i = 0; i < 8; i++) {
    Serial.print(zahlenreihe[i]);
    //Serial.print(",");
  }

  Serial.println(" "); //ln

  

  if (index == 0){

    for(int i = 0; i < 8; i++) {
    write_data(zahlenreihe[i]);
    zahlenreihe[i] = "";
    //lcd.setCursor(i*2,1);
    //lcd.print(zahlenreihe[i]);
    }
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
      Serial.println(Daten); //ln
    
  } else {
      //lcd.clear();
      //lcd.setCursor(0,0);
      //lcd.print("Fehler beim");
      //lcd.setCursor(0,1);
      //lcd.print("Offnen der Datei");
      Serial.println("Fehler beim Öffnen der Datei!"); //ln
  }

  digitalWrite(4,LOW);

}