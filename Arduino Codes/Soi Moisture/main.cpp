#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x20, 16, 2);

void setup()
{
	lcd.init();
	lcd.backlight();
  	pinMode(7, LOW);		//Initially Sensor OFF
  	pinMode(A0, INPUT); 
    lcd.setCursor(2, 0);
    lcd.print("Soil Moisture");
}

int readSensor() {
  digitalWrite(7, HIGH);
  delay(10);				//Allow power to settle
  int val = analogRead(A0);
  digitalWrite(7, LOW);		//Sensor OFF
  return val;
}
	
void loop() {
  int val = readSensor();
  int valf = map(val, 0, 151, 0, 1023);  //1023 bcoz 10 bit output
  lcd.setCursor(3, 1);
  lcd.print("Value = ");
  lcd.print(valf);
  delay(1000);
  lcd.setCursor(11, 1);
  lcd.print("    ");
}
