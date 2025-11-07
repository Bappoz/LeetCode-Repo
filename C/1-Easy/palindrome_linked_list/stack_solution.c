#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct ListNode {
    int val;
    struct ListNode *next;
};


typedef struct Stack{
    struct ListNode* topNode;
} Stack;

Stack *create_stack(){
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    if(stack == NULL) return NULL;

    stack->topNode = NULL;
    return stack;
}

void push(Stack* stack, int value){
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    if(newNode == NULL) return;

    newNode->val = value;
    newNode->next = stack->topNode;
    stack->topNode = newNode;
}

bool is_empty(Stack* stack){
    return stack->topNode == NULL;
}

void pop(Stack* stack){
    if(is_empty(stack)) return;

    struct ListNode* tmp = stack->topNode;

    stack->topNode = stack->topNode->next;
    free(tmp);
}

void freeStack(Stack* stack){
    while(is_empty(stack) != true){
            
        struct ListNode *tmp = stack->topNode;
        stack->topNode = stack->topNode->next;
        free(tmp);
    }
    free(stack);
}

bool isPalindrome(struct ListNode* head) {
    struct ListNode* curr = head;
    Stack* stack = create_stack();

    while(curr != NULL){
        push(stack, curr->val);
        curr = curr->next;
    }
    curr = head;
    while(curr != NULL){
        if(curr->val != stack->topNode->val) return false;
        curr = curr->next;
        pop(stack);
    }

    freeStack(stack);

    return true;
}