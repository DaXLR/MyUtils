#include "Arduino.h"
#include "MyUtils.h"

/*
Écrit par Fabien Lavoie (c) 2023
Distribution et utilisation permise sous la license CC0 v1.0 Universal
Permet entre autre l'utilisation complète privée ou commerciale, la distribution et la modification
Voir la licence fournie avec cette librairie pour les conditions complètes

Code entreposé sur https://github.com/DaXLR/MyUtils et maintenu par l'auteur.
*/

/*
Contructeur. La pin est fixe pour chaque objet.
*/
PolyTone::PolyTone(int pin)
{
    _pin = pin;
    _waveOffset = 0;
    pinMode(_pin, OUTPUT);
    digitalWrite(_pin, LOW);
}

/*
Prescrit la fréquence d'oscillation. Depend de la fonction update() pour actuellement changer l'état de la pin
La duration est en milliseconde. 0 par defaut signifie durée indeterminée.
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
Met a jour l'etat de la pin. Doit etre appellé aussi souvent que possible
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
Retourne true si la pin est présentement dormante
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