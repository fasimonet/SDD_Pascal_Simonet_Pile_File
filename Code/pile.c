#include "pile.h"

/* ---------------------------------------------------------------------------------------------------- */
/* Nom du fichier : pile.c                                                                              */
/* Date de creation : 07/03/2019                                                                        */
/* Auteurs : Julien PASCAL et Fabien SIMONET (G21)                                                      */
/* Objectif : manipuler les piles                                                                       */
/* Fonctions :                                                                                          */
/*  - initialiser_pile                                                                                  */
/*  - afficher_pile                                                                                     */
/*  - est_pile_vide                                                                                     */
/*  - est_pile_pleine                                                                                   */
/*  - empiler                                                                                           */
/*  - depiler                                                                                           */
/*  - sommet                                                                                            */
/*  - liberer_pile                                                                                      */
/* ---------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------- */
/* initialiser_pile         Cree la pile est initialise les informations dans le bloc de tete           */
/*                                                                                                      */
/* En entree:                                                                                           */
/*      n la taille du tableau contenant les elements de la pile                                        */
/*                                                                                                      */
/* En sortie: Un pointeur vers le bloc de tete de la pile                                               */
/*                                                                                                      */
/* Principe                                                                                             */
/*      On alloue l'espace memoire du bloc de tete de la pile                                           */
/*      Si l'allocation memoire a echoue                                                                */
/*          On affiche un message d'erreur                                                              */
/*      Sinon                                                                                           */
/*          On alloue l'espace memoire du tableau contenant les elements de la pile                     */
/*          Si l'allocation memoire a echoue                                                            */
/*              On affiche un message d'erreur                                                          */
/*              On libere le bloc de tete de la pile                                                    */
/*      Sinon                                                                                           */
/*          On initialise la taille dans le bloc de tete                                                */
/*          On initialise le rang du sommet de la pile a -1 dans le bloc de tete                        */
/* ---------------------------------------------------------------------------------------------------- */
pile_t* initialiser_pile(int n)
{
    pile_t* p = (pile_t*) malloc(sizeof(pile_t));
    if (p == NULL)
    {
        printf("Pb allocation pile\n");
    }
    else 
    {
        p->contenu = (element_pile_t*) malloc(sizeof(element_pile_t)*n);
        if(p->contenu == NULL)
        {
            printf("Pb allocation contenu de la pile\n");
            free(p);
            p = NULL;
        }
        else 
        {
            p->taille = n;
            p->rang_sommet = -1;
        }
    }
    return p;
}

/* ---------------------------------------------------------------------------------------------------- */
/* afficher_pile                                Affiche la pile                                         */
/*                                                                                                      */
/* En entree: Le bloc de tete de la pile a afficher                                                     */
/*                                                                                                      */
/* En sortie: Aucune sortie                                                                             */
/*                                                                                                      */
/* Principe:                                                                                            */
/*      Si la pile est vide                                                                             */
/*          On affiche "La pile est vide"                                                               */
/*      Sinon                                                                                           */
/*          On affiche la taille de la pile se situant dans le bloc de tete                             */
/*          On affiche le rang du sommet de la pile se situant dans le bloc de tete                     */
/*          On affiche tous les elements de la pile                                                     */
/* ---------------------------------------------------------------------------------------------------- */
void afficher_pile(pile_t p)
{
    printf("==============================================\n");
    printf("\t\tAFFICHAGE DE LA PILE\n");
    printf("==============================================\n");
    if (est_pile_vide(p))
    {
        printf("La pile est vide\n");
    }
    else 
    {
        int cpt = 0;
        printf("Taille de la pile : %d\n", p.taille);
        printf("Rang du sommet de la pile : %d\n", p.rang_sommet);

        while (cpt <= p.rang_sommet)
        {
            printf(""FORMAT"\n", p.contenu[cpt]);
            cpt++;
        }
    }
}

/* ---------------------------------------------------------------------------------------------------- */
/* est_pile_vide                      Verifie si une pile est vide ou non                               */
/*                                                                                                      */
/* En entree:                                                                                           */
/*      p le bloc de tete de la pile                                                                    */
/*                                                                                                      */
/* En sortie:   1 si pile vide                                                                          */
/*              0 si pile non vide                                                                      */
/*                                                                                                      */
/* Principe                                                                                             */
/*      On verifie si la pile contient un sommet                                                        */
/* ---------------------------------------------------------------------------------------------------- */
int est_pile_vide(pile_t p)
{
    return p.rang_sommet == -1;
}

/* ---------------------------------------------------------------------------------------------------- */
/* est_pile_pleine                      Verifie si une pile est vide ou non                             */
/*                                                                                                      */
/* En entree:                                                                                           */
/*      p le bloc de tete de la pile                                                                    */
/*                                                                                                      */
/* En sortie:   1 si pile pleine                                                                        */
/*              0 si pile non pleine                                                                    */
/*                                                                                                      */
/* Principe                                                                                             */
/*      On verifie si le rang du sommet de la file est egal a la taille de la pile -1                   */
/* ---------------------------------------------------------------------------------------------------- */
int est_pile_pleine(pile_t p)
{   
    return p.rang_sommet == p.taille-1;
}

/* ---------------------------------------------------------------------------------------------------- */
/* empiler                          Empile un element                                                   */
/*                                                                                                      */
/* En entree:                                                                                           */
/*      p le pointeur vers bloc de tete de la pile                                                      */
/*      val la valeur a empiler                                                                         */
/*                                                                                                      */
/* En sortie:   0 si pile pleine avant l'ajout de la valeur dans la pile                                */
/*              1 si aucun probleme lors de l'ajout de la valeur dans la pile                           */
/*                                                                                                      */
/* Principe                                                                                             */
/*      On verifie si la pile est pleine                                                                */
/*      Si la pile n'est pas pleine                                                                     */
/*          On decremente le rang du sommet de la pile d'un cran                                        */
/*          On insere l'element dans la pile                                                            */
/*                                                                                                      */
/* Lexique:                                                                                             */
/*          ok booleen indique si l'element a pu etre empile correctement ou non                        */
/* ---------------------------------------------------------------------------------------------------- */
void empiler(pile_t* p, int *ok, element_pile_t val)
{
    *ok = !est_pile_pleine(*p);
    if (*ok)
    {
        p->rang_sommet++;
        p->contenu[p->rang_sommet] = val;
    }
}

/* ---------------------------------------------------------------------------------------------------- */
/* depiler                          Depile un element                                                   */
/*                                                                                                      */
/* En entree:                                                                                           */
/*      p le pointeur vers bloc de tete de la pile                                                      */
/*      ok l'adresse du booleen qui indique si l'element a pu etre defile correctement ou non           */
/*      res l'adresse de l'element depile                                                               */      
/*                                                                                                      */
/* En sortie:   0 si pile pleine avant l'ajout de la valeur dans la pile                                */
/*              1 si aucun probleme lors de l'ajout de la valeur dans la pile                           */
/*                                                                                                      */
/* Principe                                                                                             */
/*      On verifie si la pile est vide                                                                  */
/*      Si la n'est pas vide                                                                            */
/*          On recupere la valeur a depiler                                                             */
/*          On decremente le rang du sommet de la pile d'un cran                                        */
/*                                                                                                      */
/* Lexique:                                                                                             */
/*          ok adresse du booleen qui indique si l'element a pu etre defile correctement ou non         */
/* ---------------------------------------------------------------------------------------------------- */
void depiler(pile_t* p, int* ok, element_pile_t* res)
{
    *ok = !est_pile_vide(*p);
    if (*ok)
    {
        *res = p->contenu[p->rang_sommet];
        p->rang_sommet--;   
    }
}

/* ---------------------------------------------------------------------------------------------------- */
/* sommet                          Donne le sommet de la pile                                           */
/*                                                                                                      */
/* En entree:                                                                                           */
/*      p le bloc de tete de la pile                                                                    */
/*      ok l'adresse du booleen qui indique si le sommet a pu etre recupere ou non                      */
/*      res l'adresse du sommet a recuperer                                                             */  
/*                                                                                                      */
/* En sortie:   0 si pile vide lors de la recuperation du sommet de la pile                             */
/*              1 si aucun probleme lors de la recuperation du sommet de la pile                        */
/*                                                                                                      */
/* Principe                                                                                             */
/*      On verifie si la pile est vide                                                                  */
/*      Si la pile n'est pas vide                                                                       */
/*          On recupere le sommet de la pile                                                            */
/*                                                                                                      */
/* Lexique:                                                                                             */
/*          ok adresse du booleen qui indique si le sommet a pu etre recupere ou non                    */
/* ---------------------------------------------------------------------------------------------------- */
void sommet(pile_t p, int* ok, element_pile_t* res)
{
    *ok = !est_pile_vide(p);
    if (*ok)
    {
        *res = p.contenu[p.rang_sommet];
    }
}

/* ---------------------------------------------------------------------------------------------------- */
/* liberer_pile                                  Libere une pile                                        */
/*                                                                                                      */
/* En entree:                                                                                           */
/*      p le pointeur de vers le bloc de tete de la pile a supprimer                                    */
/*                                                                                                      */
/* En sortie: Aucune sortie                                                                             */
/*                                                                                                      */
/* Principe                                                                                             */
/*      Si la pile n'est pas deja liberee                                                               */
/*          On libere le tableau contenant les elements de la pile                                      */
/*          On libere la tete contenant les informations de la pile                                     */
/* ---------------------------------------------------------------------------------------------------- */
void liberer_pile(pile_t* p)
{
    if(p!=NULL)
    {
        free(p->contenu);
        free(p);
        p = NULL;
    }
}