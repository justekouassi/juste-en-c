#include "numbers.h"
#include <stdio.h>
#include <stdlib.h>

void menu(void) {
    printf("1. Addition\n2. Soustraction\n3. Multiplication\n4. Division\n\n5. Quitter le programme\n");
    printf("------------------------------------\n\n");
}

float addition(float a, float b) {
    return a + b;
}
float soustraction(float a, float b) {
    return a - b;
}
float multiplication(float a, float b) {
    return a * b;
}
float division(float a, float b) {
    if (b==0) {
        printf("Division par 0 impossible");
        exit(1);
    }
    return a / b;
}

void operation(int choice) {
    float a, b, resultat;
    printf ("Entrez deux nombres : ");
    scanf("%f %f", &a, &b) ;
    if (choice == 1) resultat = addition(a, b);
    else if (choice == 2) resultat = soustraction(a, b);
    else if (choice == 3) resultat = multiplication(a, b);
    else if (choice == 4) resultat = division(a, b);
    printf("\nResultat = %f\n", resultat);
}