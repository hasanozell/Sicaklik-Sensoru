int lm35Pin = A0;
int led = 8;
int buzzer = 9;

int zaman = 50;
int okunan_deger = 0;
float sicaklik_gerilim = 0;
float sicaklik = 0;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(2400);

}

void loop() {
  okunan_deger = analogRead(lm35Pin);
  sicaklik_gerilim = (5000.0/1023.0) * okunan_deger;
  sicaklik = sicaklik_gerilim / 10.0;

  Serial.println(sicaklik);


  if(sicaklik >= 35) {
    digitalWrite(led, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(zaman);
    digitalWrite(led,LOW);
    digitalWrite(buzzer, LOW);
    delay(zaman);
  }
 else{
  digitalWrite(led,LOW);
    digitalWrite(buzzer, LOW);
 }
}
