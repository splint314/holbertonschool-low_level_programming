# Green Efficiency Analysis

## Measurement Methodology

Pour ce projet nous devions mesurer le temps d’exécution de plusieurs programmes faits en C et d’analyser ce que ces résultats signifient en efficacité. 
Pour effectuer les mesures j’ai utilisé la fonction `clock()` fournie par la bibliothèque standard `<time.h>`. 
Cette fonction permet de récupérer les timings du CPU utilisé par le programme. 
La valeur retournée a ensuite été convertie en secondes en la divisant par la constante `CLOCKS_PER_SEC`.

Tous les programmes ont été compilés avec les flags demandés afin d’assurer une compilation cohérente et d’éviter les avertissements du compilateur. 
Après la compilation chaque programme a été exécuté 3 fois sauf le dernier (instrumentation_lab.c). 
Et les résultats affichés dans le terminal ont été enregistrés.

Dans baseline_loop, le programme exécute une boucle contenant 100 000 000 d’itérations. 
Les temps mesurés étaient: 

0.065431 secondes 
0.065570 secondes
0.065919 secondes

Les valeurs sont très proches les unes des autres, ce qui montre que les mesures sont relativement stables. 
Malgré de petites variations possibles dues au système.

Dans comparison_algorithms, deux implémentations ont été testées. L’algorithme naïf a produit les temps suivants: 

0.563538 secondes 
0.557966 secondes
0.552240 secondes

L’algorithme optimisé en une seule passe a produit des temps beaucoup plus faibles 

0.000023 secondes 
0.000022 secondes 
0.000023 secondes 

Après calcul de la moyenne, l’algorithme naïf prend environ 0.557915 secondes alors que l’algorithme en une seule passe prend environ 0.000022667 secondes.

## Observed Performance Differences

La différence de performance entre les deux algorithmes est très importante. L’algorithme naïf met un peu plus d’une demi-seconde pour terminer, 
alors que l’algorithme optimisé termine en quelques microsecondes seulement.

En comparant les temps moyens, l’algorithme naïf est environ 24 600 fois plus lent que l’algorithme en une seule passe. 
Cela montre clairement que la manière dont un algorithme est conçu peut avoir un impact énorme sur les performances.

La raison principale de cette différence vient du nombre d’opérations effectuées. 
L’algorithme naïf répète de nombreux calculs sur les données, ce qui augmente fortement le nombre total d’instructions exécutées par le processeur. 
À l’inverse, l’algorithme en une seule passe parcourt les données une seule fois et calcule le résultat au fur et à mesure.

L’expérience du baseline loop montre aussi l’impact de la répétition. 
Même si l’opération dans la boucle est simple, la répéter 100 millions de fois demande tout de même environ 0.065 seconde.

## Relation Between Runtime and Energy Consumption

Dans ce projet, la consommation d’énergie n’a pas été mesurée directement. 
Cependant, le temps d’exécution peut servir d’indicateur approximatif. 
En général, plus un programme s’exécute longtemps, plus le processeur reste actif et plus il consomme d’énergie.

La comparaison entre les deux algorithmes illustre bien ce principe. 
Si un programme met environ 24 600 fois plus de temps à effectuer la même tâche, le processeur restera actif beaucoup plus longtemps.

À grande échelle, par exemple dans des serveurs ou des applications qui traitent de grandes quantités de données, ce type d’inefficacité peut 
entraîner une consommation d’énergie beaucoup plus importante. 
Optimiser les algorithmes peut donc avoir un impact non seulement sur les performances mais aussi sur l’efficacité énergétique.

## Limitations of the Experiment

Cette expérience présente plusieurs limites. Tout d’abord, les mesures ont été réalisées avec `clock()`, qui mesure le temps CPU et non la consommation d’énergie réelle. 
Les résultats ne représentent donc pas directement la consommation électrique.

Ensuite, les tests ont été réalisés sur une seule machine. 
L’activité du système, les processus en arrière-plan ou la planification du processeur peuvent légèrement influencer les résultats.

Enfin, la taille du dataset utilisé dans les tests reste relativement petite par rapport à des applications réelles. 
Dans des programmes traitant de très grandes quantités de données, les différences de performance pourraient être encore plus importantes.

## Practical Engineering Takeaway

La principale conclusion de cette expérience est que le choix de l’algorithme a un impact majeur sur les performances. 
Deux programmes peuvent résoudre le même problème mais avoir des temps d’exécution très différents selon la façon dont ils sont conçus.

Un autre point important est l’importance de mesurer les performances plutôt que de les deviner.
En utilisant des benchmarks simples, il est possible d’identifier rapidement les différences entre plusieurs implémentations.

Même avec des outils simples comme `clock()`, les développeurs peuvent obtenir des informations utiles sur le comportement de leurs programmes. 
Ces mesures permettent de prendre de meilleures décisions de conception et d’écrire un code plus efficace.