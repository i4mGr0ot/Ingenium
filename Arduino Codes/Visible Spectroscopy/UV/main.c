#include <wire.h>

#define   AS7265_ADDRESS  0X49
#define  ML8511_PIN  A0

void setup ()  {
      Serial.begin( 9600 ) ;
      Wire.begin () ;
}

Void loop ()   {

       Wire.beginTransmission (AS7265_ADDRESS);
       Wire.write(0 x 00) ;
       Wire.endTransmission (false );
       Wire.requestFrom(AS7265_ADDRESS , 18);
       While ( Wire.available() )    {

Serial.print( Wire.read () , HEX) ; 
Serial.print( “  “ );
}

Serial.printIn () ;

int UVlevel = analogread(ML8511_PIN);

Serial.print(“UV level : “ );
Serial.printIn (uv level);

delay(1000);

}
