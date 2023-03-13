#include "Arduino.h"
#include "MyUtils.h"

// https://stackoverflow.com/questions/37074763/arduino-class-array-member

Sequencer::Sequencer(int size)
{
    _size = size;
}
Sequencer::Sequencer(int size, int initialTiming[], int initialValues[])
{
    _size = size;
    _timing = initialTiming;
    _values = initialValues;
}

void Sequencer::load(int timing[], int values[])
{
    _timing = timing;
    _values = values;
}

void Sequencer::printDebug()
{
    Serial.print("La sequence contient ");
    Serial.print(_size, DEC);
    Serial.println(" elements:");

    for (int i = 0; i < _size; i++)
    {
        Serial.print(i + 1, DEC);
        Serial.print(" - time: ");
        Serial.print(_timing[i]);
        Serial.print(", val: ");
        Serial.print(_values[i]);
        Serial.println("");
    }
}

void Sequencer::start(int loops)
{
    _loops = loops;
    _sequencePosition = 0;
    _prevSeqPos = -1;
    _flagpole = millis();
    _interval = _timing[0];
    _isRunning = true;
}

/*
Retourne la valeur de l'etape en cours dans la sequence ou -1 si la Sequence n'est pas en cours
Doit etre appelle souvent pour assurer que le flagpole est a jour
*/
int Sequencer::check()
{

    if (_isRunning)
    {
        if (millis() >= _flagpole + _interval)
        {
            _flagpole = _flagpole + _interval;

            if (_sequencePosition < _size - 1)
            {
                _sequencePosition += 1;
            }
            else // Si la fin de la sequence est atteinte
            {
                _sequencePosition = 0;

                if (_loops == 1)
                {
                    stop();
                }
                else if (_loops != 0)
                {
                    _loops -= 1;
                }
            }
            _interval = _timing[_sequencePosition];
        }
        return _values[_sequencePosition];
    }
    else
    {
        return -1;
    }
}

/*
Retourne true si une nouvelle valeur est disponible depuis la derniere fois que newVal() a ete appellee
Initie egalement un check()
*/
bool Sequencer::newVal()
{
    check();
    if (_sequencePosition != _prevSeqPos)
    {
        _prevSeqPos = _sequencePosition;
        return true;
    }
    else
    {
        return false;
    }
}

void Sequencer::stop()
{
    _loops = 0;
    _sequencePosition = 0;
    _prevSeqPos = 0;
    _flagpole = 0;
    _interval = 0;
    _isRunning = false;
}
