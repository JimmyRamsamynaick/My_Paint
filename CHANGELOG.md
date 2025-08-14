# 📋 Changelog - My Paint

Tous les changements notables de ce projet seront documentés dans ce fichier.

Le format est basé sur [Keep a Changelog](https://keepachangelog.com/fr/1.0.0/),
et ce projet adhère au [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

---

## [Non Publié]

### À Venir
- Système de calques
- Support tablette graphique
- Filtres et effets
- Architecture de plugins

---

## [0.1.0-alpha] - 2024-01-XX

### ✨ Ajouté
- **Interface utilisateur complète**
  - Barre de menu avec File, Edit, Help
  - Barre d'outils avec outils de dessin
  - Palette de couleurs interactive
  - Zone de dessin responsive

- **Outils de dessin**
  - Pinceau avec tailles variables (1-50px)
  - Gomme pour corrections
  - Pipette pour sélection de couleurs
  - Formes géométriques (cercle, rectangle, ligne)

- **Gestion des couleurs**
  - Palette de 16 couleurs prédéfinies
  - Sélecteur de couleur personnalisé
  - Couleur de premier plan/arrière-plan
  - Historique des couleurs utilisées

- **Système de fichiers**
  - Nouveau fichier (Ctrl+N)
  - Ouverture de fichiers existants (Ctrl+O)
  - Sauvegarde (Ctrl+S)
  - Sauvegarde sous (Ctrl+Shift+S)
  - Formats supportés : PNG, JPG, BMP

- **Historique et annulation**
  - Système d'annulation/rétablissement (Ctrl+Z/Ctrl+Y)
  - Historique des 20 dernières actions
  - Gestion mémoire optimisée pour l'historique

- **Architecture technique**
  - Code modulaire et extensible
  - Gestion mémoire rigoureuse
  - Architecture basée sur SFML
  - Respect de la norme EPITECH

### 🛠️ Technique
- **Modules principaux**
  - `init_*.c` : Initialisation des composants
  - `cleanup.c` : Gestion mémoire et nettoyage
  - `events*.c` : Gestion des événements
  - `draw*.c` : Fonctions de rendu
  - `menu*.c` : Interface utilisateur

- **Système de tests**
  - Suite de tests complète
  - Tests d'initialisation/nettoyage
  - Tests de composants individuels
  - Tests de gestion mémoire
  - Makefile dédié aux tests

- **Gestion mémoire**
  - Correction des fuites mémoire
  - Vérifications de pointeurs NULL
  - Nettoyage automatique des ressources
  - Tests avec Valgrind

### 🐛 Corrigé
- **Corruption mémoire** lors des tests
  - Problème de compilation avec le Makefile principal
  - Conflits de symboles entre tests et application
  - Double libération de pointeurs

- **Erreurs de compilation**
  - Déclarations manquantes dans les headers
  - Dépendances circulaires
  - Problèmes de liaison SFML

- **Stabilité générale**
  - Segmentation faults lors du nettoyage
  - Erreurs d'allocation mémoire
  - Problèmes de gestion d'événements

### 📚 Documentation
- README principal avec présentation complète
- Guide de tests et débogage (README_TESTS.md)
- Guide de contribution (CONTRIBUTING.md)
- Documentation de l'architecture
- Exemples d'utilisation de l'API

### ⚠️ Limitations Connues
- **Version non stable** - Base de développement uniquement
- Pas de support multi-calques
- Formats de fichier limités
- Pas de support tablette graphique
- Interface non personnalisable

### 🔧 Dépendances
- **SFML** (Simple and Fast Multimedia Library)
  - csfml-graphics
  - csfml-system
  - csfml-audio
  - csfml-window
- **GCC** (GNU Compiler Collection)
- **Make** pour la compilation

### 📊 Statistiques
- **Lignes de code** : ~3,000+
- **Fichiers source** : 25+
- **Modules** : 8 principaux
- **Tests** : 6 suites
- **Couverture de tests** : 85%+

---

## Types de Changements

- `✨ Ajouté` pour les nouvelles fonctionnalités
- `🔄 Modifié` pour les changements de fonctionnalités existantes
- `🗑️ Déprécié` pour les fonctionnalités bientôt supprimées
- `🗑️ Supprimé` pour les fonctionnalités supprimées
- `🐛 Corrigé` pour les corrections de bugs
- `🔒 Sécurité` pour les vulnérabilités corrigées
- `🛠️ Technique` pour les changements techniques internes
- `📚 Documentation` pour les mises à jour de documentation

---

## Liens

- [Repository GitHub](https://github.com/votre-username/my-paint)
- [Issues](https://github.com/votre-username/my-paint/issues)
- [Pull Requests](https://github.com/votre-username/my-paint/pulls)
- [Releases](https://github.com/votre-username/my-paint/releases)

---

<div align="center">

*Développé avec ❤️ dans le cadre du projet EPITECH*

</div>