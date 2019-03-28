/*
 * Benoit Pierrehumbert
 * Bataille Navale
 * 25.03.2019
 * En cours: affichage donnée grille
 */


#include <stdio.h>
#include <windows.h>
#include <conio.h>


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


#define cote 10
int datagrille[10][10] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

};

int menu() {
    int resmenu = 0;
    resmenu = resmenu + 2;
    printf("1. Aide\n"
           "2. Jouer\n"
           "9.Quitter\n");
    resmenu=_getch();
    return resmenu;
}

int affgrille(int hauteur, int largeur) {
    switch (datagrille[hauteur - 1][largeur - 1]) {
        case 0:
            printf(" "); //cas standard
            break;
        case 1:
            printf("X"); // touché
            break;
        case 2:
            printf("O"); //a lo
            break;
        case 3:
            printf("%c", SC);
            break;
    }
}

void top(int cotes) {
    SetConsoleOutputCP(437); // For semi-graphic characters
    printf("\n");
    printf("   %c", STLC);
    for (int i = 0; i <= cotes - 2; i++) {
        printf("%c%c%c%c", SHSB, SHSB, SHSB, SHTB);
    }
    printf("%c%c%c%c", SHSB, SHSB, SHSB, STRC);
}                          // ┌───┬───┐

int mid(int cotes, int i, int ligne) {
    int a = 1;
    if (i <= 9) {
        printf("\n %d %c", i, SVSB);
    } else if (i == 10) {
        printf("\n%d %c", i, SVSB);
    }
    for (int i = -1; i <= cotes - 3; i++) {
        printf(" ");
        affgrille(ligne, a);
        printf(" %c", SVSB);
        a++;
    }
    printf(" ");
    affgrille(ligne, a);
    printf(" %c", SVSB);

}         // │   │   │

void midmid(int cotes) {
    printf("\n   %c", SVLB);
    for (int i = 0; i <= cotes - 2; i++) {
        printf("%c%c%c%c", SHSB, SHSB, SHSB, SC);
    }
    printf("%c%c%c%c", SHSB, SHSB, SHSB, SVRB);
}                       // ├───┼───┤

void bootom(int cotes) {
    printf("\n   %c", SBLC);
    for (int i = 0; i <= cotes - 2; i++) {
        printf("%c%c%c%c", SHSB, SHSB, SHSB, SHBB);
    }
    printf("%c%c%c%c", SHSB, SHSB, SHSB, SBRC);
}                       // └───┴───┘

void grille(int Cotes) {
    printf("     A   B   C   D   E   F   G   H   I   J");
    top(Cotes);///OK
    int j;
    int k = 0;
    for (j = 1; j < Cotes; j++) {
        mid(Cotes, j, j);    ///OK
        midmid(Cotes); ///OK
        k = j;
    }

    mid(Cotes, j, k+1);///OK
    bootom(Cotes); ///OK
    printf("\n");
}

void jouer(){
    grille(cote);
    int lettre=0;
    int num=0;
    printf("Où voulez-vous tirer ?\n");
    printf("Le numéro de la ligne SVP.");
    scanf("%d",&num);
    printf("La lettre de la colone SVP.");
    lettre=_getch();/// A=97


}


int Aide() {
    SetConsoleOutputCP(65001);
    printf("Bonjours je suis l'aide de ce jeu.\n");
    printf("Vous aller jouer à la bataille navale. \n"
           "Vous avez demandé l’aide.\n"
           "Les règles sont assez simple : Pour commencer poser vos bateaux en disant au programme les case exemple pour un bateau à 2 cases.\n"
           "Il faut dire au programme A1 et appuyer sur entrer puis taper B1 et appuyer sur entrer. Si vous n’avez pas mis un nombre correct de case à votre bateau (2,3,4) vous ne pourrez pas placer le suivant.\n"
           "Pour tirer veuillez avoir posé vos 9 « bout » de bateau. Une fois ceci fait dite au programme une case tell : C5 et faite entrer.\n"
           "Une fois que vous voyez s’afficher : Touché c’est que vous avez touché un bateau, chercher alors autour pour pouvoir lui faire sa fête.\n"
           "Une fois tous les bateaux couler vous avez gagné.\n");

}

int main() {
    int omenu=0;//option menu
    omenu=menu();
    int quitter=-1;
    switch (omenu) {
            case 49:
                Aide();
            case 50:
                jouer();

            case 57:
                printf("Voulez-vous vraimment quitter?"
                       "\n0=Oui, 1=Non");
                scanf("%d", &quitter);
                if (quitter == 0) {
                    return 0;
                } else if (quitter == 1) {
                    menu();
                }

        }

    SetConsoleOutputCP(65001);
    int aide = 0;
    int Qmenu = 9;
    printf("Bonjour, voulez-vous afficher l'aide ?\n");
    do {
        printf("0 = OUI, 1 = NON");
        scanf("%d", &aide);

        if (aide != 1 && aide != 0) {//si pas un ou deux redemande
            system("cls");
            printf("Ce n'est pas une réponse valable...\n");
        }
    } while (aide != 1 && aide != 0);

    if (aide == 0) {//Affiche l'aide via une fonction
        system("cls");
        Aide();
        system("pause");
        menu();
    } else if (aide == 1) {
        system("cls");
        printf("D'accord vous savez joué.\n"); //sort de l'aide et charge le menu
    }


    return 0;
}

