#include <LiquidCrystal.h>
  float maximum =1012;
float minimum=215;
int Contrast = 80;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int sensorPin = A0; 
int sensorValue;  
int d;
int  vibration=8;
int value;
void setup() {
  Serial.flush();
   analogWrite(6, Contrast);
  lcd.begin(16, 2);
 Serial.begin(9600);
 pinMode(13, OUTPUT);
 pinMode(7,OUTPUT);
}

void loop()
{
  value=digitalRead(vibration);
 sensorValue = analogRead(sensorPin); 
 float percentage =(((sensorValue - maximum )/(minimum - maximum))*100);
  lcd.setCursor(0, 0);
  lcd.print("soil");
   lcd.setCursor(0, 1);
  lcd.print(percentage);
  lcd.setCursor(8,0);
  lcd.print("vib");
  lcd.setCursor(8,1);
  lcd.print(value);
  Serial.println("---------------------");
 Serial.println("moisture Value : ");
 Serial.println(sensorValue);
Serial.println(percentage);
 Serial.println("vibration status");
 if(value==1)
 {
  Serial.println("sensing vibration");
 }
 else
 {
  Serial.println("no vibration");
 }
 if ((percentage>60.0)||(value==1)) 
 {
  d=1;
 }
 else
 {
  d=0;
 } 
 if(d==1)
 {
  tone(7,5000);
  Serial.println("DANGER") ;
delay(500);
 }
 else
 {
   noTone(7); 
   Serial.println("SAFE");
   delay(500);
 }
if ((percentage>60.0)&&(value==1)) 
{
tone(7,5000); 
Serial.println(" HIGH DANGER");
delay(500);
}
else
{
noTone(7); 
delay(500);
} 
delay(2000); 
 }
