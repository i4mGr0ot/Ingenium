void setup()
{
  pinMode(11, OUTPUT);
}

void loop()
{
  int pVal = analogRead(A1);
  int brightness = map(pVal, 0, 1023, 0, 255);
  analogWrite(11, brightness);
}
