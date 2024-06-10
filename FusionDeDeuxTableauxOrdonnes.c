#include <stdio.h>
#define NMAX 100

/* Fonction de fusion de deux tableaux */

void fusion(int t[], int t1[], int t2[], int val1, int val2)
{
    int i=0, i1=0, i2=0, k;
    while (i1 < val1 && i2 < val2)
    {
        if (t1[i1] < t2[i2]) t[i++] = t1[i1++];
        else t[i++] = t2[i2++];
    }
    if (i1 == val1)
        for (k=i2; k<val2; k++) t[i++] = t2[k];
    else
        for (k=i1; k<val1; k++) t[i++] = t1[k];
}

/* Fonction du tri bulle d'un tableau */

void tri_bulle(int t[], int val)
{
    int i=-1, j, temp, k, permut=1 ;
    while (i<val-1 && permut)
    {
        permut = 0;
        for (j=val-2; j>i; j--)
            if (t[j] > t[j+1])
            {
                permut = 1;
                temp = t[j];
                t[j] = t[j+1];
                t[j+1] = temp;
            }
        i++;
    }
}

/* Programme principal */

int main()
{
    int t[NMAX1+NMAX2], t1[NMAX1], t2[NMAX2], val1, val2, k;

    /* lecture des valeurs des deux ensembles 
    à fusionner */

    printf("Combien de valeurs pour le premier tableau ? ");
    scanf("%d", &val1);
    if (val1 > NMAX1) val1 = NMAX1 ;
    printf("Donnez vos valeurs\n");
    for (k=0; k<val1; k++)
        scanf("%d", &t1[k]) ;
    
    printf("Combien de valeurs pour le second tableau ? ");
    scanf("%d", &val2);
    if (val1 > NMAX2) val2 = NMAX2 ;
    printf("Donnez vos valeurs\n");
    for (k=0; k<val2; k++)
        scanf("%d", &t2[k]) ;

    // tris des tableaux à fusionner
    tri_bulle(t1, val1);
    tri_bulle(t2, val2);

    // affichage des valeurs triées à fusionner
    printf("\nPremier tableau a fusionner\n");
    for (k=0; k<val1; k++)
        printf("%5d", t1[k]) ;
    printf("\nSecond tableau a fusionner\n");
    for (k=0; k<val2; k++)
        printf("%5d", t2[k]) ;

    // fusion des tableaux et affichage
    fusion(t, t1, t2, val1, val2) ;
    printf("\n\nResultat de la fusion des deux tableaux\n") ;
    for (k=0; k<val1+val2; k++)
        printf("%5d", t[k]) ;

    return 0;
}