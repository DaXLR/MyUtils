#include <MyUtils.h>

/*
Écrit par Fabien Lavoie (c) 2023
Distribution et utilisation permise sous la license CC0 v1.0 Universal
Permet entre autre l'utilisation complète privée ou commerciale, la distribution et la modification
Voir la licence fournie avec cette librairie pour les conditions complètes

Code entreposé sur https://github.com/DaXLR/MyUtils et maintenu par l'auteur.
*/

/*
Cet exemple utilise les trois premières classes de la librairie (timer, polytone et sequencer)
pour jouer une mélodie sur deux 'buzzer' indépendants.

Branchez un buzzer sur la pin 2, et un second buzzer sur la pin 3 pour entrendre la mélodie
*/

int time[] = {110, 20, 110, 20, 110, 20, 390, 390, 390, 130, 160, 100, 500, 10};
int val1[] = {349, 0, 349, 0, 349, 0, 349, 277, 311, 349, 0, 311, 349, 0};
int val2[] = {261, 0, 261, 0, 261, 0, 261, 207, 233, 261, 0, 233, 261, 0};

/*
Chaque objet PolyTone est assigné a une pin lors de la création
*/
PolyTone buzz1 = PolyTone(2);
PolyTone buzz2 = PolyTone(3);

Timer t1 = Timer();

/*
Chaque sequencer a besoin de deux array lors de la création; un array de timings (en millisecondes) et un array de valeurs
L'objet vas maintenir chaque valeur pendant le nombre de millisecondes prescrites, puis passer a la valeur suivante
Ex. dans seq1 la valeur 349 vas etre maintenue pendant 110 ms, puis la valeur 0 pendant 20 ms, etc.
*/
Sequencer seq1 = Sequencer(14, time, val1);
Sequencer seq2 = Sequencer(14, time, val2);

void setup()
{
    Serial.begin(115200);
    t1.start(4000, true); // Démarre l'objet timer avec un temps d'attente de 4 secondes, en mode 'repeating'
    seq1.start(1);        // Démarre le sequencer seq1 avec 1 répétition
    seq2.start(1);        // Même chose pour la deuxième séquence
}
void loop()
{
    if (t1.check()) // Timer.check() vérifier si le temp prescrit est écoulé, et retourne true si c'est le cas
    {
        // Si oui, on démarre les deux séquences, une seule fois
        seq1.start(1);
        seq2.start(1);
    }

    if (seq1.newVal()) // Si une nouvelle valeur est disponible dans la séquence
    {
        buzz1.tone(seq1.check()); // Assigner la valeur dans la séquence a un buzzer
    }

    if (seq2.newVal()) // Même chose pour la séquence 2
    {
        buzz2.tone(seq2.check());
    }

    // Mise a jour des buzzers (PolyTone requiert des calls constants pour faire osciller les pins au bon moment)
    buzz1.update();
    buzz2.update();
}