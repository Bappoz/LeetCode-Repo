#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* oddEvenList(struct ListNode* head) {
    if(!head || !head->next) return head;

    struct ListNode* impar = head;
    struct ListNode* par = head->next;
    struct ListNode* parHead = par;

    while(par && par->next){
        impar->next = par->next;
        impar = impar->next;

        par->next = impar->next;
        par = par->next;
    }
    impar->next = parHead;
    return head;
}