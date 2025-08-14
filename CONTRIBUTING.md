# 🤝 Guide de Contribution - My Paint

<div align="center">

![Contributing](https://img.shields.io/badge/Contributions-Welcome-brightgreen?style=for-the-badge)
![Code Style](https://img.shields.io/badge/Code%20Style-EPITECH-blue?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C-orange?style=for-the-badge)

*Merci de votre intérêt pour contribuer à My Paint !*

</div>

---

## 🎯 Types de Contributions

Nous accueillons tous types de contributions :

- 🐛 **Corrections de bugs**
- ✨ **Nouvelles fonctionnalités**
- 📚 **Amélioration de la documentation**
- 🧪 **Tests supplémentaires**
- 🎨 **Améliorations UI/UX**
- ⚡ **Optimisations de performance**

---

## 🚀 Démarrage Rapide

### 1. Fork et Clone

```bash
# Fork le repository sur GitHub
# Puis cloner votre fork
git clone https://github.com/VOTRE-USERNAME/my-paint.git
cd my-paint
```

### 2. Configuration de l'Environnement

```bash
# Installer les dépendances
brew install sfml  # macOS
# ou
sudo apt-get install libcsfml-dev  # Ubuntu

# Tester la compilation
make clean && make
```

### 3. Créer une Branche

```bash
# Créer une branche pour votre feature
git checkout -b feature/nom-de-votre-feature

# Ou pour un bugfix
git checkout -b bugfix/description-du-bug
```

---

## 📋 Standards de Code

### Norme EPITECH

Tous les fichiers doivent respecter la **norme EPITECH** :

```c
/*
** EPITECH PROJECT, 2024
** My Paint
** File description:
** Description du fichier
*/

#include "my_paint.h"

int my_function(int param)
{
    if (param < 0)
        return -1;
    return param * 2;
}
```

### Conventions de Nommage

- **Fonctions** : `snake_case` (ex: `init_canvas`, `cleanup_all`)
- **Variables** : `snake_case` (ex: `current_tool`, `canvas_width`)
- **Structures** : `snake_case_t` (ex: `my_paint_t`, `canvas_t`)
- **Macros** : `UPPER_CASE` (ex: `WINDOW_WIDTH`, `MAX_COLORS`)

### Organisation des Fichiers

```
src/
├── init_*.c      # Modules d'initialisation
├── cleanup.c     # Gestion mémoire
├── events*.c     # Gestion événements
├── draw*.c       # Fonctions de dessin
├── menu*.c       # Interface utilisateur
└── utils*.c      # Fonctions utilitaires
```

---

## 🧪 Tests

### Exécuter les Tests

```bash
# Compiler tous les tests
make -f Makefile_tests all_tests

# Exécuter les tests principaux
./test_init_all
./test_components

# Tests de mémoire
valgrind ./test_init_all
```

### Ajouter de Nouveaux Tests

1. Créer `test_votre_feature.c`
2. Ajouter la règle dans `Makefile_tests`
3. Suivre le pattern existant :

```c
#include "my_paint.h"

int main(void)
{
    printf("Testing votre_feature...\n");
    
    // Votre test ici
    
    printf("Test completed successfully!\n");
    return 0;
}
```

---

## 🔧 Gestion Mémoire

### Règles Importantes

1. **Toujours libérer** la mémoire allouée
2. **Vérifier les pointeurs** avant utilisation
3. **Mettre à NULL** après libération
4. **Utiliser les fonctions de cleanup** existantes

### Exemple Correct

```c
void cleanup_component(component_t *comp)
{
    if (!comp)
        return;
    
    if (comp->data) {
        free(comp->data);
        comp->data = NULL;
    }
    
    if (comp->texture) {
        sfTexture_destroy(comp->texture);
        comp->texture = NULL;
    }
    
    free(comp);
}
```

---

## 📝 Documentation

### Commentaires de Code

```c
/*
** Initialise le canvas avec les dimensions spécifiées
** Alloue la mémoire nécessaire et configure les paramètres par défaut
*/
canvas_t *init_canvas(int width, int height)
{
    // Implementation...
}
```

### Documentation des Fonctions

- **Objectif** de la fonction
- **Paramètres** et leur signification
- **Valeur de retour**
- **Effets de bord** éventuels

---

## 🔄 Processus de Contribution

### 1. Développement

```bash
# Développer votre feature
vim src/ma_nouvelle_feature.c

# Tester régulièrement
make && ./my_paint
make -f Makefile_tests test_ma_feature && ./test_ma_feature
```

### 2. Validation

```bash
# Vérifier la compilation
make clean && make

# Exécuter tous les tests
make -f Makefile_tests all_tests
./test_init_all
./test_components

# Vérifier la mémoire
valgrind ./my_paint
```

### 3. Commit

```bash
# Commits atomiques et descriptifs
git add src/ma_nouvelle_feature.c
git commit -m "✨ Add: nouvelle fonctionnalité de dessin

- Implémentation du pinceau texturé
- Tests unitaires ajoutés
- Documentation mise à jour"
```

### 4. Pull Request

1. **Push** votre branche
2. **Créer** une Pull Request sur GitHub
3. **Décrire** vos changements
4. **Lier** les issues résolues

---

## 📋 Template de Pull Request

```markdown
## 🎯 Description
Brève description de vos changements.

## 🔧 Type de Changement
- [ ] Bug fix
- [ ] Nouvelle fonctionnalité
- [ ] Breaking change
- [ ] Documentation

## 🧪 Tests
- [ ] Tests existants passent
- [ ] Nouveaux tests ajoutés
- [ ] Tests manuels effectués

## 📝 Checklist
- [ ] Code respecte la norme EPITECH
- [ ] Pas de fuites mémoire
- [ ] Documentation mise à jour
- [ ] Commit messages descriptifs
```

---

## 🐛 Signaler un Bug

### Template d'Issue

```markdown
## 🐛 Description du Bug
Description claire et concise du problème.

## 🔄 Reproduction
1. Étapes pour reproduire
2. Comportement attendu
3. Comportement observé

## 🖥️ Environnement
- OS: [macOS/Linux/Windows]
- Compilateur: [gcc version]
- SFML: [version]

## 📎 Informations Supplémentaires
Logs, captures d'écran, etc.
```

---

## 💡 Proposer une Fonctionnalité

### Template de Feature Request

```markdown
## ✨ Fonctionnalité Proposée
Description de la fonctionnalité souhaitée.

## 🎯 Motivation
Pourquoi cette fonctionnalité serait utile ?

## 💭 Solution Proposée
Comment imaginez-vous l'implémentation ?

## 🔄 Alternatives
Autres approches considérées.
```

---

## 🏆 Reconnaissance

Tous les contributeurs seront :

- 📝 **Mentionnés** dans le README
- 🎖️ **Crédités** dans les releases
- 🌟 **Remerciés** publiquement

---

## 📞 Contact

Questions ? N'hésitez pas à :

- 💬 Ouvrir une **Discussion** sur GitHub
- 📧 Contacter par **email**
- 🐛 Créer une **Issue** pour les bugs

---

<div align="center">

**Merci de contribuer à My Paint ! 🎨**

*Ensemble, créons un outil de dessin exceptionnel*

</div>