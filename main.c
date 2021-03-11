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
#include <windows.h>

const int grille[10][10] = {{0, 0, 2, 2, 2, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 5, 5, 5, 5, 5, 1, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 3, 3, 3, 0, 0, 0, 0},
                            {0, 4, 4, 4, 4, 0, 0, 0, 0, 0}};
/**
 * Le menu principale du jeu
 */
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

/**
 * affiche l'écran de victoire
 */
void affichageGagner()
{
    system("cls");
    printf("Vous avez gagner !!!!!!!!!\n\n\n");
    system("pause");
}

/**
 * vérifie si un bateau qui a été touché est coulé
 */
int conditionGagner(int aireDeJeux[10][10])
{
    //initialization des variables
    int bateau_1 = 0,
        bateau_2 = 0,
        bateau_3 = 0,
        bateau_4 = 0,
        bateau_5 = 0;

    for (int colonneA = 0; colonneA < 10; ++colonneA)
    {
        for (int colonneB = 0; colonneB < 10; ++colonneB)
        {
            //vérifie si un bateau a été touché et augmente le compteur pour ce bateaux
            if (grille[colonneA][colonneB] > 0 && aireDeJeux[colonneA][colonneB] > 0)
            {
                switch (grille[colonneA][colonneB])
                {
                    case 1:
                        bateau_1++;
                        break;
                    case 2:
                        bateau_2++;
                        break;
                    case 3:
                        bateau_3++;
                        break;
                    case 4:
                        bateau_4++;
                        break;
                    case 5:
                        bateau_5++;
                        break;
                    default:
                        break;
                }
            }
        }
    }
    //si tout les compteurs de bateaux sont égales a la valeur correcte, ça veux dire que tout les bateaux ont été touché
    if (bateau_1 == 2 && bateau_2 == 3 && bateau_3 == 3 && bateau_4 == 4 && bateau_5 == 5)
    {
        //cette valeur est utilisé si le joueur a gagner
        aireDeJeux[9][9] = 100;
    }
    return aireDeJeux;
}

int bateauToucher(int coordonneeX,int coordonneeY,int aireDeJeux[10][10])
{
    if (grille[coordonneeY-1][coordonneeX-1] > 0)
    {
        aireDeJeux[coordonneeY-1][coordonneeX-1] = 2;
        printf("\n\nToucher ^^\n");
        aireDeJeux[10][10] = conditionGagner(aireDeJeux);
        system("pause");
    }
    else
    {
        aireDeJeux[coordonneeY-1][coordonneeX-1] = 1;
        printf("\n\nPlouf ^^\n");
        system("pause");
    }
    return aireDeJeux;
}

/**
 * vérifie si les coordonnées sont valide et si elle touche un bateau
 * @param coordonneeX
 * @param coordonneeY
 * @return
 */
int verificationDesCoordonnees(int coordonneeX,int coordonneeY,int aireDeJeux[10][10])
{
    if (coordonneeX < 1 || coordonneeX > 10 || coordonneeY < 1 ||coordonneeY >10)
    {
        printf("\n\nCes coordonnée ne sont pas valide\n");
        system("pause");
    }
    else if (aireDeJeux[coordonneeY - 1][coordonneeX - 1] != 0)
    {
        printf("\n\nCette case à déjà été touché\n");
        system("pause");
    }
    else
    {
        aireDeJeux[10][10] = bateauToucher(coordonneeX,coordonneeY,aireDeJeux);
    }
    return aireDeJeux;
}

/**
 * affiche la grille pour la bataille navale
 */
void grilleBatailleNavale() {
    //déclaration de variable
    int coordonneeX,
        coordonneeY;
    /**
     * sert a définir ou le joueur a déjà tirer, 0 = pas tirer dessus, 1 = à l'eau, 2 = bateau touché
     */
    int aireDeJeux[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    //continue en boucle la bataille navale jusqu'à ce que le joueur a touché tout les bateaux
    do
    {
    system("cls");
    printf("\nBataille Navale\n\n\n");

    //commencement de la grille
    printf("╔");
    for (int premiereLigne = 0; premiereLigne < 10; ++premiereLigne) {
        for (int i = 0; i < 5; ++i) {
            printf("═");
        }
        if (premiereLigne != 9) {
            printf("╦");
        }
    }
    printf("╗");
    printf("\n");
    //toutes les lignes intermédiaires de la grille
    for (int ligneMilieux = 1; ligneMilieux <= 10; ++ligneMilieux)
    {
        for (int i = 0; i < 2; ++i)
        {
            //pour les bordures de gauche et de droite des cellules
            for (int v = 1; v <= 11; ++v)
            {
                //affiche les cellules qui ont été touché
                if (aireDeJeux[ligneMilieux-1][v-1] > 1 && v != 11)
                {
                    printf("║ ▓▓▓ ");
                }
                else if (aireDeJeux[ligneMilieux-1][v-1] > 0 && v != 11)
                {
                    printf("║ ░░░ ");
                }
                else
                {
                    printf("║     ");
                }
            }
            printf("\n");
        }
        //bordure du bas d'une cellule
        if (ligneMilieux != 10) {
            printf("╠═════");
            for (int v = 0; v < 9; ++v) {
                printf("╬═════");
            }
            printf("╣");
            printf("\n");
        }
    }
    //dernière ligne de la grille
    printf("╚");
    for (int derniereLigne = 0; derniereLigne < 10; ++derniereLigne) {
        for (int i = 0; i < 5; ++i) {
            printf("═");
        }
        if (derniereLigne != 9) {
            printf("╩");
        }
    }
    printf("╝");
    //demande les coordonnées
    printf("\n\nPremière coordonnée : ");
    fflush(stdin);
    scanf("%d", &coordonneeX);
    printf("\nDeuxième coordonnée : ");
    fflush(stdin);
    scanf("%d", &coordonneeY);

    //vérifie les coordonnées si il est valide et/ou si il touche un bateau
    aireDeJeux[10][10] = verificationDesCoordonnees(coordonneeX, coordonneeY, aireDeJeux);
    }
    //condition temporaire pendant que le reste du code soit complémenté
    while (aireDeJeux[9][9] != 100);
    affichageGagner();
}

/**
 * affiche l'aide du jeux
 */
void affichageDaide()
{
    system("cls");
    printf("================================== ~~~~~  Aide du jeux  ~~~~~ ==================================\n\n\n\n");
    printf("\nLe but du jeux est de coulé tout les bateaux sur la grille.\n\n");
    printf("Mettez les coordonnées x et y pour envoyé un missile sur cette case.\n\n");
    printf("vous saurez si vous avez touché un bateau par un symbol, ▓ si le missile a touché un bateau et ░ si il a loupé.\n\n");
    printf("Utiliser le moin de missile au total pour avoir le plus de point.\n\n\n\n\n\n");
    system("pause");
}

void changementDesMenus(int choix)
{
    switch (choix)
    {
        case 1:
            //Affiche la grille pour la bataille navale et éxecute les autres fonctions pour la bataille navale
            grilleBatailleNavale();
            break;
        case 2:
            affichageDaide();
            break;
        case 3:
            return;
    }
}

/**
 * Utilisé pour afficher les accents
 */
void affichagedaccent()
{
    SetConsoleOutputCP(65001);
}

/**
 * éfface tout ce qui est sur l'écran
 */
void resetEcran()
{
    system("cls");
}

/**
 * demande le choix du menu
 * @param choix
 * @return
 */
int demandeDuChoix(int choix)
{
    fflush(stdin);
    scanf("%d", &choix);
    return choix;
}

int main(void)
{
    int choix;
    affichagedaccent();
    //prendant que l'utilisateur ne choisi pas l'option "quiter" le programme continue
    do
    {
        resetEcran();
        //affichage du menu
        menu();
        //demande le choix de l'utilisateur
        choix = demandeDuChoix(choix);
        //change d'écran selon le choix de l'utilisateur
        changementDesMenus(choix);
    }
    while (choix != 3);
    return 0;
}