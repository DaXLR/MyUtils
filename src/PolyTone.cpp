#include "Arduino.h"
#include "MyUtils.h"

PolyTone::PolyTone(int pin)
{
    _pin = pin;
    _waveOffset = 0;
    pinMode(_pin, OUTPUT);
    digitalWrite(_pin, LOW);
}

/*
Prepare la pin a osciller. Depend de la fonction update() pour actuellement produire du son.
La duration de 0 par defaut signifie dure indetermine, autrement la fonction appelle noTone() par elle-meme
*/
void PolyTone::tone(int freq, unsigned long duration)
{

    if (freq != 0)
    {
        _freq = freq;
        _waveOffset = round(500000 / _freq);
        _prevWave = micros();
        if (duration > 0)
        {
            _stopTime = millis() + duration;
            _timedBuzz = true;
        }
        else
        {
            _timedBuzz = false;
        }
    }
    else
    {
        _waveOffset = 0;
        //_waveOffset sert aussi comme indicateur a savoir si la pin est prete ou non
    }
}

/*
Arrete le tone et reinitialise tous les parametres
*/
void PolyTone::noTone()
{
    _waveOffset = 0;
    _freq = 0;
    _stopTime = 0;
    _timedBuzz = false;
    digitalWrite(_pin, LOW);
}

/*
Met a jour l'etat de la pin. Doit etre appelle ausi souvent que possible
*/
void PolyTone::update()
{
    if (_waveOffset != 0)
    {
        if (_timedBuzz)
        {
            if (millis() >= _stopTime)
            {
                noTone();
            }
        }

        if (micros() >= (_prevWave + _waveOffset))
        {
            _pinState = !_pinState;
            digitalWrite(_pin, _pinState);
            _prevWave = micros();
        }
    }
}

/*
Retourne true si la pin est presentement dormante
*/
bool PolyTone::isAvailable()
{
    if (_waveOffset == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}