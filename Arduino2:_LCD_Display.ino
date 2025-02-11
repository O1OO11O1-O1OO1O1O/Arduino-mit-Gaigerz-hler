#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

char zeichen1 = 'X';
char zeichen2 = 'O';
char zeichen3 = 'Q';
unsigned long milliseks;
int platz = 0;
String Input;

void setup() {
  lcd.setCursor(0,0);
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();
  lcd.clear();

  //lcd.setCursor(0,0);
  //lcd.begin();
	//lcd.backlight();
	//lcd.print("");
  //lcd.setCursor(0,1);
  //lcd.clear();
}

void loop() {
  lcd.setCursor(0,0);

  if (Serial.available() > 0){
    Input = Serial.readString();
    
    Input.replace("\r", "");
    Input.replace("\n", "");
  }

  if (Input == "clear"){
    lcd.clear();
    Serial.print("Input: ");
    Serial.println(Input);
  }

  if (Input == "SD Karte gefunden!"){
    lcd.clear();
    lcd.print("SD Karte");
    lcd.setCursor(0,1);
    lcd.print("gefunden!");
    Serial.print("Input: ");
    Serial.println(Input);
  }

  if (Input == "SD Karte nicht gefunden!"){
    lcd.clear();
    lcd.print("SD Karte nicht");
    lcd.setCursor(0,1);
    lcd.print("gefunden!");
    Serial.print("Input: ");
    Serial.println(Input);
  }

  if (Input == "Suche SD Karte ..."){
    lcd.clear();
    lcd.print("Suche SD Karte..");
    Serial.print("Input: ");
    Serial.println(Input);
  }

  if (Input.indexOf(zeichen1) != -1){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Zufallszahlen:");
    lcd.setCursor(0,1);
    lcd.print(Input);
    Serial.print("Input: ");
    Serial.println(Input);
  }

  if (Input == "Fehler beim Öffnen der Datei!"){
    lcd.clear();
    lcd.print("Fehler:");
    lcd.setCursor(0,1);
    lcd.print("");
    Serial.print("Input: ");
    Serial.println(Input);
  }

  if (Input.indexOf(zeichen2) != -1){
    lcd.clear();
    lcd.print("Standby...");
    lcd.setCursor(platz,1);
    lcd.print("(-_-)");
    Serial.print("Input: ");
    Serial.println(Input);
  }
  
  if (millis() > milliseks + 700){
    milliseks = millis();
    platz = (platz + 1) % 12;
  }

  if (Input == "Anzahl KeySets:"){

    while (Input.indexOf(zeichen3) == -1){
      Serial.print("Input: ");
      Serial.println(Input);
      lcd.clear();
      lcd.print("Anzahl KeySets:");
      lcd.setCursor(0,1);
      
      if (Input != "Anzahl KeySets:"){
        lcd.print(Input);
      }
      delay(100);
      if (Serial.available() > 0){
        Input = Serial.readString();
    
        Input.replace("\r", "");
        Input.replace("\n", "");
      }
    }
  }

  if (Input.indexOf(zeichen3) != -1){
      lcd.clear();
      lcd.print("Anzahl KeySets:");
      lcd.setCursor(0,1);
      lcd.print("->");
      lcd.setCursor(2,1);
      lcd.print(Input);
  }

  if (Input.length() > 29){
    lcd.clear();
    Input = "";
  }

  delay(200);
}
