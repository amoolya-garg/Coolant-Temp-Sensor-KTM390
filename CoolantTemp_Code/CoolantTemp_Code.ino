#include <SPI.h>
#include <SD.h>
File myFile;

class TempSens
{
private:
  int pin;
  int readVal;
  float temp;
public:
  TempSens(int p)
  {
    pin=p;
  }
  float getTemp()
  {
    readVal = analogRead(pin);
    int x = readVal;

    temp = 24.94 + 0.01287*x + 0.0001056*x*x;

    return temp;
  }
}S1(A1);

void setup()
{
  Serial.begin(9600);
  if(!SD.begin(10)){
    Serial.println("Error");
  }
  myFile = SD.open("Coolant.txt", FILE_WRITE);
  myFile.println();
  myFile.close();
}

void loop()
{
  myFile = SD.open("Coolant.txt", FILE_WRITE);
  Serial.println(S1.getTemp());
  myFile.println(S1.getTemp());
  myFile.close();
  delay(500);
}
