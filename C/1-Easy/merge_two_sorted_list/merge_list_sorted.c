#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
    int val; // Valor 
    struct ListNode *next;
} ListNode;

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){

    ListNode* dummyHead = (ListNode*)malloc(sizeof(ListNode));
    dummyHead->next = NULL;
    
    ListNode* current = dummyHead;

    while( list1 != NULL && list2 != NULL){
        if(list1->val < list2-> val){
            current->next = list1;
            list1 = list1->next;
        }
        else{
            current->next = list2;
            list2 = list2->next;
        }

        current = current->next;
    }

    // Se ainda sobrar valores na array adiciona elas do jeito que está no next do current
    if(list1 != NULL) current->next = list1;
    else current->next = list2;

    ListNode* head = dummyHead->next;
    free(dummyHead);

    return head;
}

ListNode* newNode(int val){
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

void printList(ListNode* head){
    while(head != NULL){
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
} 


int main(){

    ListNode* list1 = newNode(1);
    list1->next = newNode(2);
    list1->next->next = newNode(4);

    ListNode* list2 = newNode(1);
    list2->next = newNode(3);
    list2->next->next = newNode(4);

    // Mescla
    ListNode* merged = mergeTwoLists(list1, list2);

    // Imprime
    printList(merged);

    return 0;
}
