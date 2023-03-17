#include <MyUtils.h>

/*
Écrit par Fabien Lavoie (c) 2023
Distribution et utilisation permise sous la license CC0 v1.0 Universal
Permet entre autre l'utilisation complète privée ou commerciale, la distribution et la modification
Voir la licence fournie avec cette librairie pour les conditions complètes

Code entreposé sur https://github.com/DaXLR/MyUtils et maintenu par l'auteur.
*/

/*
Exemple de l'utilisation de l'objet Timer
*/

// Création des objets
Timer t1 = Timer();
Timer t2 = Timer();
Timer t3 = Timer();
Timer t4 = Timer();

void setup()
{
    Serial.begin(9600);    // Initialisation de la console série
    t1.start(1000, true);  // Démarrage du Timer t1, en mode 'repeating'
    t2.start(1500, true);  // Démarrage de t2
    t3.start(5000, false); // Démaragge de t3, en mode 'one-shot'
}

void loop()
{
    if (t2.check()) // Vérifie si le timer t2 est écoulé
    {
        Serial.println("Cette action se produit a toutes les 1500ms (1.5s)");
    }

    /*
    Chaque Timer à une variable interne 'flag' qui peut être lue ou modifiée.
    Peut servir par exemple a compter le nombre de répétitions d'un timer
    et modifier le code après un certain nombre de répétitions
    */
    if (t1.flag <= 6) // Si le flag de t1 est de 6 ou moins
    {

        if (t1.check())
        {
            Serial.println("Cette action se produit a toutes les 1000ms (1s)");
            t1.flag += 1; // On augmente le flag
        }
    }
    else if (t1.flag == 7) // Une fois le flag == a 7
    {
        Serial.println("t1 as repete assez souvent, on demarra t4");
        t1.stop();                   // On arrète t1
        t1.flag += 1;                // On incrémente flag une dernière fois
        t4.startMicro(250000, true); // Et on démarre t4
    }
    else
    {
        // Ne plus rien faire
    }

    if (t3.check())
    {
        Serial.println("Apres 5 secondes, ce timer arrete par lui-meme");
    }

    if (t4.check())
    {
        Serial.println("Cette action se produit a toutes les 250,000 MICROsecondes (250 ms)");
    }
}
