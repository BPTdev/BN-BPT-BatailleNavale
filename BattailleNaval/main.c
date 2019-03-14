/*
 * Benoit Pierrehumbert
 * Bataille Navale
 * 14.03.2019
 * En cours: affichage aide
 */


#include <stdio.h>
#include <windows.h>


#pragma execution_character_set("utf-8")
#define STLC 218 // ┌, Single Top Left Corner
#define STRC 191 // ┐, Single Top Right Corner
#define SBLC 192 // └, Single Bottom Left Corner
#define SBRC 217 // ┘, Single Bottom Right Corner
#define SVSB 179 // │, Single Vertical Simple Border
#define SVRB 180 // ┤, Single Vertical Right Border
#define SVLB 195 // ├, Single Vertical Left Border
#define SHSB 196 // ─, Single Horizontal Simple Border
#define SHBB 193 // ┴, Single Horizontal Bottom Border
#define SHTB 194 // ┬, Single Horizontal Top Border
#define SC   197 // ┼, Single Center


#define cote 8

int menu() {
    int resmenu;
    printf("MENU lol");
    scanf("%d", &resmenu);
    return resmenu;
}

void lettre(){
    for (int i=0;i<cote;i++){
        int nb;
        nb=i+49;
        printf(" %c  ",nb);
    }
}

void top() {
    SetConsoleOutputCP(437); // For semi-graphic characters

    printf("%c", STLC);
    for (int i = 0; i <= cote - 2; i++) {
        printf("%c%c%c%c", SHSB, SHSB, SHSB, SHTB);
    }
    printf("%c%c%c%c", SHSB, SHSB, SHSB, STRC);
}

void mid() {
    printf("\n%c", SVSB);
    for (int i = 0; i <= cote - 2; i++) {
        printf("   %c", SVSB);
    }
    printf("   %c", SVSB);
}

void midmid() {
    printf("\n%c", SVLB);
    for (int i = 0; i <= cote - 2; i++) {
        printf("%c%c%c%c", SHSB, SHSB, SHSB, SC);
    }
    printf("%c%c%c%c", SHSB, SHSB, SHSB, SVRB);
}

void bootom(){
    printf("\n%c", SBLC);
    for (int i = 0; i <= cote - 2; i++) {
        printf("%c%c%c%c", SHSB, SHSB, SHSB, SHBB);
    }
    printf("%c%c%c%c", SHSB, SHSB, SHSB, SBRC);
}

void grille() {
    top();    ///OK
    for (int i=0;i<=cote;i++) {
        mid();    ///OK
        midmid(); ///OK
    }
    mid();///OK
    bootom(); ///OK

}

void Aide() {
    SetConsoleOutputCP(65001);
    grille();
    printf("Bonjours je suis l'aide de ce jeu.\n");
    printf("Vous aller jouer à la bataille navale. \n"
           "Vous avez demandé l’aide.\n"
           "Les règles sont assez simple : Pour commencer poser vos bateaux en disant au programme les case exemple pour un bateau à 2 cases.\n"
           "Il faut dire au programme A1 et appuyer sur entrer puis taper B1 et appuyer sur entrer. Si vous n’avez pas mis un nombre correct de case à votre bateau (2,3,4) vous ne pourrez pas placer le suivant.\n"
           "Pour tirer veuillez avoir posé vos 9 « bout » de bateau. Une fois ceci fait dite au programme une case tell : C5 et faite entrer.\n"
           "Une fois que vous voyez s’afficher : Touché c’est que vous avez touché un bateau, chercher alors autour pour pouvoir lui faire sa fête.\n"
           "Une fois tous les bateaux couler vous avez gagné.\n");
    printf("Voulez vous afficher le menu ? (0 = oui / 1 = non)");
}

int main() {
    SetConsoleOutputCP(65001);
    int aide = 0;
    int Qmenu = 9;
    printf("Bonjours, voulez-vous afficher l'aide ?\n");
    do {
        printf("0 = oui, 1 = non");
        scanf("%d", &aide);
        if (aide != 1 && aide != 0) {//si pas un ou deux redemande
            printf("Ce n'est pas une réponse valable...\n");
        }
    } while (aide != 1 && aide != 0);

    if (aide == 0) {//Affiche l'aide via une fonction
        Aide();
        scanf("%d", &Qmenu);
    } else if (aide == 1) {
        printf("D'accord vous savez joué.\n"); //sort de l'aide et charge le menu


    }
    if (Qmenu == 1) {

    }

    return 0;
}