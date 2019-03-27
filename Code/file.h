/* ---------------------------------------------------------------------------------------------------- */
/* Nom du fichier : file.h                                                                              */
/* Date de creation : 07/03/2019                                                                        */
/* Auteurs : Julien PASCAL et Fabien SIMONET (G21)                                                      */
/* Objectif : repertorier les prototypes des fonctions de manipulation de file                          */
/* ---------------------------------------------------------------------------------------------------- */
#ifndef FILE_H
#define FILE_H

#include <stdlib.h>
#include <stdio.h>

#define ERR_ENFILER -2
#define ERR_DEFILER -1
#define RAS_DEFILER 1
#define RAS_ENFILER 2

#define FORMAT "%d"

typedef int element_file_t;

typedef struct file
{
    int taille;
    int cpt;
    int rang_premier;
    int rang_dernier;
    element_file_t* contenu;
} file_t;

void afficher_file(file_t f);
file_t* initialiser_file(int taille);
int est_file_vide(file_t f);
int est_file_pleine(file_t f);
void enfiler(file_t* f, int *ok, int val);
void defiler(file_t* f, int *ok, int* val);
void liberer_file(file_t* f);

#endif