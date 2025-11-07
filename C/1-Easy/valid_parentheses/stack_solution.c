#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Stack{
    char *collection;
    int size;
    int capacity;
} Stack;

Stack* create_stack(int capacity){
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    if(stack == NULL) return NULL;

    stack->collection = malloc(sizeof(char)*capacity);
    if(stack->collection == NULL){
        free(stack);
        return NULL;
    }

    stack->capacity = capacity;
    stack->size = 0;

    return stack;
} 

void push(Stack* stack, char c){
    if(stack->size == stack->capacity){
        printf("Stack Capacity is already full!");
        return;
    }

    stack->collection[stack->size++] = c;
}

char pop(Stack* stack){
    stack->size--;
    return stack->collection[stack->size];
}
    


bool isValid(char* s) {
    int char_size = strlen(s);

    Stack* stack = create_stack(char_size);
    
    for(int i = 0; i < char_size; i++){
        char c = s[i];

        if(c == '(' || c == '{' || c == '['){
            push(stack, c);
            continue;
        }

        if(c == ')' || c == '}' || c == ']'){

            if(stack->size == 0){
                return false;
            }
            char top_char = pop(stack); // retorna o valor apagado

            if(c == ')' && top_char != '(' || c == '}' && top_char != '{' || c == ']' && top_char != '['){
                return false;
            }
        }
    
    }

    if(stack->size == 0) return true;
    free(stack->collection);
    free(stack);

    return false;
}