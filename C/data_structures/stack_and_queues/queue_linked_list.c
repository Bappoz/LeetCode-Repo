#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct Node{
    int data;
    struct Node *next;
} Node;


typedef struct Queue{
    Node* head;
    Node* tail;
    int size;
} Queue;


Queue* create_queue(){
    Queue* q = malloc(sizeof(Queue));
    if(q == NULL) return NULL;

    q->head = NULL;
    q->tail = NULL;
    q->size = 0;

    return q;
}

int list_size(Queue* q){
    return q->size;
}

bool is_empty(Queue* q){
    return q->size == 0; 
}

void enqueue(Queue *q, int value){
    Node* newNode = malloc(sizeof(Node));

    newNode->data = value;
    newNode->next = NULL;
    
    if(is_empty(q)){
        q->head = newNode;
        q->tail = newNode;
    }
    else{
        q->tail->next = newNode;
        q->tail = newNode;        
    }

    q->size++;
}

int dequeue(Queue* q, bool* status){
    if(is_empty(q)){
        *status = false;
        return -1;
    }

    int tmp = q->head->data;
    
    Node* oldHead = q->head;
    
    if(q->size == 1){
        q->head = NULL;
        q->tail = NULL;

    }
    else{
        q->head = q->head->next;
    }
    
    free(oldHead);
    *status = true;
    q->size--;

    return tmp;
}

int peek(Queue* q, bool *status){
    if(is_empty(q)){
        *status = false;
    }
    
    *status = true; 
    return q->head->data;
    
}

bool destroy_queue(Queue* q){
    Node* curr = q->head;

    while(curr != NULL){
        
        Node* tmp = curr;
        curr = curr->next;
        free(tmp);
        q->size--;
    }

    free(q);
}

void printQueue(Queue* q){
    if(is_empty(q)) return;

    Node* curr = q->head;

    while(curr != NULL){
        printf("%d ", curr->data);
        curr = curr->next;

    }
}

int main(){

    Queue *queue = create_queue();
    if(queue == NULL){
        return -1;
    }

    if(is_empty(queue)) printf("queue is empty");

    enqueue(queue, 10);
    enqueue(queue, 25);
    enqueue(queue, 15);

    int size = list_size(queue);
    printf("\ntamanh Lista: ");
    printf(" %d", size);
    
    printf("\nLista: ");
    printQueue(queue);
    
    printf("\n");
    bool status = false;
    int valor_removido = dequeue(queue, &status);
    if(status) printf("removido: %d\n\n", valor_removido);
    else printf("Error ao remover!\n\n");

    printQueue(queue);
    

    return 0;
}