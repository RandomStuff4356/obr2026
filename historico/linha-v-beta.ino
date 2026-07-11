#include <Arduino.h>
#include <math.h>

//Tamanho dos arrays de leitura e sensores, ou seja, o n° de sensores de luminosidade utilizados
const int length = 5;

int sensores[length] = {4, 2, 13, 35, 33};
int leituras[length];

//Leitura mínima para a leitura ser branca, ou seja, qualquer número acima de corte será branco
int corte = 1000;

//Variável que armazena a próxima ação a ser tomada pelo robô
proxAcao = "";

void setup() {
  Serial.begin(9600);
  for(int i = 0; i < length; i++)
  {
    pinMode(sensores[i], INPUT);
  }
  Serial.println("debug");
}

void loop() 
{
  lerSensores();
  printValores();
  proxAcao = lerLinha();
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

String lerLinha()
{
    //Cria uma única variável para checar a leitura e determinar a próxima ação do robô
    String leitura = "";
    for(int i = 0; i < length; i++)
    {
        leitura.append(String(leituras[i]));
    }

    if(leitura == "00010" || leitura == "00001" || leitura == "00011")
    {
        return "curvaDireita";
    }
    else if(leitura == "01000" || leitura == "10000" || leitura == "11000")
    {
        return "curvaEsquerda";
    }
    else if(leitura == "11100" || leitura == "01100")
    {
        return "curva90Esquerda";
    }
    else if(leitura == "00111" || leitura == "00110")
    {
        return "curva90Direita";
    }
    else return "reta";
}