/* ---------------------------------------------------------------------------------------------------- */
/* Nom du fichier : pile.h                                                                              */
/* Date de creation : 07/03/2019                                                                        */
/* Auteurs : Julien PASCAL et Fabien SIMONET (G21)                                                      */
/* Objectif : repertorier les prototypes des fonctions de manipulation de pile                          */
/* ---------------------------------------------------------------------------------------------------- */
#ifndef PILE_H
#define PILE_H

#include <stdlib.h>
#include <stdio.h>

#define FORMAT "%d"

typedef int element_pile_t;

typedef struct pile
{
    int taille;
    int rang_sommet;
    element_pile_t *contenu;
} pile_t;

void afficher_pile(pile_t p);
int est_pile_vide(pile_t p);
int est_pile_pleine(pile_t p);
pile_t* initialiser_pile(int n);
void empiler(pile_t* p, int *ok, element_pile_t val);
void depiler(pile_t* p, int* ok, element_pile_t* res);
void sommet(pile_t p, int*ok, element_pile_t* res);
void liberer_pile(pile_t* p);

#endif