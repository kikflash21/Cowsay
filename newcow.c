#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Fonction pour afficher une vache avec une bulle de texte
void affiche_vache(char *eyes, char *tongue, int tail, char *bulle, char *lait) {
    // Affiche la vache avec les yeux, la langue et la queue spécifiés
    printf("       %s    ^__^\n\
        %s   (%s)\\_______\n\
            (__)\\       )", bulle, bulle, eyes);
    for (int y = 1; y <= tail; y++) {
        if (y % 2 != 0)
            printf("\\");
        else 
            printf("/");
    }
    printf("\n");
    // Affiche le reste du corps de la vache avec la langue
    printf("             %s  ||----w |\n\
                ||   %s||\n", tongue, lait);            
}

// Fonction pour afficher une vache qui broute
void vache_qui_broute(char *eyes, char *tongue, int tail, char *bulle) {
    // Affiche la vache avec les yeux, la langue et la queue spécifiés
    printf(      
       "       %s   ^__^ _______\n\
        %s  (%s)/       )", bulle, bulle, eyes);

    for (int y = 1; y <= tail; y++) {
        if (y % 2 != 0)
            printf("\\");
        else 
            printf("/");
    }
    printf("\n");
    // Affiche le reste du corps de la vache avec la langue
    printf("           (__)||----w |\n\
            %s  ||     ||\n", tongue);
}



int main(int argc, char *argv[]) {
    char *eyes = "00"; // Yeux par défaut
    char *tongue = " "; // Langue par défaut
    int len_tail = 3; // Taille de la queue par défaut
    int troupe = 1; // Taille du troupeau par défaut
    char *texte = ""; // Bulle de texte par défaut 
    char *bulle = " "; // Forme de l'affichage par défaut
    int cond_affichage = 0; // Condition pour l'affichage de la bulle de texte
    char *lait = "  "; // Affichage du lait par défaut
    int cond_lait = 0; // Condition pour l'affichage du lait
    char *herbe = ""; // Affichage de l'herbe par défaut
    int cond_broute = 0; // Condition pour que la vache broute
    char gauche ;
    char droite ;

    // Parcours des arguments pour trouver les options "--eyes" ou "-e","--tongue" ou "-T", "--tail", "--troupe", "--text", "--think", "--milk", et "--broute".
    for (int i = 1; i < argc; i++) {
        if ((strcmp(argv[i], "--eyes") == 0 || strcmp(argv[i], "-e") == 0) && i + 1 < argc) {
            eyes = argv[i + 1];
        }
        if ((strcmp(argv[i], "--tongue") == 0 || strcmp(argv[i], "-T") == 0) && i + 1 < argc) {
            tongue = argv[i + 1];
        }
        if (strcmp(argv[i], "--tail") == 0 && i + 1 < argc) {
            len_tail = atoi(argv[i + 1]);
        }
        if (strcmp(argv[i], "--troupe") == 0 && i + 1 < argc) {
            troupe = atoi(argv[i + 1]);
        }
        if (strcmp(argv[i], "--text") == 0 && i + 1 < argc) {
            texte = argv[i + 1];
            cond_affichage = 1;
            bulle = "\\";
            gauche = '<' ;
            droite = '>' ;
        }
        if (strcmp(argv[i], "--think") == 0 && i + 1 < argc) {
            texte = argv[i + 1];
            cond_affichage = 1;
            bulle = "o" ;
            gauche = '(' ;
            droite = ')' ;
        }
        if (strcmp(argv[i], "--milk") == 0) {
            lait = "\\/";
            cond_lait = 1;
        }
        if (strcmp(argv[i], "--broute") == 0) {
            herbe = "wwwwwwwwwwwwwwwwwwww";
            cond_broute = 1;
        }
    }
    
    // Affiche le troupeau de vaches avec les options spécifiées
    for (int a = 1; a <= troupe; a++) {
        // Si une bulle de texte est spécifiée, l'affiche avant chaque vache
        if (cond_affichage == 1) {
            printf(" _");
            for (int b = 1; b <= strlen(texte); b++)
                printf("_");
            printf("_\n");
            printf("%c %s %c\n",gauche, texte, droite);
            printf(" -");
            for (int d = 1; d <= strlen(texte); d++)
                printf("-");
            printf("-\n");
        }
        // Affiche la vache avec les options spécifiées
        if (cond_broute == 1)
             vache_qui_broute(eyes, tongue, len_tail, bulle);
        else {
            affiche_vache(eyes, tongue, len_tail, bulle, lait);
            if (cond_lait == 1)
                printf(                    
                        "                     ||\n\
                   __||__\n\
                  |\\_||_/|\n\
                  |      |\n\
                  | LAIT |\n\
                  |______|\n");
        }
        printf("         %s\n", herbe);
    }
    return 0;
}
