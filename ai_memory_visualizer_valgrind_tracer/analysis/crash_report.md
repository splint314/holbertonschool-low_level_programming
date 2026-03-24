# Crash Report

## Description du crash

Le programme se termine par un crash causé par un invalid memory access

Ce crash est la conséquence directe d’un undefined behavior survenu plus tôt dans l’exécution

---

## Root cause analysis

Le crash est causé par l’utilisation d’un pointeur qui référence une zone mémoire dont le lifetime est terminé

Cas probable
Un pointeur vers une variable locale stockée sur la stack utilisé après le return de la fonction

---

## Type de mémoire impliqué

Stack memory

Les variables locales sont allouées sur la stack et leur lifetime se termine à la fin de la fonction

Un pointeur qui continue de référencer cette mémoire devient un dangling pointer

---

## Enchaînement des causes

Une fonction déclare une variable locale sur la stack
Un pointeur prend l’adresse de cette variable
La fonction retourne
La stack frame est détruite
Le pointeur devient un dangling pointer
Le programme utilise ce pointeur
Un invalid memory access se produit
Le programme crash

---

## Pourquoi l’accès est invalide

La mémoire pointée n’est plus valide car son lifetime est terminé

Même si l’adresse contient encore une valeur
Elle ne doit plus être utilisée

Type d’undefined behavior
Use after scope

---

## Analyse critique de l’IA

### Proposition de l’IA

L’IA propose
Un pointeur non initialisé
Ou un problème de malloc

### Évaluation

Correct
L’IA identifie un invalid memory access

Incorrect ou incomplet
Ne distingue pas stack vs heap
Ne parle pas de lifetime
Propose malloc sans lien direct avec la cause

Le problème n’est pas l’allocation mais l’utilisation d’un pointeur invalide

---

## Conclusion

Le crash est causé par un dangling pointer vers une zone mémoire dont le lifetime est terminé

Type d’erreur
Use after scope sur la stack

Le crash est une conséquence directe d’un undefined behavior

---

## Suggested fix optionnel

Ne jamais retourner ou stocker l’adresse d’une variable locale

Solutions possibles
Allouer sur le heap avec malloc
Ou limiter l’utilisation du pointeur à un scope valide
