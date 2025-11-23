#include <stdio.h>
#include <stdlib.h>

struct ListNode{
    int val;
    struct ListNode *next;
};


struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* slow = malloc(sizeof(struct ListNode));
    struct ListNode* fast = malloc(sizeof(struct ListNode));
    fast = head;
    slow = head;
    
    while(fast->next != NULL){
        if(fast->next->next == NULL && fast->next != NULL){
            fast = fast->next;
            slow = slow->next; 
            break;
        }
        slow = slow->next; // Slow is the middle
        fast = fast->next->next;
    }   
    return slow;
}