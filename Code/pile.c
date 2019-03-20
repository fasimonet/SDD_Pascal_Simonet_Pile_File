#include "pile.h"

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

int est_pile_vide(pile_t p)
{
    return p.rang_sommet == -1;
}

int est_pile_pleine(pile_t p)
{   
    return p.rang_sommet == p.taille-1;
}


int empiler(pile_t* p, element_pile_t val)
{
    int ok = !est_pile_pleine(*p);
    if (ok)
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