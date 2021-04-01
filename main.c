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
#include <string.h>
#include <time.h>

#define VALEUR_Z 90
#define ESPACE 32

const int grille[10][10] = {
        {0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 5, 0},
        {0, 4, 4, 4, 4, 0, 0, 0, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 5, 0},
        {0, 0, 0, 0, 0, 0, 2, 0, 5, 0},
        {0, 0, 0, 0, 0, 0, 2, 0, 0, 0},
        {0, 3, 3, 3, 0, 0, 2, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

//utilisé pour garder en compte le score du joueur pendant qu'il joue
int scoreJeux = 0;
char nom[3];

/**
 * éfface tout ce qui est sur l'écran
 */
void effacerEcran()
{
    system("cls");
}

/**
 * mets en pause le programme
 */
void pause()
{
    system("pause");
}

void afficherLegende(int nombreDuChoix)
{
    switch (nombreDuChoix)
    {
        //L'écran de l'aide
        case 2:
            //faire 48 espace avant d'écrire le titre
            printf("\n\n%47cAide\n\n",ESPACE);
            //faire que la moitié des "-" ce trouve au milieu du titre
            for (int i = 0; i < 98; ++i)
            {
                printf("-");
            }
            break;
        case 3:
            //faire 48 espace avant d'écrire le titre
            printf("\n\n%47cScore\n\n",ESPACE);
            //faire que la moitié des "-" ce trouve au milieu du titre
            for (int i = 0; i < 98; ++i)
            {
                printf("-");
            }
            break;
        case 4:
            //faire 44 espace avant d'écrire le titre
            printf("\n\n%43cAuthentification\n\n",ESPACE);
            //faire que la moitié des "-" ce trouve au milieu du titre
            for (int i = 0; i < 98; ++i)
            {
                printf("-");
            }
            break;
        default:
            //faire 45 espace avant d'écrire le titre
            printf("\n\n%44cBataille Navale\n\n",ESPACE);
            //faire que la moitié des "-" ce trouve au milieu du titre
            for (int i = 0; i < 98; ++i)
            {
                printf("-");
            }
    }

}
/**
 * Le menu principale du jeu
 */
void menu()
{
    afficherLegende(0);
    printf("\n\nJouer: 1\n");
    printf("Aide: 2\n");
    printf("Score: 3\n");
    printf("Authentification: 4\n");
    printf("Quiter: 5\n\n");
}

/**
 * récupère la date exacte quand cette fonction est appeler
 */
void date()
{
    //time_t est un type de variable
    time_t t = time(NULL);
    //on assotie la structure de localtime dans la variable t
    struct tm tm = *localtime(&t);
    printf("now: %d.%02d.%02d %02d:%02d\n",  tm.tm_mday, tm.tm_mon + 1,tm.tm_year + 1900, tm.tm_hour, tm.tm_min);
}

/**
 * enregistre dans un fichier les évènement important qui ce sont passer pendant l'éxécution du programme
 */
void enregistrementDesLogs()
{
    char dataDuLog[50];
    FILE *logs;
    logs = fopen("BD/logs.txt","a");

    if (logs == NULL)
    {
        printf("\nUne erreur est survenue lors de l'ouverture du fichier\n");
        pause();
    }

}

/**
 * prend un fichier et l'inscrit dans une varialbe
 */
int recupereGrille()
{
    int grille[10][10];
    FILE * fp;
    fp = fopen("BD/Grille/1.txt", "r");

    if (fp == NULL)
    {
        printf("\nUne erreur est survenue lors de l'ouverture du fichier\n");
        pause();
        return NULL;
    }
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            fscanf(fp,"%d",&grille[i][j]);
        }
    }
    fclose(fp);
    return grille[10][10];
}

/**
 * enregistrement du score d'un utilisateur dans un fichier
 */
void enregistrementScore()
{
    char dataDuScore[150];
    FILE * fp;
    fp = fopen("BD/score.txt", "a");
    //assossie le texte avec le nombre du score
    sprintf(dataDuScore,"\n%27s%50c%d",nom,ESPACE,scoreJeux);
    //affiche une erreur si le fichier n'a pas été touvé
    if (fp == NULL)
    {
        printf("\nUne erreur est survenue lors de l'ouverture du fichier\n");
        pause();
        return;
    }
    //ajoute la donnée dans le fichier
    fputs(dataDuScore,fp);
    fclose(fp);
}

/**
 * Affiche l'écran du score sans les scores
 */
void affichageEcranScore()
{
    afficherLegende(3);
    printf("\n%24cNom:%49cScore:\n\n",ESPACE,ESPACE);
}

/**
 * demande à l'utilisateur de s'authentifier
 */
void ecranDemandeDauthentification()
{
    afficherLegende(4);
    printf("\n\nVeuiller vous authentifier avant de commencer une partie.");
    pause();
}

/**
 * Affiche le score des joueurs
 * @param lettre
 */
void affichageScore(char lettre)
{
    printf("%c",lettre);
}

/**
 * verifie si les conditions pour le nom est correcte
 * @return
 */
int verificationAuthentification()
{
    while (strlen(nom) != 3)
    {
        effacerEcran();
        afficherLegende(4);
        printf("\n\nLe nom d'utilisateur doit être exactement 3 character\n");
        pause();
        return 0;
    }
    return 1;
}
/**
 * enregistre le nom de l'utilisateur
 */
int nomAuthentification()
{
    scanf("%s",&nom);
    fflush(stdin);
    return verificationAuthentification();
}
/**
 * affiche le menu de l'authentification
 */
void authentification()
{
    int valide;
    while (valide != 1)
    {
        effacerEcran();
        afficherLegende(4);
        printf("\n%24cNom:%49c",ESPACE,ESPACE);
        valide = nomAuthentification();
    }
}

/**
 * lis un fichier qui à des scores enregister à l'intérieurs et les affiches avec l'utilisateur qui a fait le score
 */
 void score()
 {
     effacerEcran();
     char lettre;
     FILE *fp;
     //mode l'écture
     fp = fopen("BD/score.txt", "r");

     if (fp == NULL)
     {
         printf("Une erreur est survenue lors de l'ouverture du fichier\n");
         pause();
         return;
     }
     affichageEcranScore();
     do
     {
         lettre = fgetc(fp);
         affichageScore(lettre);
     }while (lettre != EOF);

     printf("\n");
     fclose(fp);
     pause();
 }

/**
 * affiche l'écran de victoire
 */
void affichageGagner()
{
    effacerEcran();
    printf("Vous avez gagner !!!!!!!!!\n\n\n");
    printf("Score total: %d\n\n",scoreJeux);
    enregistrementScore();
    pause();
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
    //si tout les compteurs de bateaux sont égales a la valeur correcte, ça veux dire que tout les bateaux ont été coulé
    if (bateau_1 == 2 && bateau_2 == 3 && bateau_3 == 3 && bateau_4 == 4 && bateau_5 == 5)
    {
        //cette valeur est utilisé si le joueur a gagner
        aireDeJeux[9][9] = 100;
    }
    return aireDeJeux;
}

/**
 * vérifie si le joueur a toucher un bateau ou non
 * @param coordonneeX
 * @param coordonneeY
 * @param aireDeJeux
 * @return
 */
int bateauToucher(char coordonneeX,int coordonneeY,int aireDeJeux[10][10])
{
    if (grille[coordonneeY-1][coordonneeX-1] > 0)
    {
        aireDeJeux[coordonneeY-1][coordonneeX-1] = 2;
        aireDeJeux[10][10] = conditionGagner(aireDeJeux);
        scoreJeux = scoreJeux + 100;
        printf("\n\nToucher ^^\n");
        pause();
    }
    else
    {
        aireDeJeux[coordonneeY-1][coordonneeX-1] = 1;
        scoreJeux = scoreJeux - 10;
        printf("\n\nPlouf ^^\n");
        pause();
    }
    return aireDeJeux;
}

/**
 * vérifie si les coordonnées sont valide et si elle touche un bateau
 * @param coordonneeX
 * @param coordonneeY
 * @return
 */
int verificationDesCoordonnees(char coordonneeX,int coordonneeY,int aireDeJeux[10][10])
{
    if (coordonneeX < 1 || coordonneeX > 10 || coordonneeY < 1 ||coordonneeY >10)
    {
        printf("\n\nCes coordonnée ne sont pas valide\n");
        pause();
    }
    else if (aireDeJeux[coordonneeY - 1][coordonneeX - 1] != 0)
    {
        printf("\n\nCette case à déjà été touché\n");
        pause();
    }
    else
    {
        //int grille[][] = recupereGrille();
        //if (grille == NULL)
        //{
        //    return;
        //}
        aireDeJeux[10][10] = bateauToucher(coordonneeX,coordonneeY,aireDeJeux);
    }
    return aireDeJeux;
}

/**
 * affichage des légendes sur la grille
 */
void legende()
{
    printf("\n\n▓ == Touché\n\n");
    printf("░ == à l'eau\n\n");
    date();
    printf("Coordonnée Z:0 == quitter\n\n");
}

/**
 * prends la coordonnée X de l'utilisateur
 */
char entreeCoordonneeX()
{
    int coordonneeX;
    printf("\n\nPremière coordonnée (A-J) : ");
    fflush(stdin);
    scanf("%c", &coordonneeX);
    return coordonneeX;
}

/**
 * prends la coordonnée Y de l'utilisateur
 */
int entreeCoordonneeY()
{
    int coordonneeY;
    printf("\nDeuxième coordonnée (1-10) : ");
    fflush(stdin);
    scanf("%d", &coordonneeY);
    return coordonneeY;
}

/**
 * affiche la grille pour la bataille navale
 */
void grilleBatailleNavale() {
    //déclaration de variable
    char coordonneeX;
    int coordonneeY;
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
    //rénitialise le score au début d'une nouvelle partie
    scoreJeux = 0;
    //continue en boucle la bataille navale jusqu'à ce que le joueur a touché tout les bateaux
    do
    {
        effacerEcran();
        recupereGrille();
        afficherLegende(0);
        //Légende
        legende();
        for (int legende = 0; legende < 10; ++legende)
        {
            printf("   %c  ",65 + legende);
        }
        //commencement de la grille
        printf("\n\n╔");
        for (int premiereLigne = 0; premiereLigne < 10; ++premiereLigne)
        {
            for (int i = 0; i < 5; ++i)
            {
                printf("═");
            }
            if (premiereLigne != 9)
            {
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
                    else if (v == 11 && i%2 == 0)
                    {
                        printf("║  %d",ligneMilieux);
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

        coordonneeX = entreeCoordonneeX();
        coordonneeY = entreeCoordonneeY();

        if (coordonneeX == VALEUR_Z && coordonneeY == 0)
        {
            return;
        }
        //On soustrait par 65 car la valeur de A est de 65 en numérique
        coordonneeX = coordonneeX - 64;
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
    effacerEcran();
    afficherLegende(2);
    printf("\n\nLe but du jeux est de coulé tout les bateaux sur la grille.\n\n");
    printf("Mettez les coordonnées x et y pour envoyé un missile sur cette case.\n\n");
    printf("vous saurez si vous avez touché un bateau par un symbol, ▓ si le missile a touché un bateau et ░ si il a loupé.\n\n");
    printf("Utiliser le moin de missile au total pour avoir le plus de point.\n\n\n\n\n\n");
    pause();
}

void changementDesMenus(int choix)
{
    switch (choix)
    {
        case 1:
            //Si le joueur c'est authentifier, il peux commencer une partie, sinon il ne peux pas
            if (nom == NULL)
            {
                ecranDemandeDauthentification();
            }
            else
            {
                //Affiche la grille pour la bataille navale et éxecute les autres fonctions pour la bataille navale
                grilleBatailleNavale();
            }
            break;
        case 2:
            affichageDaide();
            break;
        case 3:
            score();
            break;
        case 4:
            authentification();
            break;
        case 5:
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
        //efface
        effacerEcran();
        //affichage du menu
        menu();
        //demande le choix de l'utilisateur
        choix = demandeDuChoix(choix);
        //change d'écran selon le choix de l'utilisateur
        changementDesMenus(choix);
    }
    while (choix != 5);
    return 0;
}