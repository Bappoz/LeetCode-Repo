#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct Node{
    int val;
    struct Node *next; 
} Node;

typedef struct MyStack{
    Node *head;
    Node *tail;
    int size;
} MyStack;


MyStack* myStackCreate() {
    
    MyStack *q = (MyStack *)malloc(sizeof(MyStack));
    if( q == NULL ) return NULL;

    q->head = NULL;
    q->tail = NULL;
    q->size = 0;

    return q;
}

bool myStackEmpty(MyStack* q) {
    return q->size == 0;
}

void enqueue(MyStack* q, int x) {
    Node* newNode = malloc(sizeof(Node));
    newNode->val = x;
    newNode->next = NULL;

    if (myStackEmpty(q)) {
        q->head = newNode;
        q->tail = newNode;
    } else {
        q->tail->next = newNode;
        q->tail = newNode;
    }

    q->size++;
}

/* dequeue normal da fila */
int dequeue(MyStack* q) {
    if (myStackEmpty(q)) return -1;

    Node* old = q->head;
    int v = old->val;

    q->head = q->head->next;
    if (q->head == NULL)
        q->tail = NULL;

    free(old);
    q->size--;

    return v;
}



void myStackPush(MyStack* q, int x) {
    enqueue(q, x);

    for(int i = 0; i < q->size - 1; i++){
        int tmp = dequeue(q);
        enqueue(q, tmp);
    }

}

int myStackPop(MyStack* q) {
    return dequeue(q);
}

int myStackTop(MyStack* q) {
    if(myStackEmpty(q)) return -1;
    return q->head->val;
}


void myStackFree(MyStack* q) {
    if(myStackEmpty(q)) return;

    while(!myStackEmpty(q)) {
        myStackPop(q);
    }
    free(q);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* q = myStackCreate();
 * myStackPush(q, x);
 
 * int param_2 = myStackPop(q);
 
 * int param_3 = myStackTop(q);
 
 * bool param_4 = myStackEmpty(q);
 
 * myStackFree(q);
*/