#include <stdio.h>
#include <malloc.h>

typedef struct temp
{
    int data;
    struct temp *nextEl;
} circular_queue;
circular_queue *rear, *front, *new;

void enqueue(int n)
{
    if (n < 0)
        return;

    new = (circular_queue *)malloc(sizeof(circular_queue));
    new->data = n;

    if (front == NULL)
        front = rear = new;
    else
        new->nextEl = front;

    rear->nextEl = new;
    rear = new;
}

void dequeue()
{
    if (front == NULL)
        return;

    if (front == rear)
    {
        free(front);
        front = rear = NULL;
        return;
    }

    rear->nextEl = front->nextEl;
    free(front);
    front = rear->nextEl;
}

void showElements()
{
    if (front == NULL)
        return;

    printf("\n\n");
    new = front;
    do
    {
        printf(" %d-> ", new->data);
        new = new->nextEl;
    } while (new != front);
}

int main()
{
    front = NULL;
    int op, n;

    do
    {
        printf("\n 1- Inserir elemento \t 2- Remover elemento \t 3- Listar \t 4- Limpar Console \t 5- Sair");
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
