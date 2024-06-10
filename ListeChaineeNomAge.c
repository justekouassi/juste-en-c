#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

typedef struct Element
{
    char nom[N + 1];
    int age;
    struct Element *suivant;
} element;

void creation(element **adeb)
{
    char nomLu[N + 1];
    element *courant;

    *adeb = NULL;

    while (1)
    {
        printf("Nom : ");
        gets(nomLu);
        if (strlen(nomLu))
        {
            courant = (element *)malloc(sizeof(element));
            strcpy(courant->nom, nomLu);
            printf("Age : ");
            scanf("%d", &courant->age);
            getchar();
            courant->suivant = *adeb;
            *adeb = courant;
        }
        else
            break;
    }
}

void liste(element *debut)
{
    printf("\n\n  NOM       AGE\n\n");
    while (debut)
    {
        printf("%9s    %3d\n", debut->nom, debut->age);
        debut = debut->suivant;
    }
}

int main()
{
    void creation(element **);
    void liste(element *);
    element *debut;
    creation(&debut);
    liste(debut);
    return 0;
}