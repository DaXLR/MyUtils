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
Constructeur sans array. La taille de la séquence doit etre pré-définie et ne peut pas changer une fois que l'objet a été créé
Si l'objet est construit sans array, la fonction Picker.load() doit être utilisée pour charger des valeurs et/ou poids
*/
Picker::Picker(int size)
{
    _size = size;
}

/*
Constructeur avec array. La taille de la séquence doit etre pré-définie et ne peut pas changer une fois que l'objet a été créé
*/
Picker::Picker(int size, int weights[])
{
    _size = size;
    _weights = weights;

    _customWeights = true;

    _totalWeight = 0;

    for (int i = 0; i < _size; i++)
    {
        _totalWeight += _weights[i];
    }

    for (int i = 0; i < _size; i++)
    {
        if (i > 0)
        {
            _weights[i] += _weights[i - 1];
        }
    }
}

/*
Constructeur avec array. La taille de la séquence doit etre pré-définie et ne peut pas changer une fois que l'objet a été créé
*/
Picker::Picker(int size, int values[], int weights[])
{
    _size = size;
    _weights = weights;
    _values = values;

    _customWeights = true;
    _customValues = true;

    _totalWeight = 0;

    for (int i = 0; i < _size; i++)
    {
        _totalWeight += _weights[i];
    }

    for (int i = 0; i < _size; i++)
    {
        if (i > 0)
        {
            _weights[i] += _weights[i - 1];
        }
    }
}

/*
Charge les poids dans un objet Picker. Peut-être modifié at runtinme
*/
void Picker::load(int weights[])
{
    _weights = weights;

    _totalWeight = 0;

    _customWeights = true;

    for (int i = 0; i < _size; i++)
    {
        _totalWeight += _weights[i];
    }

    for (int i = 0; i < _size; i++)
    {
        if (i > 0)
        {
            _weights[i] += _weights[i - 1];
        }
    }
}

/*
Charge les poids et valeurs dans un objet Picker. Peut-être modifié at runtinme
*/
void Picker::load(int values[], int weights[])
{
    _values = values;
    _weights = weights;

    _totalWeight = 0;

    _customWeights = true;
    _customValues = true;

    for (int i = 0; i < _size; i++)
    {
        _totalWeight += _weights[i];
    }

    for (int i = 0; i < _size; i++)
    {
        if (i > 0)
        {
            _weights[i] += _weights[i - 1];
        }
    }
}

int Picker::pickWeights()
{

    if (_customWeights)
    {
        int _randVal = random(0, _totalWeight);

        for (int i = 0; i < _size; i++)
        {
            int _lowerBound = 0;

            if (i != 0)
            {
                _lowerBound = _weights[i - 1];
            }

            if (_randVal < _weights[i] && _randVal >= _lowerBound)
            {
                if (_customValues)
                {
                    return _values[i];
                }
                else
                {
                    return i;
                }
            }
        }
    }

    // Erreur
    return -666;
}

int Picker::pickEqual()
{
}
