/* 
Autor: Gustavo Rodrigues Padovan Perez
Programa: Ligar por tempo ao pressionar botão.
Descrição: Programa da biblioteca do LED.h que faz o led ligar por um curto periodo de tempo ao pressionar um botão.
data: 15/04/2026
versão: 1.0 
*/


#include <Arduino.h>
#include "LED.h"

const uint8_t BOTAO = 0;

Led ledAmarelo(5);

void setup()
{
    pinMode(BOTAO, INPUT_PULLUP);
}

void loop()
{
    // Ao pressionar o botão, liga o LED por 3 segundos
    // O desligamento é automático, sem bloquear o loop
    if (!digitalRead(BOTAO))
        ledAmarelo.ligar(3000);

    ledAmarelo.update();
}