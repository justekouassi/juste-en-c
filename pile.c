#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Structure d'une pile
typedef struct StackElement
{
    int value;
    struct StackElement *next;
} StackElement, *Stack;

//Prototypes de fonctions

Stack new_stack(void);
bool is_empty_stack(Stack st);
void print_stack(Stack st);
Stack push_stack(Stack st, int x);
Stack pop_stack(Stack st);
int top_stack(Stack st);
int stack_length(Stack st);

/*****************************************************/

//Créer une nouvelle pile
Stack new_stack(void)
{
    return NULL;
}

/*****************************************************/

//Vérifier si la pile est vide
bool is_empty_stack(Stack st)
{
    if (st == NULL)
        return true;
    return false;
}

/*****************************************************/

// Affiche le contenu de la pile
void print_stack(Stack st)
{
    if (is_empty_stack(st))
    {
        puts("La pile est vide\n");
        return;
    }

    printf("\n-------AFFICHAGE DE LA PILE\n");
    while (!is_empty_stack(st))
    {
        printf("[%d]\n", st->value);
        st = st->next;
    }
}

/*****************************************************/

// Empiler
Stack push_stack(Stack st, int x)
{
    StackElement *element;
    element = (StackElement*) malloc(sizeof(StackElement));

    if (element == NULL)
    {
        puts("Problème d'allocation de mémoire\n");
        exit(EXIT_FAILURE);
    }

    element->value = x; // (*element).value = x
    element->next = st;
}

/*****************************************************/

// Dépiler
Stack pop_stack(Stack st)
{
    StackElement *element;

    if (is_empty_stack(st))
    {
        puts("La pile est vide\n");
        exit(1);
    }

    element = st->next;
    free(st);

    return element;
}

/*****************************************************/

// Sommet de la pile
int top_stack(Stack st)
{
    if (is_empty_stack(st))
    {
        puts("La pile est vide\n");
        exit(1);
    }
    return st->value; 
}

/*****************************************************/

//Longueur de la pile
int stack_length(Stack st)
{
    int length = 0;
    while (st != NULL)
    {
        ++length;
        st = st->next;
    }
    return length;
}

/*****************************************************/

// Programme principal
int main(void)
{
    Stack st = new_stack();
    print_stack(st);
    st = push_stack(st, 45);
    st = push_stack(st, 7);
    st = push_stack(st, 69);
    print_stack(st);
    st = pop_stack(st);
    print_stack(st);
    printf("\nLe sommet de la pile est : %d\n", top_stack(st));
    printf("\nLongueur de la pile est : %d\n", stack_length(st));

    system("PAUSE");
    return 0;
}