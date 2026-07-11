#include <Arduino.h>
#include <math.h>

//Tamanho dos arrays de leitura e sensores, ou seja, o n° de sensores de luminosidade utilizados
const int length = 5;

int sensores[length] = {4, 2, 13, 35, 33};
int leituras[length];
int debugLeds[length] = {32, 23, 22, 19, 27};

//Leitura mínima para a leitura ser branca, ou seja, qualquer número acima de corte será branco
int corte = 1000;

void setup() {
  Serial.begin(9600);
  for(int i = 0; i < length; i++)
  {
    pinMode(sensores[i], INPUT);
    pinMode(debugLeds[i], OUTPUT);
  }
  Serial.println("debug");
}

void loop() 
{
  lerSensores();
  printValores();
  debug();
}

void lerSensores()
{
  for(int i = 0; i < length; i++)
  {
    leituras[i] = analogRead(sensores[i]);
  }
}

void printValores()
{

  for(int i = 0; i < length; i++)
  {
    Serial.print("Sensor " + String(i) + ": " + String(leituras[i]));
  }
  Serial.println();
}

void debug()
{
  for(int i = 0; i < length; i++)
  {
    if(leituras[i] > corte)
    {
      digitalWrite(debugLeds[i], HIGH);
    }
    else
    {
      digitalWrite(debugLeds[i], LOW);
    }
  }
}