#include <stdio.h>
#include <stdlib.h>

main(int argc, char* argv[]) {
    argc--; argv++;
    int sum=0;
    while (argc != 0) {
        sum += atoi(*argv++);
        argc--;
    }
    printf("La somme des valeurs saisies à l'écran est : %d.\n", sum);
}
