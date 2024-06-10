#include <stdio.h>
#define NMAX 15

int t[NMAX], // tableau représentant une ligne du triangle
    n, // nombre de lignes souhaitées
    i, // indice de ligne courante
    j; // indice courant de colonne

void menu(void)
{
    printf("Combien de lignes souhaitez-vous ? ");
    scanf("%d", &n);

    if (n > NMAX) n = NMAX;
    
    printf("\n\n p          ");

    for (i=0; i<n; i++) printf("%5d", i);
    printf("\n n\n");
    for (i=0; i<=n; i++) printf("-------");
    printf("\n");
}

void function(void)
{
    for (i=0; i<n; i++)
    {
        t[i] = 1;
        for (j=i-1; j>0; j--)
            t[j] = t[j-1] + t[j];
        printf("%2d --", i);
        for (j=0; j<=i; j++)
            printf("%5d", t[j]);
        printf("\n");
    }
}

int main()
{
    menu();
    function();
    return 0;
}