# MyUtils

## CONTEXTE:

Les buts de cette librairie sont, en ordre d'importance;

1. Pratiquer mes compétences en programmation Arduino et C++
2. Regrouper dans une seule librairie une collection de classes que je trouve utile dans mes projets
3. Rendre le code acessible pour les personnes en aprentissage

Il y a plusieurs fonctions et structures dans Arduino qui se retrouvent un jour ou l'autre dans la pluspart des sketchs. Certaines de ces structures peuvent être difficiles à cerner pour les néophytes et ennuyantes a programmer pour les experts. Mon but avec les classes dans cette librairie est de simplifier mon propre travail tout en fournissant de la documentation aidant l'aprentissage des personnes qui se lancent sérieusement dans la programmation Arduino

Le but premier étant mon propre perfectionnement (et malgré le fait que toutes ces fontions existent probablement ailleur sur le web) le code dans cette librairie est entièrement le mien. Je ne ferais pas d'effort significatif pour garder les fonctions consistantes ou ajouter des éléments indéfiniment. Ce n'est pas destiné a être une librairie de production mais bien d'aprentissage

Je ne suis pas un expert non plus, et le code est fournis sans aucunes garanties. Cela-dit je serait très content de vous aider si vous avez des questions avec mon code ou vos projets Arduino. N'hésitez pas a me contacter au fabien.lavoie@outlook.com, ou si vous êtes membres, via le serveur Discord d'Ubchihica [LINK REDACTED]

## INSTALLATION:

Téléchargez la release voulue et placez le dossier parent ''MyUtils'' dans votre dossier de librairies d'Arduino.

Comme la paritée des fonctions entre les versions n'est pas garantie, si vous prévoyez utiliser la librairie dans une production finale je recommande de faire une copie locale et de renommer la librairie avec un nom unique. Vous devez renommer les items suivants avec le même nom;

- Le nom du dossier contenant la librairie
- Le nom du fichier header MyUtils.h
- La déclaration _#include "MyUtils.h"_ présente dans chacun des fichiers \*.cpp
- La déclaration _#include "MyUtils.h"_ dans votre sketch

# Description Sommaire des Classes (Release 0.1)

## Timer

Simple objet permettant de faire des actions périodiques sans bloquer le code avec Delay. Abstraction du concept décris dans le tutoriel [BlinkWithoutDelay](https://docs.arduino.cc/built-in-examples/digital/BlinkWithoutDelay)

## PolyTone

Version software de la fonction 'tone()' d'Arduino, permettant la polyphonie. tone() utilise normalement un compteur hardware et est limité a une seule fréquence a la fois

## Sequencer

Objet permettant de passer automatiquement à travers une séquence de valeurs selon un timing pré-définis. Utile pour faire des mélodies, animations de servomoteurs, séquence de LEDs etc. sans avoir a bloquer le code avec Delay ou utiliser plusieurs timers différents
