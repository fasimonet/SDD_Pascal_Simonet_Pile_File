#include "file.h"

/* ---------------------------------------------------------------------------------------------------- */
/* Nom du fichier : file.c                                                                              */
/* Date de creation : 07/03/2019                                                                        */
/* Auteurs : Julien PASCAL et Fabien SIMONET (G21)                                                      */
/* Objectif : manipuler les files                                                                       */
/* Fonctions :                                                                                          */
/*  - initialiser_file                                                                                  */
/*  - afficher_file                                                                                     */
/*  - est_file_vide                                                                                     */
/*  - est_file_pleine                                                                                   */
/*  - enfiler                                                                                           */
/*  - defiler                                                                                           */
/*  - liberer_file                                                                                      */
/* ---------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------- */
/* initialiser_file         Cree la file est initialise les informations dans le bloc de tete           */
/*                                                                                                      */
/* En entree:                                                                                           */
/*      taille la taille du tableau contenant les elements de la file                                   */
/*                                                                                                      */
/* En sortie: Un pointeur sur une structure de type file                                                */
/*                                                                                                      */
/* Principe                                                                                             */
/*      On alloue l'espace memoire du bloc de tete de la file                                           */
/*      Si l'allocation memoire a echoue                                                                */
/*          On affiche un message d'erreur                                                              */
/*      Sinon                                                                                           */
/*          On alloue l'espace memoire du tableau contenant les elements de la file                     */
/*          Si l'allocation memoire a echoue                                                            */
/*              On affiche un message d'erreur                                                          */
/*              On libere le bloc de tete de la file                                                    */
/*      Sinon                                                                                           */
/*          On initialise la taille dans le bloc de tete                                                */
/*          On initialise le nombre d'elements dans le bloc de tete                                     */
/*          On initialise le rang du premier element de la file a 0 dans le bloc de tete                */
/*          On initialise le rang du dernier element de la file a taille-1 dans le bloc de tete         */
/*                                                                                                      */
/* Lexique                                                                                              */
/*      f : pointeur sur une structure de type file                                                     */
/* ---------------------------------------------------------------------------------------------------- */
file_t* initialiser_file(int taille)
{
    file_t* f = (file_t*) malloc(sizeof(file_t));
    if(f == NULL)
    {
        printf("Pb allocation file\n");
    }
    else 
    {
        f->contenu = (element_file_t*) malloc(sizeof(element_file_t)*taille);
        if(f->contenu == NULL)
        {
            printf("Pb allocation contenu file\n");
            free(f);
            f = NULL;
        }
        else 
        {
            f->taille = taille;
            f->cpt = 0;
            f->rang_premier = 0;
            f->rang_dernier = taille-1;
        }
    }
}

/* ---------------------------------------------------------------------------------------------------- */
/* afficher_file                                Affiche la file                                         */
/*                                                                                                      */
/* En entree: Le bloc de tete de la file a afficher                                                     */
/*                                                                                                      */
/* En sortie: Aucune sortie                                                                             */
/*                                                                                                      */
/* Principe:                                                                                            */
/*      On affiche la taille de la file se situant dans le bloc de tete                                 */
/*      On affiche le nombre d'elements de la file se situant dans le bloc de tete                      */
/*      On affiche le rang du premier element de la file se situant dans le bloc de tete                */
/*      On affiche le rang du dernier element de la file se situant dans le bloc de tete                */
/*                                                                                                      */
/* Lexique :                                                                                            */
/*      compt : entier servant a parcourire le tableau pour en afficher tout les elements               */
/* ---------------------------------------------------------------------------------------------------- */
void afficher_file(file_t f)
{
    int compt;
    printf("==============================================\n");
    printf("\t\tAFFICHAGE DE LA FILE\n");
    printf("==============================================\n");

    printf("Taille : %d\n", f.taille);
    printf("Nombre d'éléments : %d\n", f.cpt);
    printf("Rang premier %d\n", f.rang_premier);
    printf("Rang dernier %d\n", f.rang_dernier);

    if(f.cpt == 0)
    {
        printf("La file est vide\n");
    }
    else 
    {
        printf("Contenu de la file : ");
        for (compt = 0; compt < f.cpt; compt++ )
        {
            printf(""FORMAT" ", f.contenu[(f.rang_premier+compt)%f.taille]);
        }
        printf("\n");
    }  
}



/* ---------------------------------------------------------------------------------------------------- */
/* est_file_vide                      Verifie si une file est vide ou non                               */
/*                                                                                                      */
/* En entree:                                                                                           */
/*      f le bloc de tete de la file                                                                    */
/*                                                                                                      */
/* En sortie:   1 si file vide                                                                          */
/*              0 si file non vide                                                                      */
/*                                                                                                      */
/* Principe                                                                                             */
/*      On verifie si le nombre d'element dans la file est egal a 0                                     */
/* ---------------------------------------------------------------------------------------------------- */
int est_file_vide(file_t f)
{
    return f.cpt == 0;
}

/* ---------------------------------------------------------------------------------------------------- */
/* est_file_pleine                      Verifie si une file est vide ou non                             */
/*                                                                                                      */
/* En entree:                                                                                           */
/*      f le bloc de tete de la file                                                                    */
/*                                                                                                      */
/* En sortie:   1 si file pleine                                                                        */
/*              0 si file non pleine                                                                    */
/*                                                                                                      */
/* Principe                                                                                             */
/*      On verifie si le nombre d'element dans la file est egal a la taille de la file                  */
/* ---------------------------------------------------------------------------------------------------- */
int est_file_pleine(file_t f)
{
    return f.cpt == f.taille;
}

/* ---------------------------------------------------------------------------------------------------- */
/* enfiler                          Enfile un element                                                   */
/*                                                                                                      */
/* En entree:                                                                                           */
/*      f le pointeur vers bloc de tete de la file                                                      */
/*      val la valeur a enfiler                                                                         */
/*                                                                                                      */
/* En sortie:   ERR_ENFILER si file pleine avant l'ajout de la valeur dans la file                      */
/*              RAS_ENFILER si aucun probleme lors de l'ajout de la valeur dans la file                 */
/*                                                                                                      */
/* Principe                                                                                             */
/*      Si la file est pleine                                                                           */
/*          On indique qu'une erreur a eu lieu lors de l'ajout                                          */
/*      Sinon                                                                                           */
/*          On avance le dernier element de la file d'un cran                                           */
/*          On ajoute la valeur au rang du dernier element de la file                                   */
/*          On incremente le nombre d'elements de la file                                               */
/*          On indique qu'aucune erreur n'a perturbe l'ajout de la valeur dans la file                  */
/* ---------------------------------------------------------------------------------------------------- */
void enfiler(file_t* f, int *ok, int val)
{  
    if(est_file_pleine(*f))
    {
        *ok = ERR_ENFILER;
    }
    else 
    {
        f->rang_dernier = (f->rang_dernier+1)%(f->taille);
        f->contenu[f->rang_dernier] = val;
        f->cpt++;
        *ok = RAS_ENFILER;
    }
}

/* ---------------------------------------------------------------------------------------------------- */
/* defiler                          Defile un element                                                   */
/*                                                                                                      */
/* En entree:                                                                                           */
/*      f le pointeur vers le bloc de tete de la file                                                   */
/*                                                                                                      */
/* En sortie:   ERR_DEFILER si file vide avant la suppression du premier element de la file             */
/*              RAS_DEFILER si aucun probleme lors de la suppression du premier element de la file      */
/*                                                                                                      */
/* En entree/sortie:                                                                                    */
/*              val le pointeur vers la valeur de l'element a supprimer                                 */
/*                                                                                                      */
/* Principe                                                                                             */
/*      Si la file est vide                                                                             */
/*          On indique qu'une erreur a eu lieu lors de la suppression                                   */
/*      Sinon                                                                                           */
/*          On recupere la valeur de l'element a supprimer au rang du premier element de la file        */
/*          On avance le premier element de la file d'un cran                                           */
/*          On decremente le nombre d'elements de la file                                               */
/*          On indique qu'aucune erreur n'a perturbe la suppression du premier element de la file       */
/* ---------------------------------------------------------------------------------------------------- */
void defiler(file_t *f, int *ok, int* val)
{
    if(est_file_vide(*f))
    {
        *ok = ERR_DEFILER;
    }
    else 
    {
        printf("test : "FORMAT"\n", f->contenu[f->rang_premier]);
        *val = f->contenu[f->rang_premier]; 
        f->rang_premier = (f->rang_premier+1)%(f->taille);
        f->cpt--;
        *ok = RAS_DEFILER;
    }
}

/* ---------------------------------------------------------------------------------------------------- */
/* liberer_file                                  Libere une file                                        */
/*                                                                                                      */
/* En entree:                                                                                           */
/*      tete le pointeur de tete de la file a supprimer                                                 */
/*                                                                                                      */
/* En sortie: Aucune sortie                                                                             */
/*                                                                                                      */
/* Principe                                                                                             */
/*      Si la file n'est pas deja liberee                                                               */
/*          On libere le tableau contenant les elements de la file                                      */
/*          On libere la tete contenant les informations de la file                                     */
/* ---------------------------------------------------------------------------------------------------- */
void liberer_file(file_t* f)
{
    if(f!=NULL)
    {
        free(f->contenu);
        free(f);
        f = NULL; 
    }
}
