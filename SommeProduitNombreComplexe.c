#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double reel;
    double imag;
} complexe ;

void somme(complexe *x, complexe *y, complexe *som)
{
    som->reel = x->reel + y->reel ;
    som->imag = x->imag + y->imag ;
}

void produit(complexe *x, complexe *y, complexe *prod)
{
    prod->reel = (x->reel * y->reel) - (x->imag * y->imag) ;
    prod->imag = (x->reel * y->imag) + (x->imag * y->reel) ;
}

int main()
{
    complexe z1, z2, s, p ;
    /*
    printf("Calculs de la somme et du produit de \nz1 = a+ib et z2 = c+id\n");
    printf("a = ");
    scanf("%f", z1.reel);
    printf("b = ");
    scanf("%f", z1.imag);
    printf("c = ");
    scanf("%f", z2.reel);
    printf("d = ");
    scanf("%f", z1.imag);
    */
    z1.reel = 0.5 ; z1.imag = 1.0 ;
    z2.reel = 2.0 ; z2.imag = 1.0 ;
    somme(&z1, &z2, &s) ;
    produit(&z1, &z2, &p) ;

    printf("%f + %f i  et  %f + %f i \n", z1.reel, z1.imag, z2.reel, z1.imag) ;
    printf("ont pour somme %f + %f i \n", s.reel, s.imag) ;
    printf("et pour produit %f + %f i \n", p.reel, p.imag) ;

    return 0;
}