/*
 * Benoit Pierrehumbert
 * Bataille Navale
 * 07.03.2019
 * En cours: affichage aide
 */
#include <stdio.h>
#include <windows.h>

#pragma execution_character_set( "utf-8")
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


int menu() {
    int resmenu;
    printf("MENU lol");
    scanf("%d", &resmenu);
    return resmenu;
}

void Aide(){
    SetConsoleOutputCP(65001);
    printf("Bonjours je suis l'aide de ce jeu.\n");
    printf("Vous aller jouer à la bataille navale. \n"
           "Vous avez demandé l’aide.\n"
           "Les règles sont assez simple : Pour commencer poser vos bateaux en disant au programme les case exemple pour un bateau à 2 cases.\n"
           "Il faut dire au programme A1 et appuyer sur entrer puis taper B1 et appuyer sur entrer. Si vous n’avez pas mis un nombre correct de case à votre bateau (2,3,4) vous ne pourrez pas placer le suivant.\n"
           "Pour tirer veuillez avoir posé vos 9 « bout » de bateau. Une fois ceci fait dite au programme une case tell : C5 et faite entrer.\n"
           "Une fois que vous voyez s’afficher : Touché c’est que vous avez touché un bateau, chercher alors autour pour pouvoir lui faire sa fête.\n"
           "Une fois tous les bateaux couler vous avez gagné.");
    printf("Voulez vous afficher le menu ? (0 = oui / 1 = non)");
}


void grille() {
    SetConsoleOutputCP(437); // For semi-graphic characters
    printf("%c%c%c%c%c%c%c%c%c\n", STLC, SHSB, SHSB, SHSB, SHTB, SHSB, SHSB, SHSB, STRC);
    printf("%c   %c   %c\n", SVSB, SVSB, SVSB);
    printf("%c%c%c%c%c%c%c%c%c\n", SVLB, SHSB, SHSB, SHSB, SC, SHSB, SHSB, SHSB, SVRB);
    printf("%c   %c   %c\n", SVSB, SVSB, SVSB);
    printf("%c%c%c%c%c%c%c%c%c\n", SBLC, SHSB, SHSB, SHSB, SHBB, SHSB, SHSB, SHSB, SBRC);
}

int main() {
    SetConsoleOutputCP(65001);
    int aide = 0;
    int Qmenu = 1;
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
        scanf("%d",&Qmenu);
    } else if (aide == 1) {
        printf("D'accord vous savez joué."); //sort de l'aide et charge le menu
        menu;
    }
    if
    return 0;
}