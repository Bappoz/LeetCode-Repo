#include <stdio.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode** splitListToParts(struct ListNode* head, int k, int* returnSize) {


    struct ListNode** parts = calloc(k, sizeof(struct ListNode*));
    if(parts == NULL) return NULL;

    struct ListNode* curr = head;

    int contador = 0;
    while(curr != NULL){
        contador++;
        curr = curr->next;
    }
    curr = head;

    if(contador <= k){

        int j = 0; 
        while(curr != NULL && j < k){
            
            parts[j] = curr;
            struct ListNode* proximo = curr->next;
            curr->next = NULL;

            curr = proximo;
            j++;
        }

        for(; j < k; j++){
            parts[j] = NULL;
        }

        *returnSize = k;
    }

    else{
        *returnSize = k;
        return parts;
    }

    return parts;
}