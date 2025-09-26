#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Fonction pour mettre à jour et effacer l'écran
void update() {
    printf("\033[H\033[J");
}

// Fonction pour afficher la vache avec les yeux, la langue et la bulle spécifiés
void affiche_vache(char *eyes, char tongue, char *bulle) {
    // Affiche la vache avec les yeux, la langue et la queue spécifiés
    printf("       %s    ^__^\n\
        %s   (%s)\\_______\n\
            (__)\\       )\\/\\\n", bulle, bulle, eyes);
    printf("             %c  ||----w |\n\
                ||     ||\n", tongue);            
}
// Fonction pour afficher un texte encadré
void affichage(char *texte){
    printf(" _");
    for (int b = 1; b <= strlen(texte); b++)
        printf("_");
    printf("_\n");
    printf("< %s >\n", texte);
    printf(" -");
    for (int d = 1; d <= strlen(texte); d++)
        printf("-");
    printf("-\n");
}

int main(int argc, char *argv[]){
    
    char *eye = "oo"; // Yeux par défaut
    char *ko = "xx"; // Yeux pour l'erreur
    char langue = 'U'; // Langue par défaut
    char *bulle = "\\"; // Forme de la bulle par defaut
    char *vide = " "; 
    char vide2 = ' ';
    char *erreur = "Fichier erroné"; // Message d'erreur
    char *fichier; // Initialisation du nom de fichier a lire
    int longueur = 0;
    char message[256] = ""; // Tableau pour stocker le texte
    FILE* f ; // Pointeur de fichier
    int cond_close = 0; // Condition pour fermer le fichier
    
    // Vérification si un fichier est passé en argument
    if (argc >= 2){
        fichier = argv[1];
        f = fopen(fichier, "r");
        cond_close = 1;
        if (f == NULL){
            // Affiche le message d'erreur si le fichier n'est pas valide
            affichage(erreur);
            affiche_vache(ko, langue, bulle);
            return 1;
        }
    }    
    else{ 
        printf("Entrer un texte : ");
        f = stdin; // Utilise l'entrée standard
    }
    char c = fgetc(f); // Lit le premier caractère
    int i = 0; // Indice du message
    
    // Affiche la vache avec le premier caractère
    update();
    affiche_vache(eye, c, vide);
    message[i] = c;
    c = fgetc(f);
    sleep(1);
    i++;
    
    // Lit les caractères suivants jusqu'à la fin du fichier ou la fin de la lign
    while (c != EOF && c != '\n') {
        update();
        affichage(message);
        message[i] = c;
        affiche_vache(eye, c, bulle);
        c = fgetc(f);
        sleep(1);
        i++;
    }

    // Affiche le message final et la vache avec un caractère vide pour la langue
    update();
    affichage(message);
    affiche_vache(eye, vide2, bulle);
    printf("\n");

    // Ferme le fichier si nécessaire
    if (cond_close == 1)
        fclose(f);
    return 0;
}