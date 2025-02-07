#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

char zeichen = 'X';

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

  if (Serial.available() > 0){
    String Input = Serial.readString();
    
    Input.replace("\r", "");
    Input.replace("\n", "");

    if (Input == "SD Karte gefunden!"){
      lcd.clear();
      lcd.print("SD Karte");
      lcd.setCursor(0,1);
      lcd.print("gefunden!");
    }

    if (Input == "SD Karte nicht gefunden!"){
      lcd.clear();
      lcd.print("SD Karte nicht");
      lcd.setCursor(0,1);
      lcd.print("gefunden!");
    }

    if (Input == "Suche SD Karte ..."){
      lcd.clear();
      lcd.print("Suche SD Karte..");
    }

    if (Input.indexOf(zeichen) != -1){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Berechnung:");
      lcd.setCursor(0,1);
      lcd.print(Input);
    }

  }

}
