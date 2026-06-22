#define sensor 4
#define led 2
//Máx = 4095
const int corte = 2047;
int leitura;

void setup()
{
    pinMode(sensor, INPUT);
    pinMode(led, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
  leitura = analogRead(sensor);
  Serial.println(leitura);
  if(leitura < corte)
  {digitalWrite(led, HIGH);}
  else
  {digitalWrite(led, LOW);}
}
