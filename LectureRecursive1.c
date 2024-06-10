#include <stdio.h>

#define N 20

void lecture(int *p)
{
    int cpt;
    char ligne[N+1];

    fgets(ligne,N,stdin);
    cpt = sscanf(ligne, "%d", p);
    if (!cpt)
    {
        printf("** réponse incorrecte - redonnez-la : ");
        lecture(p);
    }
}

int main()
{
    void lecture(int *);
    int n;

    printf("donnez un nombre entier : ");
    lecture(&n);
    printf("-- merci pour %d", n);
    
    return 0;
}