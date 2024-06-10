#include <stdio.h>
#include "numbers.h"

void app(void) {
    int choice = 0;
    float a, b;
    do {
        menu();
        scanf("%d", &choice);
        switch(choice) {
            case 1 :
                operation(choice);
                break;
            case 2 :
                operation(choice);
                break;
            case 3 :
                operation(choice);
                break;
            case 4 :
                operation(choice);
                break;
            case 5 :
                break;
            default : 
                printf("Option incorrecte !\n");
                break;
        }
    } while(choice != 5) ;
}

int main(void) {
    app() ;
    return 0;
}