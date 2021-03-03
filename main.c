/**
 * Auteur: Arthur Bottemanne
 * Projet: Bataille Navale
 * Date: 19.02.21
 * Version: 0.1v
 *
                    ()
                    ||q',,'
                    ||d,~
         (,---------------------,)
          ',       q888p       ,'
            \       986       /
             \  8p, d8b ,q8  /
              ) 888a888a888 (
             /  8b` q8p `d8  \              O
            /       689       \             |','
           /       d888b       \      (,---------,)
         ,'_____________________',     \   ,8,   /
         (`__________L|_________`)      ) a888a (    _,_
         [___________|___________]     /___`8`___\   }*{
           }:::|:::::}::|::::::{      (,=========,)  -=-
            '|::::}::|:::::{:|'  .,.    \:::|:::/    ~`~=
 --=~(@)~=-- '|}:::::|::{:::|'          ~".,."~`~
               '|:}::|::::|'~`~".,."
           ~`~".,."~`~".,                 "~`~".,."~
                          ".,."~`~
 */
#include <stdio.h>
#include <stdlib.h>
/**
 * Le menu principale du jeu
 */

#define GRILLES {{0, 0, 0, 0, 0, 0, 0, 0}, \
                {0, 0, 0, 0, 0, 0, 0, 0},  \
                {0, 0, 0, 0, 0, 0, 0, 0},  \
                {0, 0, 0, 0, 0, 0, 0, 0},  \
                {0, 0, 0, 0, 0, 0, 0, 0},  \
                {0, 0, 0, 0, 0, 0, 0, 0},  \
                {0, 0, 0, 0, 0, 0, 0, 0},  \
                {0, 0, 0, 0, 0, 0, 0, 0}}
void menu()
{
    printf("================================== ~~~~~  Bataille Navale  ~~~~~ ==================================\n\n                    ()\n"
           "                    ||q',,'\n"
           "                    ||d,~\n"
           "         (,---------------------,)\n"
           "          ',       q888p       ,'\n"
           "            \\       986       /\n"
           "             \\  8p, d8b ,q8  /\n"
           "              ) 888a888a888 (\n"
           "             /  8b` q8p `d8  \\              O\n"
           "            /       689       \\             |','\n"
           "           /       d888b       \\      (,---------,)\n"
           "         ,'_____________________',     \\   ,8,   /\n"
           "         (`__________L|_________`)      ) a888a (    _,_\n"
           "         [___________|___________]     /___`8`___\\   }*{\n"
           "           }:::|:::::}::|::::::{      (,=========,)  -=-\n"
           "            '|::::}::|:::::{:|'  .,.    \\:::|:::/    ~`~=\n"
           " --=~(@)~=-- '|}:::::|::{:::|'          ~\".,.\"~`~\n"
           "               '|:}::|::::|'~`~\".,.\"\n"
           "           ~`~\".,.\"~`~\".,                 \"~`~\".,.\"~\n"
           "                          \".,.\"~`~\n\n");
    printf("---- 1: Jouer\n\n");
    printf("---- 2: Aide\n\n");
    printf("---- 3: Quiter\n\n");
}

void jeuxBatailleNavale()
{
    system("cls");
    printf("\nBataille Navale\n");
    system("pause");
}

void affichageDaide()
{
    system("cls");
    printf("================================== ~~~~~  Aide du jeux  ~~~~~ ==================================\n\n");
}

void changementDesMenus(int choix)
{
    switch (choix)
    {
        case 1:
            jeuxBatailleNavale();
            break;
        case 2:
            affichageDaide();
            break;
        case 3:
            return;
    }
}

int main(void)
{
    int choix;

    //prendant que l'utilisateur ne choisi pas l'option "quiter" le programme continue
    do
    {
        system("cls");
        menu();
        scanf("%d", &choix);
        changementDesMenus(choix);
    }
    while (choix != 3);
    return 0;
}