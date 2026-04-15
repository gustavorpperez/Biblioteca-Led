#include <Arduino.h>
#include "LED.h"

// Cria o objeto LED no pino 13
Led ledVermelho(13);

void setup()
{
    // Inicia o LED piscando a 2 Hz (2 vezes por segundo)
    ledVermelho.piscar(2.0f);
}

void loop()
{
    // Atualiza o estado do LED a cada ciclo do loop
    // Deve ser chamado sempre para o piscar funcionar
    ledVermelho.update();
}
