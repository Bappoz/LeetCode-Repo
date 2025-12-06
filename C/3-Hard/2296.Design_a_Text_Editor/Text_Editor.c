#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char c;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct TextEditor{
    Node* cursor;
    Node* head;
    int size;
} TextEditor;


TextEditor* textEditorCreate() {
    TextEditor* TE = malloc(sizeof(TextEditor));
    if(TE == NULL) return NULL;

    TE->head = TE->cursor = NULL;
    TE->size = 0;
    return TE;
}

void addCharToTE(TextEditor* TE, char c){
    Node* newNode = malloc(sizeof(Node));
    newNode->c = c;
    newNode->next = NULL;
    newNode->prev = NULL;

    if(TE->cursor == NULL){
        newNode->next = TE->head;
        if(TE->head != NULL) TE->head->prev = newNode;
        TE->head = newNode;
        TE->cursor = newNode;
    }
    else{
        newNode->next = TE->cursor->next;
        newNode->prev = TE->cursor;

        if(TE->cursor->next != NULL){
            TE->cursor->next->prev = newNode;
        }
        TE->cursor->next = newNode;
        TE->cursor = newNode;
    }
    TE->size++;
}

void textEditorAddText(TextEditor* TE, char* text) {
    if(TE == NULL) return;
    int size = strlen(text);

    for(int i = 0; i < size; i++){
        addCharToTE(TE, text[i]);
    }
}

void deleteNode(TextEditor* TE){
    if(TE->cursor == NULL || TE->size == 0) return;
    Node* tmp = TE->cursor;

    if(tmp->prev){
        tmp->prev->next = tmp->next;
    }
    else TE->head = tmp->next;

    if(tmp->next) tmp->next->prev = tmp->prev;

    TE->cursor = tmp->prev;
    free(tmp);
    TE->size--;
}

int textEditorDeleteText(TextEditor* TE, int k) {
    int deletados = 0;
    if(TE->cursor == NULL || TE->size == 0 || TE->head == NULL) return deletados;
    while(k-- > 0 && TE->cursor){
        deleteNode(TE);
        deletados++;
    }
    return deletados;
}

void moveLeft(TextEditor* TE){
    if(!TE->cursor) return;
    TE->cursor = TE->cursor->prev;
}

void moveRight(TextEditor* TE){
    if(!TE->cursor){
        if(TE->head) TE->cursor = TE->head;
        return;
    }
    if(!TE->cursor->next) return;
    TE->cursor = TE->cursor->next;
}

char* textEditorCursorLeft(TextEditor* TE, int k) {
    while(k-- > 0 && TE->cursor){
        moveLeft(TE);
    }
    char* result = malloc(sizeof(char) * 11);
    Node* tmp = TE->cursor;
    int j = 0;
    for(; j < 10 && tmp;){
        result[j++] = tmp->c;
        tmp = tmp->prev;
    }

    //Inverter a lista:
    for(int k = 0; k < j/2; k++){
        char t = result[k];
        result[k] = result[j - k - 1];
        result[j - k - 1] = t;
    }
    
    result[j] = '\0';

    return result;
}

char* textEditorCursorRight(TextEditor* TE, int k) {
    while(k-- > 0){
        moveRight(TE);
    }
    char* result = malloc(sizeof(char) * 11);
    Node* tmp = TE->cursor;
    
    int j = 0;
    for(; j < 10 && tmp;){
        result[j++] = tmp->c;
        tmp = tmp->prev;
    }
    //Inverter a lista:
    for(int k = 0; k < j/2; k++){
        char t = result[k];
        result[k] = result[j - k - 1];
        result[j - k - 1] = t;
    }
    
    result[j] = '\0';

    return result;
}

void textEditorFree(TextEditor* TE) {
    if(!TE) return;
    Node* curr = TE->head;
    while(curr){
        Node* prox = curr->next;
        free(curr);
        curr = prox;
    }
    free(TE);
}
