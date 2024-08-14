#define fire 6
#define buz 7

int fr;

void setup() {
  pinMode(fire, INPUT);
  pinMode (buz, OUTPUT);

}

void loop() {
  fr = digitalRead(fire);

  if (fr == 0) {
    digitalWrite(buz, HIGH);
  } else {
    digitalWrite(buz, LOW);
  }
  delay(200);

}
