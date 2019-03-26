#include "truc.h"
#include "pile.h"

/* ---------------------------------------------------------------------------------------------------- */
/* swap                                A remplir                                                        */
/*                                                                                                      */
/* En entree:                                                                                           */
/*                                                                                                      */
/* En sortie:                                                                                           */
/*                                                                                                      */
/* Principe:                                                                                            */
/* ---------------------------------------------------------------------------------------------------- */
void swap(int t[], int i, int j)
{
    int temp = t[i]; 
    t[i] = t[j];
    t[j] = temp;
}

/* ---------------------------------------------------------------------------------------------------- */
/* afficher_tab                                A remplir                                                */
/*                                                                                                      */
/* En entree:                                                                                           */
/*                                                                                                      */
/* En sortie:                                                                                           */
/*                                                                                                      */
/* Principe:                                                                                            */
/* ---------------------------------------------------------------------------------------------------- */
void afficher_tab(int t[], int n)
{
    printf("[ ");
    for(int j=0; j<n; j++)
    {
        printf("%d ", t[j]);
    }
    printf("]\n");
}

/* ---------------------------------------------------------------------------------------------------- */
/* TRUC                                A remplir                                                        */
/*                                                                                                      */
/* En entree:                                                                                           */
/*                                                                                                      */
/* En sortie:                                                                                           */
/*                                                                                                      */
/* Principe:                                                                                            */
/* ---------------------------------------------------------------------------------------------------- */
void TRUC(int i, int n, int t[])
{
    int il = i-1;
    
    if(il+1 == n)
    {
        afficher_tab(t, n);
    }
    else 
    {
        for(int j=il; j<n; j++)
        {
            swap(t, il, j);
            TRUC(i+1, n, t);
            swap(t, il, j);  
        }
    }
}

/* ---------------------------------------------------------------------------------------------------- */
/* TRUC_nr                                A remplir                                                     */
/*                                                                                                      */
/* En entree:                                                                                           */
/*                                                                                                      */
/* En sortie:                                                                                           */
/*                                                                                                      */
/* Principe:                                                                                            */
/* ---------------------------------------------------------------------------------------------------- */
void TRUC_nr(int i, int n, int t[])
{
    int il = i-1;
    int jl = il;
    int fini = 0;
    int reboucler = 0;
    int ok;
    pile_t* p = initialiser_pile(2*n);

    while(!fini)
    {
        if(il == n-1)
        {
            afficher_tab(t, n);
            if(est_pile_vide(*p))
            {
                fini = 1;
            }
            else 
            {
                depiler(p, &ok, &il);
                depiler(p, &ok, &jl);
                swap(t, il, jl);
                jl++;
                reboucler = 1;
            }
        }
        else 
        {
            if(!reboucler)
            {
                jl = il;
            }
            
            if (jl<n)
            {
                swap(t, il, jl);
                empiler(p, jl);
                empiler(p, il);
                il++;
                reboucler = 0;
            }
            else 
            {
                if(est_pile_vide(*p))
                {
                    fini = 1;
                }
                else 
                {
                    depiler(p, &ok, &il);
                    depiler(p, &ok, &jl);
                    swap(t, il, jl);
                    jl++;
                    reboucler = 1;
                }
            }
        }
    
    }
}
