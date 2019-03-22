#include "pile.h"
#include "file.h"

int main()
{
    
    int ok;

    int res, est_vide, est_pleine;

    // Test pile : creation de la pile
    pile_t *p = NULL;
    p = initialiser_pile(5);

    // Test pile : la pile est-elle vide ? cas lorsque la pile est vide
    est_vide = est_pile_vide(*p);

    // Test pile : la pile est-elle vide ? cas lorsque la pile n'est pas vide
    empiler(p, 1);
    est_vide = est_pile_vide(*p);

    // Test pile : la pile est-elle pleine ? cas lorsque la pile n'est pas pleine
    est_pleine = est_pile_pleine(*p);

    // Test pile : la pile est-elle pleine ? cas lorsque la pile est pleine
    empiler(p, 2);
    empiler(p, 3);
    empiler(p, 4);
    empiler(p, 5);
    est_pleine = est_pile_pleine(*p);

    // Test pile : empiler dans une pile non pleine
    pile_t *p2 = NULL;
    p2 = initialiser_pile(5);
    afficher_pile(*p2);
    ok = empiler(p2, 1);
    afficher_pile(*p2);

    // Test pile : empiler dans une pile pleine
    empiler(p2, 2);
    empiler(p2, 3);
    empiler(p2, 4);
    empiler(p2, 5);
    afficher_pile(*p2);
    ok = empiler(p2, 6);
    afficher_pile(*p2);
    

    // Test pile : depiler un element d'une pile vide
    pile_t *p3 = NULL;
    p3 = initialiser_pile(5);
    afficher_pile(*p3);
    depiler(p3, &ok, &res);
    afficher_pile(*p3);

    // Test pile : depiler un element d'une pile non vide
    empiler(p3, 1);
    empiler(p3, 2);
    empiler(p3, 3);
    afficher_pile(*p3);
    depiler(p3, &ok, &res);
    afficher_pile(*p3);

    //Test file : liberer la pile
    liberer_pile(p);
    liberer_pile(p2);
    liberer_pile(p3);

    /*

    // Test file : creation de la file
    file_t* f = NULL;
    f = initialiser_file(5);

    // Test file : la file est-elle vide ? cas lorsque la file est vide
    est_vide = est_file_vide(*f);

    // Test file : la file est-elle vide ? cas lorsque la file n'est pas vide
    file_t* f2 = NULL;
    f2 = initialiser_file(5);
    enfiler(f2, 1);
    enfiler(f2, 2);
    enfiler(f2, 3);

    afficher_file(*f2);

    est_vide = est_file_vide(*f2);
    
    // Test file : la file est-elle pleine ? cas lorsque la file n'est pas pleine
    est_pleine = est_file_pleine(*f2);

    // Test file : la file est-elle pleine ? cas lorsque la file est pleine
    enfiler(f2, 4);
    enfiler(f2, 5);

    est_pleine = est_file_pleine(*f2);

    // Test file : enfiler dans une file non pleine
    file_t* f3 = NULL;
    f3 = initialiser_file(5);
    afficher_file(*f3);
    ok = enfiler(f3, 1);
    afficher_file(*f3);

    // Test file : enfiler dans une file pleine
    enfiler(f3, 2);
    enfiler(f3, 3);
    enfiler(f3, 4);
    enfiler(f3, 5);
    afficher_file(*f3);
    ok = enfiler(f3, 6);
    afficher_file(*f3);

    // Test file : defiler dans une file vide
    file_t* f4 = NULL;
    f4 = initialiser_file(5);
    afficher_file(*f4);
    ok = defiler(f4, &res);
    afficher_file(*f4);
    

    // Test file : defiler dans une file non vide
    enfiler(f4, 1);
    enfiler(f4, 2);
    enfiler(f4, 3);
    afficher_file(*f4);

    ok = defiler(f4, &res);
    afficher_file(*f4);

    // Test file : liberer la file
    liberer_file(f);
    liberer_file(f2);
    liberer_file(f3);
    liberer_file(f4);
    */

    return 0;
}