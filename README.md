# Cowsay amélioré – Bash & C

**Période:** Février 2024 – Avril 2024

## 📋 Description du projet

Développement d'une version enrichie du programme **Cowsay**, affichant un message dans une bulle de dialogue accompagnée d'un ASCII art de vache. Ce projet a abouti à un outil fonctionnel et interactif, démontrant des compétences en scripting shell et programmation système en C.

### Fonctionnalités principales

- **Affichage personnalisable de vaches** : Modification des yeux, de la langue et de la queue
- **Bulles de texte** : Affichage de messages dans des bulles de dialogue (`--text` ou `--think`)
- **Troupeaux de vaches** : Affichage multiple avec option `--troupe`
- **Effets spéciaux** : Vaches qui broûtent, affichage de lait
- **Automates interactifs** : Vaches avec état de santé basé sur l'alimentation
- **Scripts Bash spécialisés** : Différents niveaux scolaires avec logique Fibonacci

## 🏗️ Architecture du projet

### Fichiers C (80.3%)
- **`newcow.c`** - Programme principal de Cowsay avec options complètes
  - Options: `--eyes`, `--tongue`, `--tail`, `--troupe`, `--text`, `--think`, `--milk`, `--broute`
  - Affichage de troupeaux de vaches personnalisées

- **`wildcow.c`** - Version "sauvage" avec ASCII art avancé

- **`reading_cow.c`** - Vache lectrice avec interactions

- **`automates.c`** - Tamagotchi-like : vache interactive avec système d'alimentation
  - Gestion du stock de nourriture
  - Suivi du fitness (0-10)
  - États de santé (mort, sain, malade)
  - Durée de vie basée sur le fitness

### Scripts Bash (18.8%)
- **`cow_kindergarten.sh`** - Affichage simple de vaches
- **`cow_primaryschool.sh`** - Vaches avec fonctionnalités basiques
- **`cow_college.sh`** - Suite de Fibonacci interactive avec Cowsay
- **`cow_university.sh`** - Fonctionnalités avancées
- **`crazy_cow.sh`** - Variantes créatives
- **`smart_cow.sh`** - Logique avancée

### Build & Configuration (0.9%)
- **`Makefile.mak`** - Compilation avec clang des fichiers C

## 🛠️ Compilation et utilisation

### Compiler le projet
```bash
make -f Makefile.mak all
```

### Exécuter les programmes

**Version principale :**
```bash
./new --text "Hello World" --eyes "oo" --tongue " " --tail 3
./new --think "Je pense donc je suis"
./new --troupe 3
./new --broute
./new --milk
```

**Version automate (Tamagotchi) :**
```bash
./automates
./automates --eyes "^^" --sante 1
```

**Scripts interactifs :**
```bash
./cow_college.sh 20  # Fibonacci jusqu'à 20
```

## 🎯 Compétences développées

- **Programmation en C** : Gestion de chaînes, arguments en ligne de commande, affichage ASCII
- **Scripting Bash** : Boucles, conditions, intégration avec programmes C
- **Gestion de systèmes** : Intégration de commandes système, manipulation de processus
- **Algorithmique** : Suite de Fibonacci, automates avec états
- **Build & Compilation** : Configuration Makefile, optimisation clang

## 📂 Langue du projet

| Langage | Pourcentage |
|---------|------------|
| C | 80.3% |
| Shell | 18.8% |
| Makefile | 0.9% |

## 📚 Documentation additionnelle

Un rapport détaillé est disponible dans `Compte rendu cowsay pdf.pdf` contenant l'analyse complète du projet, les spécifications et les résultats.

---

**Auteur:** kikflash21  
**Type de projet:** Éducatif - Programmation système
