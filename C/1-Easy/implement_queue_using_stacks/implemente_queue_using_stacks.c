#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct Node{
    int data;
    struct Node *next;
} Node;

typedef struct Stack{    
    int size;
    Node *topNode;
} Stack;

typedef struct MyQueue{
    Stack in;
    Stack out;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue *q = malloc(sizeof(MyQueue));
    if(q == NULL) return NULL;

    q->in.size = 0;
    q->in.topNode = NULL;
    
    q->out.size = 0;
    q->out.topNode = NULL;

    return q;
}

bool is_empty(Stack *s){
    return s->size == 0;
}

void push(Stack *s, int val){
    Node* newNode = malloc(sizeof(Node));
    if(newNode == NULL) return;

    newNode->data = val;
    newNode->next = s->topNode;
    s->topNode = newNode;
    
    s->size++;
}

int pop(Stack *s){
    if(is_empty(s)) return 0;

    Node* oldNode = s->topNode;
    int val_tmp = oldNode->data;
    s->topNode = s->topNode->next;
    free(oldNode);
    
    s->size--;
    return val_tmp;
}

int peek(Stack *s){
    return s->topNode->data;
}

void free_stack(Stack *s){
    if(is_empty(s)) return;

    Node *curr = s->topNode;
    Node* tmp;

    while(curr != NULL){
        tmp = curr->next;
        free(curr);
        curr = tmp;
    }
}

void myQueuePush(MyQueue* obj, int x) {
    push(&obj->in, x);
}

int myQueuePop(MyQueue* obj) {
    if(is_empty(&obj->out)){
        while(!is_empty(&obj->in)){
            int in_value = pop(&obj->in);
            push(&obj->out, in_value);
        }
    }
    return pop(&obj->out);
}

int myQueuePeek(MyQueue* obj) {
    if(is_empty(&obj->out)){
        while(!is_empty(&obj->in)){
            int v = pop(&obj->in);
            push(&obj->out, v); 
        }
    }
    return peek(&obj->out);
}

bool myQueueEmpty(MyQueue* obj) {
    return is_empty(&obj->in) && is_empty(&obj->out);
}

void myQueueFree(MyQueue* obj) {
    free_stack(&obj->in);
    free_stack(&obj->out);
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/