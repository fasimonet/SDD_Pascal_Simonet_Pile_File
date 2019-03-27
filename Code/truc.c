#include "truc.h"
#include "pile.h"

/* ---------------------------------------------------------------------------------------------------- */
/* swap                                echange les valeur de deux element du tableau                    */
/*                                                                                                      */
/* En entree:                                                                                           */
/*      t un tableau                                                                                    */
/*      i et j lesdeux indices des elements a permuter                                                  */
/*                                                                                                      */
/* En sortie:                                                                                           */
/*                                                                                                      */
/* Principe:                                                                                            */
/*      on defini une variable temporaire                                                               */
/*      on memorise grace a cette variable la valeur de la premiere variable                            */
/*      on modifie la premiere variable en la mettant egal a la deuxieme                                */
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
/*      t un tableau                                                                                    */
/*      n sa taille                                                                                     */
/*                                                                                                      */
/* En sortie:                                                                                           */
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
/* TRUC                                ecrit l'ensemble des permutation possible du tableau t           */
/*                                                                                                      */
/* En entree:                                                                                           */
/*      t un tableau                                                                                    */
/*      n sa taille                                                                                     */
/*      i un indice de depart                                                                           */
/*                                                                                                      */
/* En sortie:                                                                                           */
/*                                                                                                      */
/* Principe:                                                                                            */
/*      si i = n alors                                                                                  */
/*          on affiche le tableau                                                                       */
/*      sinon                                                                                           */
/*          pour j allant de i a n                                                                      */
/*              echanger les element d'indice i et j                                                    */
/*              appeler la fonction TRUC avec i+1 n et t                                                */
/*              echanger les element d'indice i et j                                                    */
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
/* En sortie:                                                                                           */
/*                                                                                                      */
/* Principe:                                                                                            */
/*      on initialise les variables locales il et jl en les mettant egale a i                           */
/*      on initialise le booleen d'arret a faux                                                         */
/*      on initialise le bolleen de retour de boucle a faux                                             */
/*      on cree une pile                                                                                */
/*      tant que le booleen d'arret est faux                                                            */
/*          si il=n alors                                                                               */
/*              on affiche le tableau                                                                   */
/*              si la pile est vide alors                                                               */
/*                  on met le booleen de fin a vrais                                                    */
/*              sinon                                                                                   */
/*                  on depile les element il et jl                                                      */
/*                  on echange les elements d'indice il et jl                                           */
/*                  on incremente jl                                                                    */
/*                  on met le booleen de retour de boucle a vrais                                       */
/*          sinon                                                                                       */
/*              si le booleen de retour de boucle est faux alors                                        */
/*                  on met jl egal il                                                                   */
/*              si jl<= n alors                                                                         */
/*                  on echange les elements d'indice il et jl                                           */
/*                  on empile jl et il                                                                  */
/*                  on incremente il                                                                    */
/*                  on met le booleen de retour de boucle a faux                                        */
/*              sinon                                                                                   */
/*                  si la pile est vide alors                                                           */
/*                  on met le booleen de fin a vrais                                                    */
/*              sinon                                                                                   */
/*                  on depile les element il et jl                                                      */
/*                  on echange les elements d'indice il et jl                                           */
/*                  on incremente jl                                                                    */
/*                  on met le booleen de retour de boucle a vrais                                       */
/* ---------------------------------------------------------------------------------------------------- */
void TRUC_nr(int i, int n, int t[])
{
    int il = i-1; // les indices vont de 0 a n-1
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
