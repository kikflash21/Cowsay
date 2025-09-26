#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Fonction pour mettre à jour et effacer l'écran
void update() {
    printf("\033[H\033[J");
}

// Fonction pour déplacer le curseur à la position (x, y)
void gotoxy(int x, int y) {
    printf("\033[%d;%dH", x, y);
}

// Fonction pour afficher une vache 
void affiche_vache_droite(char *eye, char *patte, char *patte2, char *une_patte, char*bulle, char *langue, int x, int y){
    gotoxy(x,y);
    printf("%s   ^__^\n", bulle);
    printf("\n");
    gotoxy(x+1,y);
    printf(" %s  (%s)\\_______\n",bulle, eye);
    gotoxy(x+2,y);
    printf("    (__)\\       )\\/\\\n");
    gotoxy(x+3,y);
    printf("     %s  %s----w %s\n", langue, patte, une_patte);
    gotoxy(x+4,y);
    printf("       %s     %s\n", patte2, patte);
}

// Fonction pour afficher une vache tournée vers la gauche
void affiche_vache_gauche(char *eye, char *patte, char *patte2, char* une_patte, int x, int y){
    gotoxy(x,y);
    printf("             ^__^\n");
    printf("\n");
    gotoxy(x+1,y);
    printf("     _______/(%s)\n",eye);
    gotoxy(x+2,y);
    printf(" /\\/(       /(__)\n");
    gotoxy(x+3,y);
    printf("    %s w----%s\n", patte, une_patte);
    gotoxy(x+4,y);
    printf("    %s     %s\n", patte2, patte2);
}
// Fonction pour afficher une vache qui est baissé
void vache_prepare(int x, int y){
    gotoxy(x+1,y);
    printf("     _______ ^__^");
    gotoxy(x+2,y);
    printf(" /\\/(       /(00)");
    gotoxy(x+3,y);
    printf("    || w----|(__)");
    gotoxy(x+4,y);
    printf("    ||     ||");
}

// Fonction pour afficher le texte
void affichage(char *texte){
    gotoxy(9,1);
    printf(" _");
    for (int b = 1; b <= strlen(texte); b++)
        printf("_");
    printf("_\n");
    gotoxy(10,1);
    printf("< %s >\n",texte);
    gotoxy(11,1);
    printf(" -");
    for (int d = 1; d <= strlen(texte); d++)
        printf("-");
    printf("-\n");    
}


// Fonction pour afficher la barrière
void barriere(int x, int y){
    gotoxy(x,y);
    printf("     ____");
    gotoxy(x+1,y);
    printf("    /    \\");
    gotoxy(x+2,y);
    printf("   /      \\");  
    gotoxy(x+3,y);
    printf("   |      |");
    gotoxy(x+4,y);
    printf("   |      |"); 
    gotoxy(x+5,y);
    printf("   \\      /");  
    gotoxy(x+6,y); 
    printf("    \\____/");
    gotoxy(x+7,y);
    printf("     //\\\\"); 
    gotoxy(x+8,y);       
    printf("    //__\\\\");
    gotoxy(x+9,y);       
    printf("   //____\\\\");
    gotoxy(x+10,y);        
    printf("  //      \\\\");
    gotoxy(x+11,y);     
    printf(" //________\\\\\n");    
}


int main(int argc, char *argv[]) {

    // Définition des différentes parties de la vache et des éléments de l'affichage
    char *eye = "00";
    char *po= ".." ;
    char *clin = "0.";
    char *marche_avant = "\\\\";
    char *marche_avant2 = " \\\\";
    char *avant = "\\" ;
    char *marche_arriere = "//";
    char *marche_arriere2 = " //";
    char *arriere = "/" ;
    char *deb = "|";
    char *debout = "||";
    char *debout2 = " ||";
    int y = 8;
    char *bulle = "\\";
    char *vide = " ";
    char *texte = "Bonjour";
    char *langue = "U";
    char *texte1 = "Je suis la vache acrobatique";
    char *texte2 = "Je vais vous montrer ce que je sais faire";
    char *texte3 = "Mais avant, je vais m'échauffer";
    char *texte4 = "Ok c'est parti" ;
    char *texte5 = "Taddaaa";

    // Boucle pour l'animation de la vache se préparant et du texte affiché
    for (int i = 0; i < 28; i++) {
        update();
        if (i<7)
            affichage(texte);
        if (i>=7 && i<14)
            affichage(texte1);
        if (i>=14 && i<21)
            affichage(texte2);
        if (i>=21)
            affichage(texte3);
        if ((i%4)!=0)
            affiche_vache_droite(eye, debout, debout2, deb, bulle, langue, 12, 8);
        else 
            affiche_vache_droite(po, debout, debout2, deb, bulle, vide, 12, 8);
        usleep(300000) ;
    }
    
    // Animation de la vache se déplaçant vers la droite
    int u = 12;
    for (int i=1; i<=59; i++){
        update();
        if ((i%2)!=0)
            affiche_vache_gauche(eye, debout, debout, deb, u, y);
        else 
            affiche_vache_gauche(eye, marche_avant, marche_avant2, avant, u, y);
        usleep(80000) ;
        y++;
    }
    // Animation de la vache se déplaçant vers la gauche
    for (int i=1; i<=52; i++){
        update();
        if ((i%2)!=0)
            affiche_vache_droite(eye, debout, debout2, deb, vide, vide, u, y);
        else 
            affiche_vache_droite(eye, marche_arriere, marche_arriere, arriere, vide, vide, u, y);
        usleep(80000) ;
        y--;
    }
    // Préparation de l'affichage du texte et de la vache avant le début de l'acrobatie
    int z=8;
    update();
    affichage(texte4);
    affiche_vache_droite(eye, debout, debout2, deb, bulle, vide, 12, z);
    sleep(2);
    update();
    vache_prepare(12, 8);
    barriere(5, 50);
    sleep(3);
    // Animation de la vache sautant par-dessus la barrière
    for (int a=0; a<=23; a++){
        update();
        barriere(5, 50);
        if ((a%2)!=0)
            affiche_vache_gauche(eye, debout, debout2, deb, 12, z);
        else 
            affiche_vache_gauche(eye, marche_avant, marche_avant2, avant, 12, z);
        usleep(80000) ;
        z++;
    }
    // Animation de la vache qui saute
    int b = 12;
    for (int a=0; a<=5; a++){
        update();
        barriere(5, 50);
        affiche_vache_gauche(eye, marche_arriere, marche_arriere, arriere, b, z);
        usleep(70000) ;
        z++;
        b--;
    }
    // Animation de la vache avancant après avoir sauté
    for (int a=0; a<=18; a++){
        update();
        barriere(5, 50);
        affiche_vache_gauche(eye, debout, debout, deb, b, z);
        usleep(20000) ;
        z++;
    }
    // Animation de la vache qui retombe apres avoir sauté
    for (int a=0; a<=6; a++){
        update();
        barriere(5, 50);
        affiche_vache_gauche(eye, marche_avant, marche_avant2, avant, b, z);
        usleep(70000) ;
        z++;
        b++;
    }
    // Animation de la vache qui court
    for (int a=0; a<=23; a++){
        update();
        barriere(5, 50);
        if ((a%2)!=0)
            affiche_vache_gauche(eye, debout, debout, deb, 12, z);
        else 
            affiche_vache_gauche(eye, marche_avant, marche_avant2, avant, 12, z);
        usleep(80000) ;
        z++;
    }
 
    // Animation de la vache qui repete les memes actions mais dans le chemin inverse

    b--;
    for (int a=0; a<=25; a++){
        update();
        barriere(5, 50);
        if ((a%2)!=0)
            affiche_vache_droite(eye, debout, debout2, deb, vide, vide, b, z);
        else 
            affiche_vache_droite(eye, marche_arriere, marche_arriere, arriere, vide, vide, b, z);
        usleep(80000) ;
        z--;
    }
    for (int a=0; a<=5; a++){
        update();
        barriere(5, 50);
        affiche_vache_droite(eye, marche_avant, marche_avant2, avant, vide, vide, b, z);
        usleep(70000) ;
        z--;
        b--;
    }
    for (int a=0; a<=17; a++){
        update();
        barriere(5, 50);
        affiche_vache_droite(eye, debout, debout2, deb, vide, vide, b, z);
        usleep(20000) ;
        z--;
    }
    for (int a=0; a<=6; a++){
        update();
        barriere(5, 50);
        affiche_vache_droite(eye, marche_arriere, marche_arriere, arriere, vide, vide, b, z);
        usleep(70000) ;
        z--;
        b++;
    }
    
    for (int a=0; a<=23; a++){
        update();
        barriere(5, 50);
        if ((a%2)!=0)
            affiche_vache_droite(eye, debout, debout2, deb, vide, vide, 12, z);
        else 
            affiche_vache_droite(eye, marche_arriere, marche_arriere2, arriere, vide, vide, 12, z);
        usleep(80000) ;
        z--;
    }
    //  Vache qui affiche un message apres avoir réaliser l'acrobatie
    update();
    affichage(texte5);
    barriere(5, 50);
    affiche_vache_droite(clin, debout, debout2, deb, bulle, langue, 12, z);
}
