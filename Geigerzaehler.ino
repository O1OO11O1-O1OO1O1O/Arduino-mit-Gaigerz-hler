unsigned long treffer = 0;
unsigned long tpm = 0;
unsigned long milliseks = 0;
unsigned long zeit = 0;
volatile bool newData = false;

void setup() {

  pinMode(2, INPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(2), counter_hit, FALLING);
}

void loop() {

  if (newData) {
    Serial.println(treffer);
    zeit = millis() - milliseks;
    Serial.println(zeit);
    milliseks = millis();
    newData = false;
  }

}

void counter_hit() { 
  treffer++;
  newData = true;
}