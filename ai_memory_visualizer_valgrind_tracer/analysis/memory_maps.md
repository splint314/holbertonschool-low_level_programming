# Memory Maps Analysis

## Program: stack_example (recursion and stack frames)

### Step 1: Enter depth = 0

[STACK]

Frame depth 0:
- local_int = 100        @ 0x7ffd6331bf54
- p_local  = 0x7ffd6331bf54 → pointe vers local_int
- local_buf[0] = 'A'     @ 0x7ffd6331bf60
- marker = 0             @ 0x7ffd6331bfa4

[HEAP]
- (vide)

---

### Step 2: Enter depth = 1

[STACK]

Frame depth 1:
- local_int = 101        @ 0x7ffd6331bf24
- p_local  = 0x7ffd6331bf24 → pointe vers local_int
- local_buf[0] = 'B'     @ 0x7ffd6331bf30
- marker = 10            @ 0x7ffd6331bf74

Frame depth 0:
- toujours présent en dessous dans la stack

---

### Step 3: Enter depth = 2

[STACK]

Frame depth 2:
- local_int = 102        @ 0x7ffd6331bef4
- p_local  = 0x7ffd6331bef4
- local_buf[0] = 'C'     @ 0x7ffd6331bf00
- marker = 20            @ 0x7ffd6331bf44

Frame depth 1  
Frame depth 0  

---

### Step 4: Enter depth = 3

[STACK]

Frame depth 3 (top de la stack):
- local_int = 103        @ 0x7ffd6331bec4
- p_local  = 0x7ffd6331bec4
- local_buf[0] = 'D'     @ 0x7ffd6331bed0
- marker = 30            @ 0x7ffd6331bf14

Frame depth 2  
Frame depth 1  
Frame depth 0  

---

### Stack Behavior

- La stack grandit vers les adresses plus basses :
  0x7ffd6331bf54 → 0x7ffd6331bec4
- Chaque appel récursif crée une nouvelle stack frame indépendante
- Les variables ayant le même nom sont stockées à des adresses différentes
- Les pointeurs (p_local) pointent vers des variables locales spécifiques à chaque frame

---

### Function Exit (Unwinding)

- Lors du retour de depth = 3 → la frame est détruite
- Puis depth = 2 → détruite
- Puis depth = 1 → détruite
- Finalement retour à depth = 0

---

### Lifetime Notes

- Toutes les variables locales sont stockées sur la stack
- Elles sont valides uniquement pendant l’exécution de leur fonction
- Après le return, elles deviennent invalides
- Tout pointeur vers ces variables devient un pointeur dangling

---

### AI Analysis Issues and Corrections

#### Issue 1

AI Analysis:
"Les variables sont recréées à chaque appel récursif."

Pourquoi c’est incorrect :
Explication trop vague, ne précise pas l’organisation mémoire.

Correction :
Chaque appel récursif crée une nouvelle stack frame contenant ses propres variables locales.
Ces variables ont les mêmes noms mais occupent des adresses mémoire différentes et sont indépendantes.

---

#### Issue 2

AI Analysis:
"p_local pointe vers local_int."

Pourquoi c’est incomplet :
Ne précise pas que cela dépend de la frame courante.

Correction :
p_local contient l’adresse de local_int dans la stack frame courante.
Chaque appel récursif crée un nouveau local_int, donc chaque p_local pointe vers une adresse différente.

---

#### Issue 3

AI Analysis:
"La stack grandit à chaque appel."

Pourquoi c’est incorrect :
La direction n’est pas précisée.

Correction :
La stack grandit vers les adresses mémoire plus basses, comme le montrent les valeurs observées.

---

#### Issue 4

AI Analysis:
"Les variables restent accessibles après le return."

Pourquoi c’est faux :
Ignore la durée de vie des variables.

Correction :
Lorsqu’une fonction se termine, sa stack frame est détruite.
Toutes les variables deviennent invalides, et les pointeurs deviennent dangling.

---

## Program: heap_example (allocations and leak)

### Observed Allocations

- alice = 0x60acd03e86b0
- alice->name = 0x60acd03e86d0

- bob = 0x60acd03e86f0
- bob->name = 0x60acd03e8710

---

### Memory Layout

[HEAP]

0x60acd03e86b0 → struct alice
    └── name → 0x60acd03e86d0

0x60acd03e86f0 → struct bob
    └── name → 0x60acd03e8710

[STACK]
- pointeurs vers alice et bob (non affichés mais implicites)

---

### Key Observations

- Le heap est séparé de la stack (adresses différentes : 0x60... vs 0x7ffd...)
- Chaque structure contient un pointeur vers une autre zone du heap
- Il y a plusieurs niveaux d’allocation

---

### Lifetime Notes

- La mémoire allouée avec malloc reste valide jusqu’à free
- Dans ce programme, aucun free n’est appelé
- Toutes les allocations restent en mémoire jusqu’à la fin du programme

---

### Memory Leak

- alice n’est pas libéré
- bob n’est pas libéré
- alice->name n’est pas libéré
- bob->name n’est pas libéré

→ fuite mémoire volontaire

---

### AI Analysis Issues and Corrections

#### Issue 1

AI Analysis:
"La mémoire est libérée automatiquement à la fin."

Pourquoi c’est incorrect :
Confusion entre OS et programme C.

Correction :
La mémoire n’est pas libérée par le programme (absence de free).
C’est donc une fuite mémoire, même si l’OS récupère la mémoire après l’exécution.

---

#### Issue 2

AI Analysis:
"alice et bob sont indépendants."

Pourquoi c’est incomplet :
Ignore les pointeurs internes.

Correction :
alice et bob sont des allocations distinctes, mais chacune contient un pointeur vers une autre zone mémoire.
Toutes ces allocations doivent être libérées individuellement.

---

### Final Insight

- Stack → mémoire temporaire (frames, variables locales)
- Heap → mémoire persistante (malloc/free)
- Pointeurs → liens entre zones mémoire
- Une mauvaise gestion des pointeurs entraîne :
  - dangling pointers (stack)
  - memory leaks (heap)