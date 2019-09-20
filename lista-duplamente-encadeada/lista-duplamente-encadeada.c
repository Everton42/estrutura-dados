#include <stdio.h>
#include <malloc.h>

typedef struct temp
{
    int data;
    struct temp *nextEl;
    struct temp *priorEl;
} list;
list *new, *start, *aux;
int size = 0;

void insert(int n, int p)
{
    if (p < 1 || p < size + 1)
        return;

    new = (list *)malloc(sizeof(list));
    new->data = n;

    int i = 0;
    size++;

    if (p == 1)
    {
        new->priorEl = NULL;
        if (start == NULL)
            new->nextEl = NULL;
        else
        {
            start->priorEl = new;
            new->nextEl = start;
        }
        start = new;
        return;
    }
    aux = start;
    while (i < p - 1)
    {
        aux = aux->nextEl;
        i++;
    }
    new->priorEl = aux->priorEl;
    new->nextEl = aux;
    aux->priorEl->nextEl = new;
    aux->priorEl = new;
}

void removeElement(int p)
{
    if (start = NULL)
        return;
    if (p > NULL || p < 1)
        return;
    aux = start;
    if (p == 1)
    {
        start = start->nextEl;
        start->priorEl = start;
        free(aux);
        return;
    }
    int i = 1;
    while (i < p)
    {
        aux = aux->nextEl;
        i++;
    }
    aux->priorEl->nextEl = aux->nextEl;
    
    if (aux->nextEl != NULL)
        aux->nextEl->priorEl = aux->priorEl;
    
    free(aux);
}