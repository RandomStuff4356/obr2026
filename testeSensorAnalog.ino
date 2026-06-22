#define sensor 4
#define led 2

void setup()
{
    pinMode(sensor, INPUT);
    pinMode(led, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
  if(digitalRead(sensor) == LOW)
  {digitalWrite(led, HIGH);}
  else
  {digitalWrite(led, LOW);}
}
