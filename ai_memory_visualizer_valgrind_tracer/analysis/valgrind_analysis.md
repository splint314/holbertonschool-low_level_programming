# Analyse Valgrind

## Programme heap_example

### Résumé de la sortie Valgrind

1 fuite mémoire détectée
6 octets perdus dans 1 bloc definitely lost
5 allocations 4 libérations

---

## Problème fuite mémoire

### Type d’erreur

Fuite mémoire definitely lost

### Objet mémoire concerné

Une chaîne de caractères allouée dynamiquement char *name dans une structure Person

### Origine de l’allocation

Fonction person_new
Ligne heap_example.c 21
Allocation via malloc

### Explication de l’erreur

La mémoire allouée pour name n’est pas libérée avant la fin du programme

Le bloc mémoire est encore alloué mais aucun pointeur n’y fait référence au moment de la fin du programme
Cela correspond à une perte de propriété mémoire

Valgrind indique definitely lost car le programme a perdu toute référence vers ce bloc

---

## Violation de durée de vie

La mémoire allouée pour name devrait être libérée avant la destruction de la structure Person

Ici la durée de vie de name dépasse celle de son propriétaire
Cela indique que la libération est incomplète ou oubliée pour une instance

---

## Cause racine

Le programme ne libère pas correctement tous les champs internes des structures

Une structure contenant un pointeur nécessite de libérer
D’abord les champs internes
Ensuite la structure elle-même

---

## Analyse critique de l’IA

### Hypothèse initiale

L’IA indique que le champ name n’est pas libéré

### Vérification

Une seule fuite est détectée 6 octets 1 bloc
Cela correspond à une petite chaîne de caractères

### Conclusion

L’analyse est partiellement correcte
La cause est bien un oubli de libération
Mais une seule instance est concernée et non toutes

---

## Conclusion

Fuite mémoire causée par une perte de propriété sur un champ dynamique name
Erreur classique de gestion mémoire dans une structure composée

---

## Programme stack_example

### Résumé de la sortie Valgrind

Aucune fuite mémoire
0 erreurs détectées
Toutes les allocations ont été libérées

---

## Analyse

### Type d’erreur

Aucune erreur mémoire détectée

### Objet mémoire concerné

Variables locales sur la pile stack
local_int local_buf marker

### Explication

Toutes les variables utilisées sont allouées sur la pile
Leur durée de vie est automatiquement gérée par les appels de fonction

Chaque appel récursif crée une nouvelle frame avec ses propres variables
Les adresses affichées diminuent ce qui montre la croissance de la pile

Lors du retour de fonction les frames sont détruites correctement
Aucune utilisation après libération ni accès invalide

---

## Conclusion

Le programme respecte correctement les règles de gestion mémoire
Aucune fuite ni violation de durée de vie
Exemple correct d’utilisation de la pile avec récursion
