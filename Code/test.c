#include "pile.h"
#include "file.h"

int main()
{
    
    int ok;/*
    element_pile_t res;
    pile_t* p = initialiser_pile(5);
    afficher_pile(*p);

    //if(est_pile_pleine(*p)) printf("La pile est pleine\n");

    for(int i= 0; i< 10; i++)
    {
        ok = empiler(p, i); 
        if (!ok) printf("Pile pleine, impossible d'empiler\n");
        afficher_pile(*p);   
    }

    for(int i=0; i<6; i++)
    {
        depiler(p, &ok, &res);
        if(!ok) 
        {
            printf("Pile vide, impossible de depiler\n");
        }
        else 
        {
            printf("l'element depile est : %d\n", res);
        }
        afficher_pile(*p);
    }
    
        sommet(*p, &ok, &res);
        if(!ok) 
        {
            printf("Pile vide, impossible de récupérer le sommet\n");
        }
        else 
        {
            printf("le sommet est : %d\n", res);
        }

    liberer_pile(p); */

    int res;
    file_t* f = initialiser_file(5);
    afficher_file(*f);
    enfiler(f, 2);
    afficher_file(*f);
    enfiler(f, 3);
    afficher_file(*f);
    enfiler(f, 4);
    afficher_file(*f);
    enfiler(f, 5);
    afficher_file(*f);
    enfiler(f, 6);
    afficher_file(*f);
    enfiler(f, 7);
    afficher_file(*f);

    defiler(f, &res);
    //printf("Les res est : %d\n", *res);
    afficher_file(*f);
        defiler(f, &res);
    //printf("Les res est : %d\n", *res);
    afficher_file(*f);
        defiler(f, &res);
    //printf("Les res est : %d\n", *res);
    afficher_file(*f);
        defiler(f, &res);
    //printf("Les res est : %d\n", *res);
    afficher_file(*f);
        defiler(f, &res);
    //printf("Les res est : %d\n", *res);
    afficher_file(*f);
        defiler(f, &res);
    //printf("Les res est : %d\n", *res);
    afficher_file(*f);

    liberer_file(f);
    return 0;
}