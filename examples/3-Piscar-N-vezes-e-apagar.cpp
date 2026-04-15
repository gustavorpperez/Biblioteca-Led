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