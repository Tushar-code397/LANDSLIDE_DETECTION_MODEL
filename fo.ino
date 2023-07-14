
#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
int contrast =100;
unsigned char SOIL1 = 0;

const int vs1 = 4;
const int BUZZ = 6;

boolean SOIL_A=0,VIB_A=0;

long measurement1;

void setup() 
{
   pinMode(vs1, INPUT);
   pinMode(BUZZ, OUTPUT);
   pinMode(A0, INPUT);
   
   digitalWrite(BUZZ, HIGH);//OFF

  lcd.begin(16,2);
  
  lcd.print("   LANDSLIDE    ");
  lcd.setCursor(0,1);
  lcd.print(" DETECTION  IOT ");
  
 // Serial.begin(115200);
}
void loop() 
{
   lcd.setCursor(0,0);///////////;
   lcd.print("V     S  ");
  
  
  ///////////////VIB_A//////////////////////
  measurement1 =vs1;
  if (measurement1 >= 9999)
  {
    measurement1 = 9999;
  }
 
  lcd.setCursor(0,1);
  lcd.print("                ");
  lcd.setCursor(0,1);
  lcd.print(measurement1);
  
  if (measurement1 > 100)
  {
    VIB_A=1;
  }
  else
  {
    VIB_A=0;
  }
  //////////////////////////////////////////
  delay(100);
  ///////////////VIB_B//////////////////////
  
  ////////////////SOIL_A///////////////////////  
  SOIL1= analogRead(A0)/10.5;
  if(SOIL1<=1 )
    SOIL1=1;
  if(SOIL1>=90)
    SOIL1=90;
  SOIL1=100-SOIL1;
  delay(10);

  lcd.setCursor(6,1);
  lcd.print(SOIL1);
 // lcd.setCursor(10,1);
 // lcd.print("%");
//  lcd.setCursor(11,1);
//  lcd.print(" ");
  ///////////////////////////////////////
  if(SOIL1>=60)
  {
    SOIL_A=1;
  }
  else
  {
    SOIL_A=0;
  }
  ////////////////////////////////
  delay(100);
}
 
 
 
long vibration1()
{
  long measurement1=pulseIn (vs1, HIGH);  //wait for the pin to get HIGH and returns measurement
  return measurement1;
}
