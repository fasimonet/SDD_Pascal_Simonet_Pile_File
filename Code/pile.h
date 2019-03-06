typedef struct pile
{
    int taille;
    int rang_sommet;
    int *contenu;
} pile_t;

void afficher_file(pile_t t)
int est_file_vide(pile_t t);
int est_file_pleine(pile_t t);
pile_t* initialiser_file(int n);

