#include <stdio.h>
#include <stdlib.h>

void main()
{
int i, N;

struct Polygone
{
    float abs, ord;
    struct Polygone *suiv;
};

printf("Nombre de sommets : ");
scanf("%d", N);

struct Polygone *Tpoly;
Tpoly = malloc(N*sizeof(struct Polygone));

for(i=0; i<N; i++) {
    scanf("%f %f", &Tpoly[i].abs, &Tpoly[i].ord);
}

struct Polygone *creerPoly(struct Polygone * Tpoly)
{
    struct Polygone *Ptete = malloc(sizeof(struct Polygone));
    Ptete->abs = Tpoly[0].abs;
    Ptete->ord = Tpoly[0].ord;
    struct Polygone *prec = Ptete;

    struct Polygone *ptr = malloc(sizeof(struct Polygone));
    for (i = 1; i < N; i++)
    {
        Ptete->abs = Tpoly[i].abs;
        Ptete->ord = Tpoly[i].ord;
        prec->suiv = ptr;
        prec = ptr;
    }
    prec->suiv = Ptete;
    return Ptete;
}
}
