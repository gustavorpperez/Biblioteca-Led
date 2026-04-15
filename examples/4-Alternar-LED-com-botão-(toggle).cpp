/* 
Autor: Gustavo Rodrigues Padovan Perez
Programa: Altenar LED com botão (toggle)
Descrição: Programa da biblioteca do LED.h que altera o estado do led quando o botão é pressionado
data: 15/04/2026
versão: 1.0 
*/

#include <Arduino.h>
#include "LED.h"

const uint8_t BOTAO = 0;

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