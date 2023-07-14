
void setup() {
pinMode(6,OUTPUT);
}

void loop() {
tone(6,200);
delay(2500);
noTone(6);
 delay(2500);
}
