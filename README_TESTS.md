# Tests et Débogage - My Paint

## Problème Résolu : Corruption de Mémoire

### Description du Problème
Le test `test_init_all.c` échouait avec une erreur `malloc: *** error for object: pointer being freed was not allocated` lors de l'exécution via le Makefile principal.

### Cause Identifiée
Le problème venait du fait que le Makefile principal incluait les fichiers de test dans la compilation de l'exécutable principal `my_paint`, créant des conflits de symboles et des problèmes de gestion mémoire.

### Solution Implémentée

1. **Modification du Makefile principal** :
   - Ajout d'un filtre pour exclure les fichiers `test_*.c` de la compilation principale
   - `SRC := $(filter-out test_%.c, $(SRC))`

2. **Création d'un Makefile dédié aux tests** :
   - `Makefile_tests` : système de compilation séparé pour les tests
   - Compilation indépendante évitant les conflits

3. **Amélioration de la fonction `cleanup_all`** :
   - Ajout de vérifications de pointeurs NULL
   - Mise à NULL des pointeurs après libération
   - Messages de débogage pour traçabilité

## Utilisation du Système de Tests

### Compilation des Tests
```bash
# Compiler un test spécifique
make -f Makefile_tests test_init_all

# Compiler tous les tests
make -f Makefile_tests all_tests

# Nettoyer les exécutables de test
make -f Makefile_tests clean_tests
```

### Exécution des Tests
```bash
# Test principal d'initialisation/nettoyage
./test_init_all

# Autres tests disponibles
./test_components
./test_partial_init
```

### Tests Disponibles

- **`test_init_all.c`** : Test complet d'initialisation et de nettoyage
- **`test_components.c`** : Test des composants individuels
- **`test_partial_init.c`** : Test d'initialisation partielle

## Compilation de l'Application Principale

```bash
# Compilation normale (exclut automatiquement les tests)
make clean && make

# Exécution de l'application
./my_paint
```

## Résultats

✅ **Problème résolu** : Plus d'erreurs de corruption mémoire
✅ **Tests fonctionnels** : Tous les tests passent avec succès
✅ **Application stable** : L'application principale compile et fonctionne correctement
✅ **Système maintenable** : Séparation claire entre application et tests

## Notes Techniques

- Les avertissements `sfMouseWheelEvent deprecated` sont normaux (liés à SFML)
- Le système de tests utilise les mêmes dépendances que l'application principale
- La fonction `cleanup_all` a été renforcée pour éviter les double-libérations