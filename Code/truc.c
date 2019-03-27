#include "truc.h"
#include "pile.h"

/* ---------------------------------------------------------------------------------------------------- */
/* Nom du fichier : file.c                                                                              */
/* Date de creation : 13/03/2019                                                                        */
/* Auteurs : Julien PASCAL et Fabien SIMONET (G21)                                                      */
/* Objectif : manipuler les files                                                                       */
/* Fonctions :                                                                                          */
/*  - swap                                                                                              */
/*  - afficher_tab                                                                                      */
/*  - test_de_fin                                                                                       */
/*  - TRUC                                                                                              */
/*  - TRUC_nr                                                                                           */
/* ---------------------------------------------------------------------------------------------------- */


/* ---------------------------------------------------------------------------------------------------- */
/* swap                                echange les valeur de deux element du tableau                    */
/*                                                                                                      */
/* En entree:                                                                                           */
/*      i et j les deux indices des elements a permuter                                                 */
/*                                                                                                      */
/* En entree / sortie:                                                                                  */
/*      t un tableau                                                                                    */
/*                                                                                                      */
/* Principe:                                                                                            */
/*      on definit une variable temporaire                                                              */
/*      on memorise grace a cette variable la valeur de la premiere variable                            */
/*      on modifie la premiere variable en la mettant egale a la deuxieme                               */
/*      on recupere la premiere valeur dans la variable temporaire que l'on met dans la deuxieme        */
/*      variable                                                                                        */
/* ---------------------------------------------------------------------------------------------------- */
void swap(int t[], int i, int j)
{
    int temp = t[i]; 
    t[i] = t[j];
    t[j] = temp;
}

/* ---------------------------------------------------------------------------------------------------- */
/* afficher_tab                                affiche le tableau                                       */
/*                                                                                                      */
/* En entree:                                                                                           */
/*      t : un tableau                                                                                  */
/*      n : sa taille                                                                                   */
/*                                                                                                      */
/* En sortie: Aucune sortie                                                                             */
/*                                                                                                      */
/* Principe:                                                                                            */
/*      pour j allant de 0 a n-1                                                                        */
/*          afficher l'element d'indice j du tableau                                                    */
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
/* test_de_fin                                effectue le test de fin de la fonction                    */
/*                                                                                                      */
/* En entree / sortie :                                                                                 */
/*      p : pointeur sur la structure pile                                                              */
/*      t : un tableau                                                                                  */
/*      reboucler : pointeur sur un entier                                                              */
/*      fini : pointeur sur un entier                                                                   */
/*      ok : pointeur sur un entier                                                                     */
/*      il : pointeur sur un entier                                                                     */
/*      jl : pointeur sur un entier                                                                     */
/*                                                                                                      */
/*                                                                                                      */
/* Principe:                                                                                            */
/*      si la pile est vide alors                                                                       */
/*                  on met le booleen de fin a vrai                                                     */
/*              sinon                                                                                   */
/*                  on depile les element il et jl                                                      */
/*                  on echange les elements d'indice il et jl                                           */
/*                  on incremente jl                                                                    */
/*                  on met le booleen de retour de boucle a vrai                                        */
/* ---------------------------------------------------------------------------------------------------- */

void test_de_fin(pile_t* p, int t[], int* reboucler, int* fini, int *ok, int *il, int* jl)
{
    if(est_pile_vide(*p))
    {
        *fini = 1;
    }
    else 
    {
        depiler(p, ok, il);
        depiler(p, ok, jl);
       // printf("jl : %d, il : %d\n", *jl, *il);
        swap(t, *il, *jl);
        (*jl)++;
        *reboucler = 1;
    }
}


/* ---------------------------------------------------------------------------------------------------- */
/* TRUC                                ecrit l'ensemble des permutation possible du tableau t           */
/*                                                                                                      */
/* En entree:                                                                                           */
/*      t : un tableau                                                                                  */
/*      n : sa taille                                                                                   */
/*      i : un indice de depart                                                                         */
/*                                                                                                      */
/* En sortie: Aucune sortie                                                                             */
/*                                                                                                      */
/* Principe:                                                                                            */
/*      si i = n alors                                                                                  */
/*          on affiche le tableau                                                                       */
/*      sinon                                                                                           */
/*          pour j allant de i a n                                                                      */
/*              echanger les elements d'indice i et j                                                   */
/*              appeler la fonction TRUC avec i+1 n et t                                                */
/*              echanger les elements d'indice i et j                                                   */
/* ---------------------------------------------------------------------------------------------------- */
void TRUC(int i, int n, int t[])
{
    int il = i-1; // les indices vont de 0 a n-1
    
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
/* TRUC_nr                                ecrit l'ensemble des permutation possible du tableau t de     */
/* maniere non recursive                                                                                */
/*                                                                                                      */
/* En entree:                                                                                           */
/*      t un tableau                                                                                    */
/*      n sa taille                                                                                     */
/*      i un indice de depart                                                                           */
/*                                                                                                      */
/* En sortie: Aucune sortie                                                                             */
/*                                                                                                      */
/* Principe:                                                                                            */
/*      on initialise les variables locales il et jl en les mettant egales a i                          */
/*      on initialise le booleen d'arret a faux                                                         */
/*      on initialise le booleen de retour de boucle a faux                                             */
/*      on cree une pile                                                                                */
/*      tant que le booleen d'arret est faux                                                            */
/*          si il=n alors                                                                               */
/*              on affiche le tableau                                                                   */
/*              on appelle la foction test_de_fin                                                       */
/*          sinon                                                                                       */
/*              si le booleen de retour de boucle est faux alors                                        */
/*                  on met jl egal il                                                                   */
/*              si jl<= n alors                                                                         */
/*                  on echange les elements d'indice il et jl                                           */
/*                  on empile jl et il                                                                  */
/*                  on incremente il                                                                    */
/*                  on met le booleen de retour de boucle a faux                                        */
/*              sinon                                                                                   */
/*                  on appelle la foction test_de_fin                                                   */
/* ---------------------------------------------------------------------------------------------------- */
void TRUC_nr(int i, int n, int t[])
{
    int         il = i-1; // les indices vont de 0 a n-1
    int         jl = il;
    int         fini = 0;
    int         reboucler = 0;
    int         ok;
    pile_t    * p = initialiser_pile(2*n);

    while(!fini)
    {
        if(il == n-1)
        {   
            afficher_tab(t, n);
            test_de_fin(p, t, &reboucler, &fini, &ok, &il, &jl);
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
                empiler(p, &ok, jl);
                empiler(p, &ok, il);
                il++;
                reboucler = 0;
            }
            else 
            {
                test_de_fin(p, t, &reboucler, &fini, &ok, &il, &jl);
            }
        }
    
    }
}
