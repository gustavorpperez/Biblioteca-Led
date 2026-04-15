#include <Arduino.h>
#include "LED.h"

Led ledVermelho(11);
Led ledVerde(12);
Led ledAzul(13);

void setup()
{
    ledVermelho.piscar(1.0f);  // Pisca devagar: 1 Hz
    ledVerde.piscar(4.0f);    // Pisca rápido: 4 Hz
    ledAzul.ligar(5000);      // Fica ligado por 5 s e apaga
}

void loop()
{
    // Cada LED é atualizado de forma independente
    // Nenhum bloqueia o outro
    ledVermelho.update();
    ledVerde.update();
    ledAzul.update();
}