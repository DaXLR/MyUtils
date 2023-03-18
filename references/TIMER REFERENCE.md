# RÉFÉRENCE - TIMER

## Variables

### Timer.flag

> Description : Variable générique pour assigner une valeur arbitraire a un timer. N'affecte aucunement le minutage et n'est pas utilisé a l'interne par la classe

> Type : int

Exemple :

```
if (timerName.check())
{
    if (timerName.flag == 1)
    {
        //Faire quelquechose
    }
    if (timerName.flag == 2)
    {
        //Faire quelquechose de different
    }
}
```

```
if (timerName.check())
{
    timerName.flag += 1; //Incrémente le flag chaque fois que le timer fait une répétition
}
```

## Fonctions Publiques

### Timer()

> Description : Constructeur

> Paramètres : aucuns

> Retourne : rien

Exemple :

```
Timer timerName = Timer();
```

</br>

### Timer.start(interval, repeating)

> Description : Initialise le Timer

> Paramètres :
>
> _interval_ (unsigned long): Le nombre de ms entre chaque répétitions
>
> _repeating_ (boolean, Defaut **true**) : Le timer vas répéter à l'infini si **true**, autrement le timer s'arrète par lui-même la première fois que Timer.check() retourne true

> Retourne : rien

> Exemple :

```
timerName.start(1000, true) //Initialise un timer récurrent de 1000ms
```

</br>

### Timer.startMicro(interval, repeating)

> Description : Même chose que Timer.start(), mais avec intervalles en microsecondes

> Paramètres :
>
> _interval_ (unsigned long): Le nombre de us entre chaque répétitions
>
> _repeating_ (boolean, Defaut = **true**): Le timer vas répéter à l'infini si **true**, autrement le timer s'arrète par lui-même la première fois que Timer.check() retourne true

> Retourne : rien

Exemple :

```
timerName.startMicros(25, true) //Initialise un timer récurrent de 25us
```

</br>

### Timer.check()

> Description : Vérifie si l'interval du timer s'est écoulé. Met a jour le timer et le réinitialise automatiquement si le mode est repeating

> Paramètres : aucuns

> Retourne : **true** si le timer est écoulé

Exemple :

```
if (timerName.check())
{
Serial.println("Done!");
}
```

</br>

### Timer.stop()

> Description : Arrète le timer et réinitialise toutes les variables utilisés

> Paramètres : aucuns

> Retourne : rien

Exemple :

```
timerName.stop();
```
