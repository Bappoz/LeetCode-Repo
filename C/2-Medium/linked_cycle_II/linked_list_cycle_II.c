#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) break;
    }

    if(!fast|| !fast->next) return NULL;


    slow = head;
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}