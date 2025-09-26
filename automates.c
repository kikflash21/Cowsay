#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define byebyellife 0
#define lifesucks 1
#define liferocks 2 


// Fonction pour afficher une vache avec des condtions par rapport a l'etat de sante
void affiche_vache(char *eyes, char *tongue, int tail, int sante) {

    if (sante == liferocks) {
        printf("                 ^__^\n\
                 (%s)\\_______\n\
                 (__)\\      )", eyes);
        for (int y = 1; y <= tail; y++) {
            if (y % 2 != 0)
                printf("\\");
            else 
                printf("/");
        }
        printf("\n");

        printf("                %s  ||----w |\n\
                   ||     ||\n", tongue);            
    }
    else if (sante == lifesucks) {
        printf("                 ^__^\n\
                 (%s)\\_______\n\
                 (__)\\      )", "--");
        for (int y = 1; y <= tail; y++) {
            if (y % 2 != 0)
                printf("\\");
            else 
                printf("/");
        }
        printf("\n");

        printf("                %s  ||----w |\n\
                   ||     ||\n", tongue);            
    }
    else if (sante == byebyellife) {
        printf("                 ^__^\n\
                 (%s)\\_______\n\
                 (__)\\      )", "XX");
        for (int y = 1; y <= tail; y++) {
            if (y % 2 != 0)
                printf("\\");
            else 
                printf("/");
        }
        printf("\n");

        printf("                %s  ||----w |\n\
                   ||     ||\n", tongue);            
    }
} 

int stock_update(int stock, int lunchfood){
    time_t t ;
    srand (( unsigned ) time (& t ) ) ;
    int crop = rand() % 7 -3;
    if (0 > stock - lunchfood + crop) // deux if pour vérifier que le stock soit bien entre 0 et 5
        return 0;
    else if (stock - lunchfood + crop > 5)
        return 5;
    return stock - lunchfood + crop;

}

int fitness_update(int fitness, int lunchfood){
    time_t t ;
    srand (( unsigned ) time (& t ) ) ;
    int digestion = rand() % 3;
    if (0 > fitness + lunchfood - digestion) // deux if pour verifier que le fitness soit bien entre 0 et 10
        return 0;
    else if (fitness + lunchfood - digestion > 10)
        return 10;
    return fitness + lunchfood - digestion;
}

int main(int argc, char *argv[]) {
    int lunchfood; //declaration de lunchfood
    int duree_de_vie = 0; // declaration de la variable de durée de vie qui va augmenter de 1 a chaque iteration de la boucle
    int fitness = 5; // initialisation du fitness a sa valeur par defaut
    int stock = 5; // valeur par defaut du stock
    char *eyes = "00"; // Yeux par défaut
    char *tongue = " "; // Langue par défaut
    int len_tail = 3; // Taille de la queue par défaut
    int sante = liferocks; // niveau de sante par defaut
    // Parcours des arguments pour trouver les options "--eyes" ou "-e","--tongue" ou "-T", "--tail"
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
        if (strcmp(argv[i], "--sante") == 0 && i + 1 < argc) {
            sante = atoi(argv[i + 1]);
        }
    } 
    // Boucle qui ne s'arrete que quand la vache meurt
    while (sante != byebyellife) {
        affiche_vache(eyes, tongue, len_tail, sante);
        printf("Votre stock est de %d\n", stock);
        printf("Entrez la quantité de nourriture à donner à la vache (inférieure ou égale à %d) : ", stock);
        scanf("%d", &lunchfood); // demande la quantité de nourriture que l'utilisateur souhaite donner
        // Vérification de la quantité de nourriture entrée
        if (lunchfood < 0) {
            printf("La quantité de nourriture doit être positive.\n");
            continue; // Redemande à l'utilisateur d'entrer une quantité valide
        }
        
        if (lunchfood > stock) { // verification que lunchfood soit bien disponible parmi le stock
            printf("La quantité de nourriture ne peut pas dépasser la taille du stock (%d).\n", stock);
            continue; // Redemande à l'utilisateur d'entrer une quantité valide
        }
        stock = stock_update(stock, lunchfood); // mise à jour du stock et du fitness en fonction de lunchfood à chaque iteration
        fitness = fitness_update(fitness, lunchfood); 
        duree_de_vie ++;
        if (fitness >= 4 && fitness <= 6) // trois conditions pour changer la sante de la vache en fonction du fitness
            sante = liferocks;
        else if (fitness == 0 | fitness == 10)
            sante = byebyellife;
        else
            sante = lifesucks;
    }
    affiche_vache(eyes, tongue, len_tail, sante); // A la fin le programme affiche la vache morte et dit combien de jours (= iterations de la boucle) elle a vecu
    printf("La vache a vécu %d jours\n",duree_de_vie);
    return 0;
}
 
