#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE* fic = fopen("exercice_3.c", "r");
    int character = 0;
    if (fic == NULL) exit(1);

    do {
        character = fgetc(fic);
        printf("%c", character);
    } while(character != EOF);

    fclose(fic);

    return 0;
}
