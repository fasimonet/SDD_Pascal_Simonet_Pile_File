#include "pile.h"

pile_t* initialiser_pile(int n)
{
    pile_t* p = (pile_t*) malloc(sizeof(pile_t));
    if (p == NULL)
    {
        printf("Pb allocation pile\n");
        free(p);
    }
    else 
    {
        p->taille = n;
        p->rang_sommet = -1;
        p->contenu = (element_pile_t*) malloc(sizeof(element_pile_t)*n);
        if(p->contenu == NULL)
        {
            printf("Pb allocation contenu de la pile\n");
            free(p->contenu);
            p = NULL;
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
            printf("%d\n", p.contenu[cpt]);
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