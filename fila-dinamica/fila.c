#include <stdio.h>
#include <malloc.h>
typedef struct temp
{
    int data;
    struct temp *nextEl;
} queue;
queue *front, *rear, *helper;

void enqueue(int e)
{
    helper = (queue *)malloc(sizeof(queue));
    helper->data = e;

    if (front == NULL)
        front = helper;
    else
        rear->nextEl = helper;

    rear = helper;
    helper->nextEl = NULL;
}

void dequeue()
{
    if (front == NULL)
        return;
    else
    {
        helper = front;
        front = front->nextEl;
        free(helper);
    }
}

void printElements()
{
    if (front == NULL)
        return;

    helper = front;
    printf("\n Inicio");

    while (helper != NULL)
    {
        printf("->[%d]", helper->data);
        helper = helper->nextEl;
    }
    printf("->NULL");
}

int main()
{
    front = NULL;
    int op, n;

    do
    {
        printf("\n 1- Enfileirar \t 2- Desenfileirar \t 3- Listar \t 4- Sair");
        printf("\n");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("\n valor:");
            scanf("%d", &n);
            enqueue(n);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            printElements();
            break;
        case 4:
            exit(0);
        default:
            printf("\n Operacao invalida!");
        }
    } while (op != 4);
}
