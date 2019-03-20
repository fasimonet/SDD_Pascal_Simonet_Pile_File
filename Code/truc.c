#include "truc.h"
#include "pile.h"

void TRUC(int i, int n, int t[])
{
    //printf("%d %d %d\n", t[0], t[1], t[2]);
    int temp;
    if(i == n)
    {
        printf("[ ");
        for(int j=0; j<n; j++)
        {
            printf("%d ", t[j]);
        }
        printf("]\n");
    }
    else 
    {
        for(int j=i-1; j<n; j++)
        {
            //printf("cc : %d\n", i);
            temp = t[i-1]; 
            t[i-1] = t[j];
            t[j] = temp;
            //printf("t[0] = %d, t[1] = %d t[2] = %d\n", t[0], t[1], t[2]);
            //printf("i = %d, n = %d\n", i, n);
            TRUC(i+1, n, t);
            temp = t[i-1]; 
            t[i-1] = t[j];
            t[j] = temp;
            //printf("byebye : t[0] = %d, t[1] = %d t[2] = %d\n", t[0], t[1], t[2]);    
        }
    }
}

void TRUC_nr(int i, int n, int t[])
{
    int ok;
    int fini = 0;
    int jl = i;
    int il = i;
    pile_t *p = initialiser_pile(n);

    while (!fini)
    {
        if(il == n)
        {
            printf("[ "); 
            for(int k=0; k<n; k++)
            {
                printf("%d ", t[k]);
            }
            printf("]\n");
            if(!est_pile_vide(*p))
            {
                depiler(p, &ok, &il);
                depiler(p, &ok, &jl);
            }
            else 
            {
                fini = 1;
            }
        }
        else 
        {
            if(jl < n)
            {
                t[il] = t[jl];
                empiler(p, jl);
                empiler(p, il);
                il += 1;
                jl += 1;
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
               }
            }
        }
    }
}