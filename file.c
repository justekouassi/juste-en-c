#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Structure d'une file
typedef struct QueueElement
{
    int value;
    struct QueueElement *next;
} QueueElement, *Queue;

//Prototypes de fonctions

Queue new_queue(void);
bool is_empty_queue(Queue q);
void print_queue(Queue q);
Queue push_queue(Queue q, int x);
Queue pop_queue(Queue q);
int top_queue(Queue q);
int queue_length(Queue q);

/*****************************************************/

//Créer une nouvelle file
Queue new_queue(void)
{
    return NULL;
}

/*****************************************************/

//Vérifier si la file est vide
bool is_empty_queue(Queue q)
{
    if (q == NULL)
        return true;
    return false;
}

/*****************************************************/

// Affiche le contenu de la file
void print_queue(Queue q)
{
    QueueElement *temp;

    if (is_empty_queue(q))
    {
        puts("La file est vide\n");
        //return;
    }

    temp = q;
    temp = temp->next;

    printf("<---");
    while (temp != q)
    {
        printf("[%d] --", temp->value);
        temp = temp->next;
    }
    printf("[%d] -- |\n", temp->value);
}

/*****************************************************/

// Enfiler
Queue push_queue(Queue q, int x)
{
    QueueElement *element;
    element = (QueueElement*) malloc(sizeof(QueueElement));

    if (element == NULL)
    {
        puts("Problème d'allocation de mémoire\n");
        exit(EXIT_FAILURE);
    }

    element->value = x; // (*element).value = x
    
    if (is_empty_queue(q))
    {
        element->next = element;
        return element;
    }

    element->next = q->next;
    q->next = element;

    return element;
}

/*****************************************************/

// Défiler
Queue pop_queue(Queue q)
{
    QueueElement *element;

    if (is_empty_queue(q))
    {
        puts("La pile est vide\n");
        exit(1);
    }
    
    if (q == q->next)
    {
        free(q);
        q=NULL;
        return new_queue();
    }

    element = q->next;
    q->next = element->next;

    free(element);
    element = NULL;

    return q;
}

/*****************************************************/

// Sommet de la file
int top_queue(Queue q)
{
    Queue temp;
    if (is_empty_queue(q))
    {
        puts("La file est vide\n");
        exit(1);
    }
    temp = q;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    return temp->value; 
}

/*****************************************************/

//Longueur de la pile
int queue_length(Queue q)
{
    int length = 0;
    while (q != NULL)
    {
        ++length;
        q = q->next;
    }
    return length;
}

/*****************************************************/

// Programme principal
int main(void)
{
    Queue q;
    q = new_queue();
    print_queue(q);
    q = push_queue(q, 45);
    q = push_queue(q, 7);
    q = push_queue(q, 69);
    print_queue(q);
    /*
    
    q = pop_queue(q);
    print_queue(q);
    q = push_queue(q, 69);
    q = push_queue(q, 1);
    q = push_queue(q, 19);
    q = push_queue(q, 35);
    q = pop_queue(q);
    q = pop_queue(q);
    print_queue(q);
    */
    printf("\nLe sommet de la file est : %d\n", top_queue(q));
    printf("\nLongueur de la file est : %d\n", queue_length(q));

    system("PAUSE");
    return EXIT_SUCCESS;
}