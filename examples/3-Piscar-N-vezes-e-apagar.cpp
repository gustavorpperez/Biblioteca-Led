/* 
Autor: Gustavo Rodrigues Padovan Perez
Programa: Piscar N vezes e apagar.
Descrição: Programa da biblioteca do LED.h que faz o led selecionado piscar uma certa quantidade de vezes com uma certa velocidade e depois apaga.
data: 15/04/2026
versão: 1.0 
*/


#include <Arduino.h>
#include "LED.h"

Led ledAzul(6);

void setup()
{
    // Pisca 5 vezes a 3 Hz e apaga automaticamente
    ledAzul.piscar(3, 5);
}

void loop()
{
    // update() controla a contagem e apaga ao terminar
    ledAzul.update();
}   