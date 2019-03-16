#include "file.h"

file_t* initialiser_file(int taille)
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

    if(f.cpt == 0)
    {
        printf("La file est vide\n");
    }
    else 
    {
        printf("Contenu de la file : ");
        while (cpt < f.cpt)
        {
            printf("%d ", f.contenu[(f.rang_premier+cpt)%f.taille]);
            cpt++;
        }
        printf("\n");
    }  
}

int est_file_vide(file_t f)
{
    return f.cpt == 0;
}

int est_file_pleine(file_t f)
{
    return f.cpt == f.taille;
}

int enfiler(file_t* f, int val)
{
    int ok;
    
    if(est_file_pleine(*f))
    {
        // FAIRE DES MACROS !
        ok = 0;
    }
    else 
    {
        f->rang_dernier = (f->rang_dernier+1)%(f->taille);
        f->contenu[f->rang_dernier] = val;
        f->cpt++;
        ok = 1;
    }
    return ok;
}

int defiler(file_t *f, int* val)
{
    int ok;

    if(est_file_vide(*f))
    {
        ok = 0;
    }
    else 
    {
        printf("test : %d\n", f->contenu[f->rang_premier]);
        *val = f->contenu[f->rang_premier]; 
        f->rang_premier = (f->rang_premier+1)%(f->taille);
        f->cpt--;
        ok = 1;
    }
}

void liberer_file(file_t* f)
{
    if(f!=NULL)
    {
        free(f->contenu);
        free(f);
        f = NULL; 
    }
}
