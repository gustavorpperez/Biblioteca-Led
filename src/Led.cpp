#include "LED.h"

Led::Led(uint8_t pin) :
                        pino(pin),
                        estado(LOW),
                        desligarPorTempo(false),
                        desligarNoMomento(0),
                        tempoAnteriorPiscar(0),
                        estadoPiscar(false),
                        repeticoes(0)
{
    pinMode(pino, OUTPUT);
}

void Led::ligar()
{
    estadoPiscar = false; // Reseta os valores
    desligarPorTempo = false;

    estado = HIGH;
}

void Led::ligar(uint32_t tempoLigado_ms)
{
    estadoPiscar = false; // Reseta os valores
    estado = HIGH;
    desligarPorTempo = true;
    desligarNoMomento = millis() + tempoLigado_ms;
}

void Led::desligar()
{
    estadoPiscar = false; // Reseta os valores
    desligarPorTempo = false;

    estado = LOW;
}

void Led::alternar()
{
    estado = !estado;
}

void Led::update()
{

    if (desligarPorTempo)
        funcaoDesligamento();

    if (estadoPiscar)
        funcaoPiscar();

    digitalWrite(pino, estado);
}

bool Led::getEstado()
{
    estadoPiscar = false; // Reseta os valores
    desligarPorTempo = false;
    return estado;
}

uint8_t Led::getPino()
{
    return pino;
}

void Led::setEstado(bool estado)
{
    this->estado = estado;
    desligarPorTempo = false;
    estadoPiscar = false;
}

void Led::piscar()
{
    estadoPiscar = true;
    tempoEspera = 500;
    tempoAnteriorPiscar = millis();
    estado = HIGH;
    desligarPorTempo = false;
}

void Led::piscar(float frequencia)
{
    estadoPiscar = true;
    tempoEspera = (1000.0f / (2.0f * frequencia));
    tempoAnteriorPiscar = millis();
    estado = HIGH;
    desligarPorTempo = false;
}

void Led::piscar(uint8_t frequencia, float repeticoes)
{
    estadoPiscar = true;
    tempoEspera = (1000.0f / (2.0f * frequencia));
    tempoAnteriorPiscar = millis();
    estado = HIGH;
    this->repeticoes = repeticoes * 2;
}

void Led::funcaoPiscar()
{
    if (millis() - tempoAnteriorPiscar >= tempoEspera)
    {
        estado = !estado;
        tempoAnteriorPiscar = millis();
        if (repeticoes > 0)
        {
            repeticoes--;
            if (repeticoes == 0)
            {
                estadoPiscar = false;
                estado = LOW;
            }
        }
    }
}

void Led::funcaoDesligamento()
{
    if (millis() >= desligarNoMomento)
    {
        estado = LOW;
        desligarPorTempo = false;
    }
}