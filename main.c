/**
 * Auteur: Arthur Bottemanne
 * Projet: Bataille Navale
 * Date: 01.04.2021
 * Version: 1.0v
 */

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <time.h>

#define VALEUR_Z 90
#define ESPACE 32
#define DECALAGE 48

//utilisé pour garder en compte le score du joueur pendant qu'il joue
int scoreJeux = 0;
char nom[3];
char grille[10][10];

/**
 * efface tout ce qui est sur l'écran
 */
void effacerEcran()
{
    system("cls");
}

/**
 * met en pause le programme
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
            //faire 48 espaces avant d'écrire le titre
            printf("\n\n%47cAide\n\n",ESPACE);
            //faire que la moitié des "-" se trouve au milieu du titre
            for (int i = 0; i < 98; ++i)
            {
                printf("-");
            }
            break;
        case 3:
            //faire 48 espaces avant d'écrire le titre
            printf("\n\n%47cScore\n\n",ESPACE);
            //faire que la moitié des "-" se trouve au milieu du titre
            for (int i = 0; i < 98; ++i)
            {
                printf("-");
            }
            break;
        case 4:
            //faire 44 espaces avant d'écrire le titre
            printf("\n\n%43cAuthentification\n\n",ESPACE);
            //faire que la moitié des "-" se trouve au milieu du titre
            for (int i = 0; i < 98; ++i)
            {
                printf("-");
            }
            break;
        default:
            //faire 45 espaces avant d'écrire le titre
            printf("\n\n%44cBataille Navale\n\n",ESPACE);
            //faire que la moitié des "-" se trouve au milieu du titre
            for (int i = 0; i < 98; ++i)
            {
                printf("-");
            }
    }

}
/**
 * Le menu principal du jeu
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
 * récupère la date exacte quand cette fonction est appelée
 */
int date()
{
    //time_t est un type de variable
    time_t t = time(NULL);
    //on associe la structure de localtime dans la variable t
    struct tm tm = *localtime(&t);
    //on met les valeurs de la date dans une table pour pouvoir plus facilement les retourner
    int dateEtHeure[] = {tm.tm_mday, tm.tm_mon + 1,tm.tm_year + 1900, tm.tm_hour, tm.tm_min};
    return (int) dateEtHeure;
}

/**
 * enregistre dans un fichier les évènements importants qui se sont passés pendant l'exécution du programme
 */
void enregistrementDesLogs(int typeDevenement, int argument1, int argument2)
{
    char dataDuLog[150];
    int *dateEtHeure;
    //ouvre le fichier des logs
    FILE *logs;
    logs = fopen("BD/logs.txt","a");
    //affiche une erreur s'il ne trouve pas le fichier
    if (logs == NULL)
    {
        printf("\nUne erreur est survenue lors de l'ouverture du fichier\n");
        pause();
    }
    //insertion des valeurs de date et heure dans la table
    dateEtHeure = (int *) date();
    //il y a deux switch pour une version du log qui a le nom de l'utilisateur et une autre sans l'utilisateur
    if (strlen(nom) == 3)
    {
        switch (typeDevenement)
        {
            //le joueur a commencé une partie
            case 1:
                sprintf(dataDuLog,"%s a commencé une partie le %d.%d.%d %d:%d\n\n",nom, *(dateEtHeure + 0), *(dateEtHeure + 1), *(dateEtHeure + 2), *(dateEtHeure + 3), *(dateEtHeure + 4));
                fputs(dataDuLog,logs);
                break;
            //le joueur a tiré
            case 2:
                sprintf(dataDuLog,"%s a tiré sur %c;%d le %d.%d.%d %d:%d\n\n",nom, argument1, argument2, *(dateEtHeure + 0), *(dateEtHeure + 1), *(dateEtHeure + 2), *(dateEtHeure + 3), *(dateEtHeure + 4));
                fputs(dataDuLog,logs);
                break;
            //le joueur a gagné la partie
            case 3:
                sprintf(dataDuLog,"%s a gagné avec un score de %d le %d.%d.%d %d:%d\n\n",nom, argument1, *(dateEtHeure + 0), *(dateEtHeure + 1), *(dateEtHeure + 2), *(dateEtHeure + 3), *(dateEtHeure + 4));
                fputs(dataDuLog,logs);
                break;
            //appelle la fonction pour l'aide
            case 4:
                sprintf(dataDuLog,"%s a affiché l'aide le %d.%d.%d %d:%d\n\n",nom, *(dateEtHeure + 0), *(dateEtHeure + 1), *(dateEtHeure + 2), *(dateEtHeure + 3), *(dateEtHeure + 4));
                fputs(dataDuLog,logs);
                break;
            //le joueur appelle la fonction score
            case 5:
                sprintf(dataDuLog,"%s a affiché les scores le %d.%d.%d %d:%d\n\n",nom, *(dateEtHeure + 0), *(dateEtHeure + 1), *(dateEtHeure + 2), *(dateEtHeure + 3), *(dateEtHeure + 4));
                fputs(dataDuLog,logs);
                break;
            //le joueur s'est authentifié
            case 6:
                sprintf(dataDuLog,"L'utilisateur s'est nommé %s le %d.%d.%d %d:%d\n\n",nom, *(dateEtHeure + 0), *(dateEtHeure + 1), *(dateEtHeure + 2), *(dateEtHeure + 3), *(dateEtHeure + 4));
                fputs(dataDuLog,logs);
                break;
            //le joueur a quitté le programme
            case 7:
                sprintf(dataDuLog,"%s a fermé le programme le %d.%d.%d %d:%d\n\n",nom, *(dateEtHeure + 0), *(dateEtHeure + 1), *(dateEtHeure + 2), *(dateEtHeure + 3), *(dateEtHeure + 4));
                fputs(dataDuLog,logs);
                break;
            //le joueur a quitté la partie
            case 8:
                sprintf(dataDuLog,"%s a quitté la partie le %d.%d.%d %d:%d\n\n",nom, *(dateEtHeure + 0), *(dateEtHeure + 1), *(dateEtHeure + 2), *(dateEtHeure + 3), *(dateEtHeure + 4));
                fputs(dataDuLog,logs);
                break;
        }
    }
    else
    {
        switch (typeDevenement)
        {
            //le joueur a commencé une partie
            case 1:
                sprintf(dataDuLog,"Anonyme a commencé une partie le %d.%d.%d %d:%d\n\n", *(dateEtHeure + 0), *(dateEtHeure + 1), *(dateEtHeure + 2), *(dateEtHeure + 3), *(dateEtHeure + 4));
                fputs(dataDuLog,logs);
                break;
            //le joueur a tiré
            case 2:
                sprintf(dataDuLog,"Anonyme a tiré sur %d;%d le %d.%d.%d %d:%d\n\n", argument1, argument2, *(dateEtHeure + 0), *(dateEtHeure + 1), *(dateEtHeure + 2), *(dateEtHeure + 3), *(dateEtHeure + 4));
                fputs(dataDuLog,logs);
                break;
            //le joueur a gagné la partie
            case 3:
                sprintf(dataDuLog,"Anonyme a gagné avec un score de %d le %d.%d.%d %d:%d\n\n", argument1, *(dateEtHeure + 0), *(dateEtHeure + 1), *(dateEtHeure + 2), *(dateEtHeure + 3), *(dateEtHeure + 4));
                fputs(dataDuLog,logs);
                break;
            //appelle la fonction pour l'aide
            case 4:
                sprintf(dataDuLog,"Anonyme a affiché l'aide le %d.%d.%d %d:%d\n\n", *(dateEtHeure + 0), *(dateEtHeure + 1), *(dateEtHeure + 2), *(dateEtHeure + 3), *(dateEtHeure + 4));
                fputs(dataDuLog,logs);
                break;
            //le joueur appelle la fonction score
            case 5:
                sprintf(dataDuLog,"Anonyme a affiché les scores le %d.%d.%d %d:%d\n\n", *(dateEtHeure + 0), *(dateEtHeure + 1), *(dateEtHeure + 2), *(dateEtHeure + 3), *(dateEtHeure + 4));
                fputs(dataDuLog,logs);
                break;
            //le joueur a quitté le programme
            case 7:
                sprintf(dataDuLog,"Anonyme a fermé le programme le %d.%d.%d %d:%d\n\n", *(dateEtHeure + 0), *(dateEtHeure + 1), *(dateEtHeure + 2), *(dateEtHeure + 3), *(dateEtHeure + 4));
                fputs(dataDuLog,logs);
                break;
            //le joueur a quitté la partie
            case 8:
                sprintf(dataDuLog,"Anonyme a quitté la partie le %d.%d.%d %d:%d\n\n", *(dateEtHeure + 0), *(dateEtHeure + 1), *(dateEtHeure + 2), *(dateEtHeure + 3), *(dateEtHeure + 4));
                fputs(dataDuLog,logs);
                break;
        }
    }
    fclose(logs);
}

/**
 * prend un fichier et l'inscrit dans une variable
 */
void recupereGrille()
{
    //déclaration et initialisation des variables
    srand(time(NULL));
    int aleatoire = rand() % 5 + 1;
    char cheminDuFichier[50];
    //stocke le chemin d'une grille aléatoire
    sprintf(cheminDuFichier,"BD/Grille/%d.txt",aleatoire);
    FILE * fichierGrille;
    fichierGrille = fopen(cheminDuFichier, "r");
    printf("%s",cheminDuFichier);

    if (fichierGrille == NULL)
    {
        printf("\nUne erreur est survenue lors de l'ouverture du fichier\n");
        pause();
        return;
    }
    fgets((char *) grille, 101, fichierGrille);
    fclose(fichierGrille);
}

/**
 * enregistrement du score d'un utilisateur dans un fichier
 */
void enregistrementScore()
{
    char dataDuScore[150];
    FILE * fp;
    fp = fopen("BD/score.txt", "a");
    //associe le texte avec le nombre du score
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
 * Affiche l'écran du score sans les valeurs des scores
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
    effacerEcran();
    afficherLegende(4);
    printf("\n\nVeuillez vous authentifier avant de commencer une partie.\n\n");
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
 * vérifie si les conditions pour le nom sont correctes
 * @return
 */
int verificationAuthentification()
{
    while (strlen(nom) != 3)
    {
        effacerEcran();
        afficherLegende(4);
        printf("\n\nLe nom d'utilisateur doit contenir exactement 3 caractères\n");
        pause();
        return 0;
    }
    //enregistre cet évènement dans le log
    enregistrementDesLogs(6, (int) NULL, (int) NULL);
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
 * lis un fichier qui a des scores enregistrés à l'intérieur et les affiche avec l'utilisateur qui a fait le score
 */
 void score()
 {
     //enregistre cet évènement dans le log
     enregistrementDesLogs(5, (int) NULL, (int) NULL);
     effacerEcran();
     char lettre;
     FILE *fp;
     //mode lecture
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
void affichageGagne()
{
    //enregistre cette évènement dans le log
    enregistrementDesLogs(3, scoreJeux, (int) NULL);
    effacerEcran();
    printf("Vous avez gagner !!!!!!!!!\n\n\n");
    printf("Score total: %d\n\n",scoreJeux);
    enregistrementScore();
    pause();
}

/**
 * vérifie si les conditions de victoire sont réunis
 */
int conditionGagne(int aireDeJeux[10][10])
{
    //initialisation des variables
    int bateau_1 = 0,
        bateau_2 = 0,
        bateau_3 = 0,
        bateau_4 = 0,
        bateau_5 = 0;

    for (int colonneA = 0; colonneA < 10; ++colonneA)
    {
        for (int colonneB = 0; colonneB < 10; ++colonneB)
        {
            //vérifie si un bateau a été touché et augmente le compteur pour ce bateau
            if (grille[colonneA][colonneB] - DECALAGE > 0 && aireDeJeux[colonneA][colonneB] > 0)
            {
                switch ((grille[colonneA][colonneB]) - DECALAGE)
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
    //si tous les compteurs de bateaux sont égaux à la valeur correcte, cela veut dire que tous les bateaux ont été coulés
    if (bateau_1 == 2 && bateau_2 == 3 && bateau_3 == 3 && bateau_4 == 4 && bateau_5 == 5)
    {
        //cette valeur est utilisée si le joueur a gagné
        aireDeJeux[9][9] = 100;
    }
    return (int) aireDeJeux;
}

/**
 * vérifie si le joueur a touché un bateau ou non
 * @param coordonneeX
 * @param coordonneeY
 * @param aireDeJeux
 * @return
 */
int bateauTouche(char coordonneeX, int coordonneeY, int aireDeJeux[10][10])
{
    if ((grille[coordonneeY-1][coordonneeX-1] - DECALAGE) > 0)
    {
        aireDeJeux[coordonneeY-1][coordonneeX-1] = 2;
        aireDeJeux[10][10] = conditionGagne(aireDeJeux);
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
    return (int) aireDeJeux;
}

/**
 * vérifie si les coordonnées sont valides et si elle touche un bateau
 * @param coordonneeX
 * @param coordonneeY
 * @return
 */
int verificationDesCoordonnees(char coordonneeX,int coordonneeY,int aireDeJeux[10][10])
{
    if (coordonneeX < 1 || coordonneeX > 10 || coordonneeY < 1 ||coordonneeY >10)
    {
        printf("\n\nCes coordonnées ne sont pas valides\n");
        pause();
    }
    else if (aireDeJeux[coordonneeY - 1][coordonneeX - 1] != 0)
    {
        printf("\n\nCette case a déjà été toucher\n");
        pause();
    }
    else
    {
        //enregistre l'évènement du tire dans le log
        enregistrementDesLogs(2,coordonneeX,coordonneeY);
        aireDeJeux[10][10] = bateauTouche(coordonneeX, coordonneeY, aireDeJeux);
    }
    return (int) aireDeJeux;
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
 * prend la coordonnée X de l'utilisateur
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
 * prend la coordonnée Y de l'utilisateur
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
    //déclaration des variables
    char coordonneeX;
    int coordonneeY;
    //enregistre cet évènement dans le log
    enregistrementDesLogs(1, (int) NULL, (int) NULL);
    /**
     * sert à définir où le joueur a déjà tiré, 0 veut dire qu'il n'a pas été tiré dessus, 1 veut dire à l'eau, 2 veut dire bateau touché
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
    //réinitialise le score au début d'une nouvelle partie
    scoreJeux = 0;
    //récupère une grille au hasard, ne pas mettre dans la boucle sinon elle va reprendre une grille aléatoirement à chaque fois
    recupereGrille();
    //continue en boucle la bataille navale jusqu'à ce que le joueur a touché tous les bateaux
    do
    {
        effacerEcran();
        afficherLegende(0);
        //affiche la légende
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
        for (int ligneMilieu = 1; ligneMilieu <= 10; ++ligneMilieu)
        {
            for (int i = 0; i < 2; ++i)
            {
                //pour les bordures de gauche et de droite des cellules
                for (int v = 1; v <= 11; ++v)
                {
                    //affiche les cellules qui ont été touchées
                    if (aireDeJeux[ligneMilieu - 1][v - 1] > 1 && v != 11)
                    {
                        printf("║ ▓▓▓ ");
                    }
                    else if (aireDeJeux[ligneMilieu - 1][v - 1] > 0 && v != 11)
                    {
                        printf("║ ░░░ ");
                    }
                    else if (v == 11 && i%2 == 0)
                    {
                        printf("║  %d", ligneMilieu);
                    }
                    else
                    {
                        printf("║     ");
                    }
                }
                printf("\n");
            }
            //bordure du bas d'une cellule
            if (ligneMilieu != 10) {
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
            //enregistre l'évènement de quitter la partie dans le log
            enregistrementDesLogs(8, (int) NULL, (int) NULL);
            return;
        }
        //On soustrait par 64 car la valeur de A est de 64 en numérique
        coordonneeX = coordonneeX - 64;
        //vérifie les coordonnées si il est valide et/ou si il touche un bateau
        aireDeJeux[10][10] = verificationDesCoordonnees(coordonneeX, coordonneeY, aireDeJeux);
    }
    while (aireDeJeux[9][9] != 100);
    affichageGagne();
}

/**
 * affiche l'aide du jeu
 */
void affichageDaide()
{
    effacerEcran();
    enregistrementDesLogs(4, (int) NULL, (int) NULL);
    afficherLegende(2);
    printf("\n\nLe but du jeu est de toucher tous les bateaux sur la grille.\n\n");
    printf("Donnez les coordonnées x et y pour envoyer un missile sur cette case.\n\n");
    printf("Si vous avez touché un bateau, le symbole ▓ s'affiche, si vous avez raté un bateau, le symbole ░ s'affiche.\n\n");
    printf("Utilisez le moins de missile possible pour avoir un maximum de points.\n\n\n\n\n\n");
    pause();
}

void changementDesMenus(int choix)
{
    switch (choix)
    {
        case 1:
            //Si le joueur s'est authentifié, il peut commencé une partie, sinon il ne peut pas
            if (strlen(nom) != 3)
            {
                ecranDemandeDauthentification();
            }
            else
            {
                //Affiche la grille pour la bataille navale et exécute les autres fonctions pour la bataille navale
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
            //enregistre cet évènement dans le log
            enregistrementDesLogs(7, (int) NULL, (int) NULL);
            return;
    }
}

/**
 * affiche les accents
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
    //pendant que l'utilisateur ne choisit pas l'option "quitter" le programme continue
    do
    {
        effacerEcran();
        //affichage du menu
        menu();
        //demande le choix à l'utilisateur
        choix = demandeDuChoix(choix);
        //change d'écran selon le choix de l'utilisateur
        changementDesMenus(choix);
    }
    while (choix != 5);
    return 0;
}