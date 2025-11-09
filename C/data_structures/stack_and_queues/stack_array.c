/*
Geral: Pilha ou stack é uma forma de implementar regras de movimentação em uma array ou Lista encadeada
        ** Last in, First Out **

Operações possíveis de fazer com stack
    - Checar se um stack está vazia (contém nenhum item)
    - checar se uma stack chegou em seu limite
    - "Dar uma olhada" (peek) o valor que está no topo da stack com O(1)
    - Posso criar e destruir a stack (do ultimo até o primeiro (nessa ordem))
*/ 


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Stack{
    int *collection;
    int capacity;
    int size;
} Stack;


Stack *create_stack(int capacity){
    if(capacity <= 0) return NULL;

    Stack *stack = malloc(sizeof(Stack));
    if(stack == NULL) return NULL;

    stack->collection = malloc(sizeof(int) * capacity);
    if (stack->collection == NULL) {
        free(stack);
        return NULL;
    }

    stack->capacity = capacity;
    stack->size = 0;

    return stack;
}

void destroy_stack(Stack *stack){
    free(stack->collection);
    free(stack);
}

bool is_full(Stack *stack){
    return stack->size == stack->capacity;
}

bool is_empty(Stack *stack){
    return stack->size == 0;
}

bool pop(Stack *stack, int *item){
    if(is_empty(stack))return false;

    stack->size--;
    *item = stack->collection[stack->size];

    return true;
}

bool push(Stack *stack, int item){
    if(is_full(stack)) return false;
    
    stack->collection[stack->size] = item;
    stack->size++;

    return true;
}

bool peek(Stack *stack, int *item){
    if(is_empty(stack)) return false;
    
    *item = stack->collection[stack->size - 1]; 
    return true;
}




int main(){

    Stack *stack = create_stack(4);
    if(stack == NULL){
        return 1;
    }

    if (is_empty(stack)) printf("Stack is empty");
    
    push(stack, 2);
    printf("Stack Size %d\n", stack->size);
    
    if (is_empty(stack)) printf("Stack is empty");
    
    destroy_stack(stack);


    return 0;;
}