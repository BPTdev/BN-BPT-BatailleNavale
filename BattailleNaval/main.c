/*
 * Benoit Pierrehumbert
 * Bataille Navale
 * 07.03.2019
 * En cours: affichage aide
 */
#include <stdio.h>
#include <windows.h>
#pragma execution_character_set( "utf-8")

int menu() {
    int resmenu;
    printf("MENU lol");
    scanf("%d", &resmenu);
    return resmenu;
}

void Aide() {
    SetConsoleOutputCP(65001);
    printf("Bonjours je suis l'aide de ce jeu.\n");
    printf("Vous aller jouer à la bataille navale. \n"
           "Vous avez demandé l’aide.\n"
           "Les règles sont assez simple : Pour commencer poser vos bateaux en disant au programme les case exemple pour un bateau à 2 cases.\n"
           "Il faut dire au programme A1 et appuyer sur entrer puis taper B1 et appuyer sur entrer. Si vous n’avez pas mis un nombre correct de case à votre bateau (2,3,4) vous ne pourrez pas placer le suivant.\n"
           "Pour tirer veuillez avoir posé vos 9 « bout » de bateau. Une fois ceci fait dite au programme une case tell : C5 et faite entrer.\n"
           "Une fois que vous voyez s’afficher : Touché c’est que vous avez touché un bateau, chercher alors autour pour pouvoir lui faire sa fête.\n"
           "Une fois tous les bateaux couler vous avez gagné.");

}

int main() {
    SetConsoleOutputCP(65001);
    int aide = 0;
    int Qmenu;
    printf("Bonjours, voulez-vous afficher l'aide ?\n");
    do {
        printf("0 = oui, 1 = non");
        scanf("%d", &aide);
        if (aide != 1 && aide != 0){//si pas un ou deux redemande
            printf("Ce n'est pas une réponse valable...\n");
        }
    } while (aide != 1 && aide != 0);

    if (aide == 0) {//Affiche l'aide via une fonction
        Aide();
    } else if (aide == 1) {
        Qmenu = 1;
        printf("D'accord vous savez jouer."); //sort de l'aide et charge le menu
        return Qmenu;
    }
    if (Qmenu == 1) {//Affiche le menu
        menu;
    }
    return 0;
}