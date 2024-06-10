#include <stdio.h>

#define N 20

int lecture(void)
{
    int cpt, p;
    char ligne[N+1];

    fgets(ligne,N,stdin);
    cpt = sscanf(ligne, "%d", &p);
    if (!cpt)
    {
        printf("** réponse incorrecte - redonnez-la : ");
        p = lecture();
    }
    return (p);
}

int main()
{
    int lecture(void); 
    int n;
    
    printf("donnez un nombre entier : ");
    n = lecture();
    printf("-- merci pour %d", n);
    
    return 0;
}