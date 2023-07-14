int vibration_signal =8;
void setup()
{
  pinMode (vibration_signal,INPUT);
  Serial.begin(9600);
}
void loop()
{
  int sensor_state;
  Serial.println("vibration status");
  sensor_state=digitalRead(vibration_signal);
  if(sensor_state==1)
  {
    Serial.println("sensing vibration");
  }
  else
  {
    Serial.println("no vibration");
  }
  delay(2000);
}
