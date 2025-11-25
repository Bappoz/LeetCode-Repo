#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};



int getDecimalValue(struct ListNode* head) {
    
    struct ListNode *curr = head, *prev = NULL, *next;

    while(curr != NULL){

        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }

    int binary_int = 0;
    int power = 0;
    while(prev != NULL){

        binary_int += prev->val * pow(2, power);
        prev = prev->next;
        power++;
    }

    return binary_int;
}