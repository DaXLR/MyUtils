#include "Arduino.h"
#include "MyUtils.h"

Timer::Timer()
{
}

/*
Initialise le Timer en mode millis()
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
Initialise le Timer en mode micros()
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
Verifie si l
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

void Timer::stop()
{
    _interval = 0;
    _flagpole = 0;
    _isRunning = false;
}
