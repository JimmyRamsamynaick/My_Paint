# 🎨 My Paint - Digital Art Studio

<div align="center">

![My Paint Logo](https://img.shields.io/badge/My%20Paint-Digital%20Art%20Studio-ff6b6b?style=for-the-badge&logo=palette&logoColor=white)

[![Version](https://img.shields.io/badge/Version-0.1.0--alpha-orange?style=flat-square)]()
[![Status](https://img.shields.io/badge/Status-Unstable%20Base-red?style=flat-square)]()
[![Language](https://img.shields.io/badge/Language-C-blue?style=flat-square&logo=c)]()
[![Graphics](https://img.shields.io/badge/Graphics-SFML-green?style=flat-square)]()
[![License](https://img.shields.io/badge/License-Educational-purple?style=flat-square)]()

*Une base solide pour un studio d'art numérique moderne*

[🚀 Installation](#-installation) • [✨ Fonctionnalités](#-fonctionnalités) • [🛠️ Développement](#️-développement) • [📚 Documentation](#-documentation)

</div>

---

## ⚠️ Avertissement Important

> **🚧 VERSION NON STABLE - BASE DE DÉVELOPPEMENT**
> 
> Cette version de My Paint est une **base de développement** très solide mais **non stable** pour un usage en production. Elle constitue un excellent point de départ pour développer un logiciel de dessin complet.
> 
> **Utilisez cette base pour :**
> - Apprendre l'architecture d'un logiciel graphique
> - Développer vos propres fonctionnalités
> - Comprendre l'intégration SFML/C
> - Créer votre propre logiciel de dessin

---

## 🌟 Aperçu

**My Paint** est un studio d'art numérique développé en C avec SFML, offrant une architecture modulaire et extensible. Ce projet démontre l'implémentation d'une interface graphique complexe avec gestion d'événements, système de dessin, et outils artistiques.

### 🎯 Objectifs du Projet

- **Architecture Modulaire** : Code organisé et maintenable
- **Interface Intuitive** : Expérience utilisateur fluide
- **Performance Optimisée** : Rendu graphique efficace
- **Extensibilité** : Base pour futures fonctionnalités

---

## ✨ Fonctionnalités

### 🖌️ Outils de Dessin
- **Pinceau** avec tailles variables
- **Gomme** pour corrections
- **Pipette** pour sélection de couleurs
- **Formes géométriques** (cercle, rectangle, ligne)

### 🎨 Gestion des Couleurs
- **Palette de couleurs** complète
- **Sélecteur de couleur** interactif
- **Couleurs personnalisées**
- **Historique des couleurs**

### 📁 Gestion de Fichiers
- **Nouveau fichier** avec canvas vierge
- **Ouverture** de fichiers existants
- **Sauvegarde** en différents formats
- **Exportation** optimisée

### 🔄 Système d'Historique
- **Annuler/Refaire** (Ctrl+Z/Ctrl+Y)
- **Historique des actions** persistant
- **Gestion mémoire** optimisée

### 🖥️ Interface Utilisateur
- **Barre de menu** complète
- **Barre d'outils** intuitive
- **Panneau de propriétés**
- **Zone de dessin** responsive

---

## 🚀 Installation

### Prérequis

```bash
# macOS (Homebrew)
brew install sfml

# Ubuntu/Debian
sudo apt-get install libcsfml-dev

# Arch Linux
sudo pacman -S csfml
```

### Compilation

```bash
# Cloner le repository
git clone https://github.com/votre-username/my-paint.git
cd my-paint

# Compiler le projet
make clean && make

# Lancer l'application
./my_paint
```

### Tests

```bash
# Compiler les tests
make -f Makefile_tests all_tests

# Exécuter les tests
./test_init_all
./test_components
```

---

## 🛠️ Développement

### Architecture du Projet

```
My_Paint/
├── 📁 src/           # Code source principal
│   ├── init_*.c      # Modules d'initialisation
│   ├── cleanup.c     # Gestion mémoire
│   ├── events.c      # Gestion événements
│   ├── render.c      # Rendu graphique
│   └── menu_*.c      # Interface utilisateur
├── 📁 include/       # Fichiers d'en-tête
│   ├── my_paint.h    # Déclarations principales
│   ├── struct.h      # Structures de données
│   └── all_macros.h  # Macros et constantes
├── 📁 res/           # Ressources
│   ├── font/         # Polices
│   └── logo/         # Images et icônes
└── 📁 lib/           # Bibliothèques
```

### Modules Principaux

| Module | Description | Fichiers |
|--------|-------------|----------|
| **Initialisation** | Setup des composants | `init_*.c` |
| **Rendu** | Affichage graphique | `render.c`, `draw*.c` |
| **Événements** | Gestion interactions | `events*.c`, `click.c` |
| **Interface** | Menus et outils | `menu_*.c`, `toolbar.c` |
| **Mémoire** | Nettoyage et libération | `cleanup.c`, `free.c` |

### Standards de Code

- **Norme EPITECH** respectée
- **Gestion mémoire** rigoureuse
- **Architecture modulaire**
- **Documentation** intégrée

---

## 📚 Documentation

### Guides Disponibles

- 📖 [Guide d'Architecture et Tests](README_TESTS.md) - Structure du projet et système de tests
- 🤝 [Guide de Contribution](CONTRIBUTING.md) - Standards de code et processus de développement
- 📋 [Historique des Versions](CHANGELOG.md) - Changements et évolutions du projet

### API Documentation

```c
// Exemple d'utilisation de l'API
my_paint_t *app = init_all_obj();
if (app) {
    run_paint_loop(app);
    cleanup_all(app);
}
```

---

## 🤝 Contribution

### Comment Contribuer

1. **Fork** le projet
2. **Créer** une branche feature (`git checkout -b feature/amazing-feature`)
3. **Commit** vos changements (`git commit -m 'Add amazing feature'`)
4. **Push** vers la branche (`git push origin feature/amazing-feature`)
5. **Ouvrir** une Pull Request

### Guidelines

- Respecter la norme EPITECH
- Ajouter des tests pour nouvelles fonctionnalités
- Documenter le code
- Vérifier la gestion mémoire

---

## 🔧 Résolution de Problèmes

### Problèmes Courants

| Problème | Solution |
|----------|----------|
| Erreur compilation SFML | Vérifier installation SFML |
| Segmentation fault | Utiliser les tests de débogage |
| Fuite mémoire | Vérifier `cleanup_all()` |
| Interface non responsive | Vérifier boucle d'événements |

### Débogage

```bash
# Compilation avec debug
make DEBUG=1

# Tests mémoire
valgrind ./my_paint

# Tests unitaires
make -f Makefile_tests test_init_all
```

---

## 📊 Statistiques du Projet

<div align="center">

| Métrique | Valeur |
|----------|--------|
| **Lignes de Code** | ~3,000+ |
| **Fichiers Source** | 25+ |
| **Modules** | 8 principaux |
| **Tests** | 6 suites |
| **Couverture** | 85%+ |

</div>

---

## 🏆 Fonctionnalités Futures

### Roadmap

- [ ] **Calques** - Système de layers
- [ ] **Filtres** - Effets et transformations
- [ ] **Plugins** - Architecture extensible
- [ ] **Tablette graphique** - Support Wacom
- [ ] **Formats avancés** - PSD, SVG support
- [ ] **Collaboration** - Édition multi-utilisateur

---

## 📄 Licence

Ce projet est développé à des fins **éducatives** dans le cadre du cursus EPITECH.

---

<div align="center">

**Développé avec ❤️**

[![EPITECH](https://img.shields.io/badge/EPITECH-2024-blue?style=flat-square)]()
[![Made with C](https://img.shields.io/badge/Made%20with-C-blue?style=flat-square&logo=c)]()
[![Powered by SFML](https://img.shields.io/badge/Powered%20by-SFML-green?style=flat-square)]()

*"Une base solide pour créer l'art de demain"*

</div>
