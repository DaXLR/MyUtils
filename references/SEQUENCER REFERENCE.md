# RÉFÉRENCE - SEQUENCER

## Fonctions Publiques

### Sequencer(size, timing(optional), values(optional))

> Description : Constructeur. La grandeur de la séquence doit être déclaré lors de l'instantiation et ne peut pas être modifié par la suite. Les paramètres de valeurs et timings peuvent être omises lors de l'instantiation et changées plus tard avec Sequencer.load();

> Paramètres :
>
> _size_ (int) : Nombre d'éléments dans la séquence
>
> _timing_ (int[n], optionel) : Array contenant les timings pour la séquence, en ms. Si vous instantiez l'objet avec les timings, vous devez également fournir les values.
>
> _values_ (int[n], optionel) : Array contenant les valeurs pour la séquence.

> Retourne : rien

Exemple :

```
Sequencer seq = Sequencer(10) //Initialise une séquence de 10 items, sans les valeurs
```

```
int timing[] = {100,200,100};
int values[] = {10, 20, 30};

Sequencer seq = Sequencer(3, timing, values) //Initialise une séquence de 3 items, incluant les timings et valeurs
```

</br>

### Sequencer.load(timing, values)

> Description : Charge des timings et valeurs dans le
> Sequencer

> Paramètres :
>
> _timing_ (int[n]) : Array contenant les timings pour la séquence, en ms.
>
> _values_ (int[n]) : Array contenant les valeurs pour la séquence.

> Retourne : rien

> Exemple :

```
int timing[] = {100,200,100};
int values[] = {10, 20, 30};

Sequencer seq = Sequencer(3) //Initialise un Sequencer de taille 3, sans les valeurs

void setup()
{
    seq.load(timing, values) //Charge les timings et valeurs dans la séquence
}
```

</br>

### Sequencer.printDebug()

> Description : Print des informations sur la séquence en cours

> Paramètres : aucuns

> Retourne : rien

> Exemple :

```
seq.printDebug();
```

</br>

### Sequencer.start(loops)

> Description : Démarre la séquence pour un certain nombre de répétitions

> Paramètres :
>
> _loops_ (int, defaut 0) : Nombre de répétitions a effectuer. Le defaut de 0 signifie répétition à l'infini

> Retourne :

> Exemple :

```
seq.start(5) //Démarre la séquence pour 5 répétitions
```

</br>

### Sequencer.check()

> Description : Met a jour la séquence et retourne la valeur correspondante a l'emplacement dans la séquence. Doit être appellé le plus souvent possible pour s'assurer que la séquence soit mise à jour correctement

> Paramètres : aucuns

> Retourne : la valeur correspondante dans la séquence en cours

> Exemple :

```
Serial.println(seq.check()); //Imprime la valeur en cours
```

</br>

### Sequencer.newVal()

> Description : Vérifie si une nouvelle valeur est disponible depuis la dernière fois que Sequencer.newVal() à retournée **true**. Appelle également Sequencer.check()

> Paramètres : aucuns

> Retourne : **true** si la séquence est à une nouvelle position.
>
> Note: Dès que cette fonction retourne **true** elle est immédiatement mise a jour. Par conséquent, même si rien n'est fait avec le retour, la fonction ne retournera plus **true** tant que la séquence n'atteint pas une nouvelle position. De plus, cette fonction est affecté par la position dans la séquence et non la valeur dans l'array, par conséquent elle peut retourner **true** même si deux valeurs subséquentes dans l'array sont identiques.

> Exemple :

```
 if (seq.newVal()) // Si une nouvelle valeur est disponible dans la séquence
    {
        Serial.println(seq.check()); //Imprime la valeur dans le moniteur serial
    }
```

</br>

### Sequencer.stop()

> Description : Interromp une séquence et réinitialise les variables de contrôle (sans modifier les timings et valeurs)

> Paramètres : aucuns

> Retourne : rien

> Exemple :

```
seq.stop();
```
