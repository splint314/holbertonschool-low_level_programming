Guide du bon commit sur GitHub

Faire un bon commit, c’est avant tout rendre notre historique clair et utile pour soi et pour les autres.

🔹 1. Un message clair et concis
Titre (~50 caractères max)** → explique ce qu'on fait, pas comment.  
Exemple :  
```
fix: corrige l'affichage du bouton sur mobile
feat: ajoute la recherche par mot-clé

🔹 2. Le corps (facultatif mais utile)
Si le commit touche plusieurs choses ou nécessite du contexte :  
Le bouton "Envoyer" ne s’affichait pas sur Safari à cause d’un overflow caché.
Correction en ajustant la règle CSS.

🔹 3. Commits petits et logiques
Un commit = une idée / une modification cohérente.  
Éviter les commits “wip” ou “gros fourre-tout”.

🔹 4. Préfixes recommandés 
- `feat:` → nouvelle fonctionnalité  
- `fix:` → correction de bug  
- `refactor:` → amélioration sans changement de comportement  
- `docs:` → documentation  
- `style:` → formatage, indentation, etc.  
- `chore:` → maintenance ou tâches secondaires  
