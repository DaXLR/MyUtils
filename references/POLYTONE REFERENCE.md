# RÉFÉRENCE - POLYTONE

## Fonctions Publiques

### PolyTone(pin)

> Description : Constructeur. Chaque instance est attaché de manière permanente a une pin

> Paramètres :
>
> _pin_ (int): La pin sur laquelle attacher l'objet. Toutes les pins capable de supporter digitalWrite() sont valides

> Retourne : rien

Exemple :

```
PolyTone buzzer = PolyTone();
```

</br>

### PolyTone.tone(freq, duration)

> Description : Initialise l'objet avec une fréquence et une durée initiale (optionelle). Contrairement a la fonction tone() de Arduino, cette fonction ne produit pas d'oscillation par elle-même. On doit appeller la fonction PolyTone.update() aussi souvent que possible pour actuellement faire osciller la pin

> Paramètres :
>
> _freq_ (int): La fréquence d'oscillation de la pin
>
> _duration_ (unsigned long, Defaut 0): La durée de l'oscillation en ms. 0 équivaut a une oscillation infinie (valeur par défaut)

> Retourne : rien

> Exemple :

```
buzzer.tone(440, 1000); //Prépare un tone de 440Hz, durée de 1 seconde

while (!buzzer.isAvailable())
{
    buzzer.update() //Fait jouer le son tant que le tone est actif
}
```

</br>

### PolyTone.noTone()

> Description : Arrète toute oscillation et réinitialise les variables utilisées par la classe

> Paramètres : aucuns

> Retourne : rien

> Exemple :

```
buzzer.noTone();
```

</br>

### PolyTone.update()

> Description : Met a jour l'état de la pin afin de produire l'oscillation. Doit être appellé le plus souvent possible pour produire un son consistent et avec la bonne fréquence

> Paramètres : aucuns

> Retourne : rien

> Exemple :

```
void setup()
{
    buzzer.tone(440); //Prépare un tone de 440Hz
}

void loop()
{
    buzzer.update() //Fait jouer le son
}
```

</br>

### PolyTone.isAvailable()

> Description : Vérifie si l'instance est inactive (disponible pour jouer un son)

> Paramètres : aucuns

> Retourne : **false** si l'instance est programmée pour produire une oscillation, **true** si elle est disponible/inactive

> Exemple :

```
buzzer.tone(440, 1000); //Prépare un tone de 440Hz, durée de 1 seconde

while (!buzzer.isAvailable()) //Si le tone est actif (pas disponible)
{
    buzzer.update() //Fait jouer le son
}
```
