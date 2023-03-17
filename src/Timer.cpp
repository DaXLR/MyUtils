#include "Arduino.h"
#include "MyUtils.h"

/*
Écrit par Fabien Lavoie (c) 2023
Distribution et utilisation permise sous la license CC0 v1.0 Universal
Permet entre autre l'utilisation complète privée ou commerciale, la distribution et la modification
Voir la licence fournie avec cette librairie pour les conditions complètes

Code entreposé sur https://github.com/DaXLR/MyUtils et maintenu par l'auteur.
*/

Timer::Timer()
{
}

/*
Initialise le Timer en mode millisecondes
Le timer est repeating (reset automatiquement) par defaut
*/
void Timer::start(unsigned long interval, bool repeating)
{
    _interval = interval;
    _repeating = repeating;
    _flagpole = millis();
    _isMicros = false;
    _isRunning = true;
}
/*
Initialise le Timer en mode microsecondes
*/
void Timer::startMicro(unsigned long interval, bool repeating)
{
    _interval = interval;
    _repeating = repeating;
    _flagpole = micros();
    _isMicros = true;
    _isRunning = true;
}
/*
Retourner true si le timer à dépassé la durée prescrite
*/
bool Timer::check()
{
    if (_isRunning)
    {
        if (_isMicros)
        {
            return _checkMicros();
        }

        if (millis() >= _flagpole + _interval)
        {
            if (_repeating)
            {
                _flagpole = millis();
            }
            else
            {
                stop();
            }
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool Timer::_checkMicros()
{
    if (micros() >= _flagpole + _interval)
    {
        if (_repeating)
        {
            _flagpole = micros();
        }
        else
        {
            stop();
        }
        return true;
    }
    else
    {
        return false;
    }
}

/*
Arrête le timer
*/
void Timer::stop()
{
    _interval = 0;
    _flagpole = 0;
    _isRunning = false;
}

/*
Retourne true si le timer est présentement actif
*/
bool Timer::isRunning()
{
    return _isRunning;
}
