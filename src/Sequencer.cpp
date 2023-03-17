#include "Arduino.h"
#include "MyUtils.h"

/*
Écrit par Fabien Lavoie (c) 2023
Distribution et utilisation permise sous la license CC0 v1.0 Universal
Permet entre autre l'utilisation complète privée ou commerciale, la distribution et la modification
Voir la licence fournie avec cette librairie pour les conditions complètes

Code entreposé sur https://github.com/DaXLR/MyUtils et maintenu par l'auteur.

Références; https://stackoverflow.com/questions/37074763/arduino-class-array-member
*/

/*
Constructeur sans array. La taille de la séquence doit etre pré-définie et ne peut pas changer une fois que l'objet a été créé
Si l'objet est construit dans array, la fonction Sequencer.load() doit être utilisée pour charger une séquence
*/
Sequencer::Sequencer(int size)
{
    _size = size;
}

/*
Constructeur avec array. La taille de la séquence doit etre pré-définie et ne peut pas changer une fois que l'objet a été créé
*/
Sequencer::Sequencer(int size, int initialTiming[], int initialValues[])
{
    _size = size;
    _timing = initialTiming;
    _values = initialValues;
}

/*
Charge les timings et valeurs dans un objet Sequencer. Peut-être utilisée at runtime pour modifier une séquence
*/
void Sequencer::load(int timing[], int values[])
{
    _timing = timing;
    _values = values;
}

/*
Print en langage naturel des informations sur la séquence présentement chargée.
*/
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
    Serial.print("La sequence est ");
    if (_isRunning)
    {
        Serial.println("ACTIVE");
    }
    else
    {
        Serial.println("INACTIVE");
    }
    Serial.print("Position actuelle: ");
    Serial.println(_sequencePosition, DEC);
    Serial.print("Valeur: ");
    Serial.println(_values[_sequencePosition], DEC);
    Serial.print("Nonmbre de repetitions restantes (0 = infini): ");
    Serial.println(_loops, DEC);
}

/*
Démarre la séquence en spécifiant le nombre de répétitions (défaut = 0 = infini)
*/
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
Retourne la valeur de l'etape en cours dans la sequence ou -1 si la sequence n'est pas en cours
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
Retourne true si une nouvelle valeur est disponible depuis la derniere fois que newVal() a ete appellée
Initie également un check()
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

/*
Arrète la séquence en cours et réinitialise toutes les variables
*/
void Sequencer::stop()
{
    _loops = 0;
    _sequencePosition = 0;
    _prevSeqPos = 0;
    _flagpole = 0;
    _interval = 0;
    _isRunning = false;
}
