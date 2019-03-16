#ifndef FILE_H
#define FILE_H

#include <stdlib.h>
#include <stdio.h>

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
int enfiler(file_t* f, int val);
int defiler(file_t* f, int* val);
void liberer_file(file_t* f);

#endif