#include<stdio.h>
#include<malloc.h>
    // Tipo abstrato de dado
typedef struct temp{
    int dado;
    struct temp *nextEl;
} stack;
stack *top, *newEl;

void push(int e){
    newEl = (stack*)malloc(sizeof(stack));
    newEl->dado = e;

    if(top == NULL) newEl->nextEl = NULL;
    else newEl->nextEl = top;

    top = newEl;
}

void pop(){

    if(top == NULL) return;
    else {
        newEl = top;
        top = top->nextEl;
        free(newEl);
    }
}

void printElements(){
    if(top==NULL)return;

    newEl = top;
    printf("\n Topo \n |\n V");

    while(newEl!=NULL){
        printf("\n %d \n |\n V",newEl->dado);
        newEl=newEl->nextEl;
    }
    printf("\n NULL");
}

int main (){
    top = NULL;

    int op, n;

    do {
        printf("\n 1- Empilhar \t 2- Desempilhar \t 3- Listar \t 4- Sair");
        printf("\n");
        scanf("%d", &op);

        switch(op){
            case 1:
                printf("\n Dado:");
                scanf("%d", &n);
                push(n);
                break;
            case 2:
                pop();
                break;
            case 3:
                printElements();
                break;
            case 4:
                exit(0);
            default:
                printf("\n Operacao invalida!");
        }
    }while(op!=4);
}
