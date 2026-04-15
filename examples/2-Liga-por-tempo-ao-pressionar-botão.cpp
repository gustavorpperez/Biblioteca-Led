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