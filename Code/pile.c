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
/*  - rech_prec_triee_LCH                                                                               */
/*  - adj_cell_LCH                                                                                      */
/*  - supprimer_maillon_LCH                                                                             */
/*  - liberer_LCH                                                                                       */
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

// A FINIR !!!!!!!!
/* ---------------------------------------------------------------------------------------------------- */
/* empiler                          Empile un element                                                   */
/*                                                                                                      */
/* En entree:                                                                                           */
/*      p le pointeur vers bloc de tete de la pile                                                      */
/*      val la valeur a empiler                                                                         */
/*                                                                                                      */
/* En sortie:   1 si pile pleine avant l'ajout de la valeur dans la pile                      */
/*              0 si aucun probleme lors de l'ajout de la valeur dans la pile                 */
/*                                                                                                      */
/* Principe                                                                                             */
/*      Si la n'est pas pleine                                                                           */
/*          On indique qu'une erreur a eu lieu lors de l'ajout                                          */
/*      Sinon                                                                                           */
/*          On avance le dernier element de la file d'un cran                                           */
/*          On ajoute la valeur au rang du dernier element de la file                                   */
/*          On incremente le nombre d'elements de la file                                               */
/*          On indique qu'aucune erreur n'a perturbe l'ajout de la valeur dans la file                  */
/*                                                                                                      */
/* Lexique:                                                                                             */
/*          ok booleen indique si l'element a pu etre enfile correctement ou non                        */
/* ---------------------------------------------------------------------------------------------------- */
int empiler(pile_t* p, element_pile_t val)
{
    int ok;
    if (!est_pile_pleine(*p))
    {
        p->rang_sommet++;
        p->contenu[p->rang_sommet] = val;
    }
    return ok;
}

void depiler(pile_t* p, int* ok, element_pile_t* res)
{
    *ok = !est_pile_vide(*p);
    if (*ok)
    {
        *res = p->contenu[p->rang_sommet];
        p->rang_sommet--;
    }
}

void sommet(pile_t p, int* ok, element_pile_t* res)
{
    *ok = !est_pile_vide(p);
    if (*ok)
    {
        *res = p.contenu[p.rang_sommet];
    }
}

void liberer_pile(pile_t* p)
{
    free(p->contenu);
    free(p);
}