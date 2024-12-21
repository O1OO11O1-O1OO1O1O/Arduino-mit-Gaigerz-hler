unsigned long treffer = 0;
unsigned long tpm = 0;
unsigned long milliseks = 0;
unsigned long zeit = 0;
volatile bool newData = false;
const int laenge = 100;
String zahlenreihe[laenge];
int index = 0;
int storage = 0;
String zwischenergebnis = "0";

void setup() {

  pinMode(2, INPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(2), counter_hit, FALLING);
}

void loop() {

  if (newData) {
    Serial.println(" ");
    Serial.println(treffer);
    zeit = millis() - milliseks;
    Serial.println(zeit);
    milliseks = millis();
    newData = false;
    
    storage = zeit % 100;
    if (storage < 10) {
      zwischenergebnis = String(0) + String(storage);
    }
    else {
      zwischenergebnis = String(storage);
    }
    zahlenreihe[index] = zwischenergebnis;
    index = (index + 1) % laenge;
    for(int i = 0; i < laenge; i++) {
      Serial.print(zahlenreihe[i]);
      Serial.print(" ");
    }
  }

}

void counter_hit() { 
  treffer++;
  newData = true;
}