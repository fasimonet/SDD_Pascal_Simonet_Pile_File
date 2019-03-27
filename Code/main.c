#include "pile.h"
#include "file.h"

int main()
{
    
    int ok;           

    int res;

    // Test pile : creation de la pile
    pile_t *p = NULL;
    p = initialiser_pile(5);

    // Test pile : la pile est-elle vide ? cas lorsque la pile est vide
    est_pile_vide(*p);

    // Test pile : la pile est-elle vide ? cas lorsque la pile n'est pas vide
    empiler(p, &ok, 1);
    est_pile_vide(*p);

    // Test pile : la pile est-elle pleine ? cas lorsque la pile n'est pas pleine
    est_pile_pleine(*p);

    // Test pile : la pile est-elle pleine ? cas lorsque la pile est pleine
    empiler(p, &ok, 2);
    empiler(p, &ok, 3);
    empiler(p, &ok, 4);
    empiler(p, &ok, 5);
    est_pile_pleine(*p);

    // Test pile : empiler dans une pile non pleine
    pile_t *p2 = NULL;
    p2 = initialiser_pile(5);
    afficher_pile(*p2);
    empiler(p2, &ok, 1);
    afficher_pile(*p2);

    // Test pile : empiler dans une pile pleine
    empiler(p2, &ok, 2);
    empiler(p2, &ok, 3);
    empiler(p2, &ok, 4);
    empiler(p2, &ok, 5);
    afficher_pile(*p2);
    empiler(p2, &ok, 6);
    afficher_pile(*p2);
    

    // Test pile : depiler un element d'une pile vide
    pile_t *p3 = NULL;
    p3 = initialiser_pile(5);
    afficher_pile(*p3);
    depiler(p3, &ok, &res);
    afficher_pile(*p3);

    // Test pile : depiler un element d'une pile non vide
    empiler(p3, &ok, 1);
    empiler(p3, &ok, 2);
    empiler(p3, &ok, 3);
    afficher_pile(*p3);
    depiler(p3, &ok, &res);
    afficher_pile(*p3);

    // Test pile : liberer la pile
    liberer_pile(p);
    liberer_pile(p2);
    liberer_pile(p3);

    // Test file : creation de la file
    file_t* f = NULL;
    f = initialiser_file(5);

    // Test file : la file est-elle vide ? cas lorsque la file est vide
    est_file_vide(*f);

    // Test file : la file est-elle vide ? cas lorsque la file n'est pas vide
    file_t* f2 = NULL;
    f2 = initialiser_file(5);
    enfiler(f2, &ok, 1);
    enfiler(f2, &ok, 2);
    enfiler(f2, &ok, 3);

    afficher_file(*f2);

    est_file_vide(*f2);
    
    // Test file : la file est-elle pleine ? cas lorsque la file n'est pas pleine
    est_file_pleine(*f2);

    // Test file : la file est-elle pleine ? cas lorsque la file est pleine
    enfiler(f2, &ok, 4);
    enfiler(f2, &ok, 5);

    est_file_pleine(*f2);

    // Test file : enfiler dans une file non pleine
    file_t* f3 = NULL;
    f3 = initialiser_file(5);
    afficher_file(*f3);
    enfiler(f3, &ok, 1);
    afficher_file(*f3);

    // Test file : enfiler dans une file pleine
    enfiler(f3, &ok, 2);
    enfiler(f3, &ok, 3);
    enfiler(f3, &ok, 4);
    enfiler(f3, &ok, 5);
    afficher_file(*f3);
    enfiler(f3, &ok, 6);
    afficher_file(*f3);

    // Test file : defiler dans une file vide
    file_t* f4 = NULL;
    f4 = initialiser_file(5);
    afficher_file(*f4);
    defiler(f4, &ok, &res);
    afficher_file(*f4);
    

    // Test file : defiler dans une file non vide
    enfiler(f4, &ok, 1);
    enfiler(f4, &ok, 2);
    enfiler(f4, &ok, 3);
    afficher_file(*f4);

    defiler(f4, &ok, &res);
    afficher_file(*f4);

    // Test file : liberer la file
    liberer_file(f);
    liberer_file(f2);
    liberer_file(f3);
    liberer_file(f4);

    return 0;
}