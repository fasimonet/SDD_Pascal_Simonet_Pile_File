#include "pile.h"

pile_t* initialiser_file(int n)
{
    pile_t* p = (pile_t*) malloc(sizeof(pile_t));
    if (p == NULL)
    {
        printf("Pb allocation file\n");
        free(p);
    }
    else 
    {
        p->taille = n;
        p->rang_sommet = -1;
        p->contenu = (int*) malloc(sizeof(int)*n);
        if(p->contenu == NULL)
        {
            printf("Pb allocation contenu de la file\n");
            free(p->contenu);
            p = NULL;
        }
    }
}