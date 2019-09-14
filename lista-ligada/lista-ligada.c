#include <stdio.h>
#include <malloc.h>

typedef struct temp
{
    int data;
    struct temp *nextEl;
} list;
list *start, *newEl, *aux;
int listSize;

void insertElement(int pos, int d)
{
    if (pos < 1 || pos > listSize + 1)
    {
        printf("Posicao invalida");
        return;
    }

    newEl = (list *)malloc(sizeof(list));
    newEl->data = d;

    listSize++;

    if (pos == 1)
    {
        insertFirstEl();
        return;
    }

    moveAux(pos);

    newEl->nextEl = aux->nextEl;
    aux->nextEl = newEl;
}

void insertFirstEl()
{
    if (start == NULL)
        newEl->nextEl = NULL;
    else
        newEl->nextEl = start;

    start = newEl;
}

void removeElement(int pos)
{
    if (pos < 1 || pos > listSize)
        return;

    if (pos == 1)
    {
        removeFirstEl();
        return;
    }

    moveAux(pos);

    newEl = aux->nextEl;
    aux->nextEl = newEl->nextEl;
    free(newEl);
    listSize--;
}

void removeFirstEl()
{
    aux = start;
    start = start->nextEl;
    free(aux);
    listSize--;
}

void moveAux(int p)
{
    int i = 1;
    aux = start;

    while (i < p - 1)
    {
        aux = aux->nextEl;
        i++;
    }
}

void showElements()
{
    printf("Start");
    aux = start;

    int i = 0;
    while (i <= listSize)
    {
        printf("->%d", aux->data);
        aux = aux->nextEl;
        i++;
    }
}

int main()
{
    start = NULL;
    int op, d, p;

    do
    {
        printf("\n 1- Inserir elemento \t 2- Remover elemento \t 3- Listar \t 4- Limpar Console \t 5- Sair");
        printf("\n");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("\n valor:");
            scanf("%d", &d);
            printf("\n posicao:");
            scanf("%d", &p);
            insertElement(p, d);
            break;
        case 2:
            printf("\n posicao:");
            scanf("%d", &p);
            removeElement(p);
            break;
        case 3:
            showElements();
            break;
        case 4:
            system("cls");
            break;
        case 5:
            exit(0);
        default:
            printf("\n Operacao invalida!");
        }
    } while (op != 5);
}
