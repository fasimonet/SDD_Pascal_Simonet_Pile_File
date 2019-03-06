#include "file.h"

file_t* initialisation(int taille)
{
    file_t* f = (file_t*) malloc(sizeof(file_t));
    if(f == NULL)
    {
        printf("Pb allocation file\n");
        free(f);
    }
    else 
    {
        f->contenu = (element_file_t*) malloc(sizeof(element_file_t)*taille);
        if(f->contenu == NULL)
        {
            printf("Pb allocation contenu file\n");
            free(f->contenu);
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

void afficher_file(file_t f)
{
    int cpt = 0;
    printf("==============================================\n");
    printf("\t\tAFFICHAGE DE LA FILE\n");
    printf("==============================================\n");

    printf("Taille : %d\n", f.taille);
    printf("Nombre d'éléments : %d\n", f.cpt);
    printf("Rang premier %d\n", f.rang_premier);
    printf("Rang dernier %d\n", f.rang_dernier);

    while (cpt <= f.cpt)
    {
        printf("%d ", f.contenu[(f.rang_premier+cpt)%f.taille]);
        cpt++;
    }
    
}