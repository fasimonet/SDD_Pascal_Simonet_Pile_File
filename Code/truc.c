#include "truc.h"

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