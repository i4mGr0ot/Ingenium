#define led 13
#define pump 7
void setup()
{
Serial.begin(9600);
pinMode(led, OUTPUT);
pinMode(pump, OUTPUT);
}
void loop()
{
if (Serial.available())
{
 char k = Serial.read();
 if (k == '3')
{
 digitalWrite(led, HIGH);
 }
 if (k == '4')
{
 digitalWrite(led, LOW);
 }
 if (k == '1')
{
 digitalWrite(pump, HIGH);
 }
 if (k == '2')
{
 digitalWrite(pump, LOW);
 }
}
d
