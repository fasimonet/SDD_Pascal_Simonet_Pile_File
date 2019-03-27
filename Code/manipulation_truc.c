#include "truc.h"

/* ---------------------------------------------------------------------------------------------------- */
/* Nom du fichier : manipulation_truc.c                                                                 */
/* Date de creation : 13/03/2019                                                                        */
/* Auteurs : Julien PASCAL et Fabien SIMONET (G21)                                                      */
/* Objectif : tester le bon fonctionnement des fonctions TRUC et TRUC_nr                                */                                                                                    */
/* ---------------------------------------------------------------------------------------------------- */


int main()
{
    int tab[3];
    tab[0] = 1;
    tab[1] = 2;
    tab[2] = 3;

    printf("==============================================\n");
    printf("\tVERSION RECURSIVE DE TRUC\n");
    printf("==============================================\n");
    TRUC(1, 3, tab);
    printf("\n");
    printf("==============================================\n");
    printf("\tVERSION DERECURSIFIEE DE TRUC\n");
    printf("==============================================\n");
    TRUC_nr(1, 3, tab);
    return 0;
}