#include <Arduino.h>
#include "LED.h"

const uint8_t BOTAO = 4;

Led ledVerde(7);
bool ultimoEstado = true; // HIGH = botão solto (INPUT_PULLUP)

void setup()
{
    pinMode(BOTAO, INPUT_PULLUP);
}

void loop()
{
    bool estadoAtual = digitalRead(BOTAO);

    // Detecta apenas o momento em que o botão é pressionado
    if (!estadoAtual && ultimoEstado)
        ledVerde.alternar();

    ultimoEstado = estadoAtual;

    ledVerde.update();
}