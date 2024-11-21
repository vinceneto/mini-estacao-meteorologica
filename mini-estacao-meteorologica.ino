#include <Wire.h>
#include <Adafruit_BMP280.h>

#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BMP280 bmp; // I2C

void setup() 
{
  Serial.begin(9600);
  
  while ( !Serial ) delay(100);
  
  unsigned status;
  status = bmp.begin(0x76);
  
  if (!status) 
  {
    Serial.println("Nao foi possivel encontrar um sensor BMP280 valido, cheque o circuito!");
  }
}

void loop() 
{
    Serial.print(F("Temperatura = "));
    Serial.print(bmp.readTemperature());
    Serial.println(" *C");

    Serial.print(F("Pressao = "));
    Serial.print(bmp.readPressure());
    Serial.println(" Pa");

    Serial.print(F("Altitude aprox. = "));
    Serial.print(bmp.readAltitude(SEALEVELPRESSURE_HPA));
    Serial.println(" m");

    Serial.println();
    delay(2000);
}
