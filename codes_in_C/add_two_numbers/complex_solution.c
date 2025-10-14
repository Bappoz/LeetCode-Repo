#include <stdio.h>
#include <stdlib.h>


struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers( struct ListNode* l1, struct ListNode* l2){

    struct ListNode* tmp = (struct ListNode*)malloc(sizeof( struct ListNode ));
    struct ListNode* current = tmp;

    // Para fazer a soma binária e impedir overflow
    int carry  = 0;

    while(l1 != NULL || l2 != NULL || carry != 0){

        // Se for diferente de NULL(Acabou a lista), pega o valor do nó atual de l1 Caso contrário o valor é 0
        int val1 = (l1 != NULL) ?  l1->val : 0;
        int val2 = (l2 != NULL) ?  l2->val : 0;

        // Soma Binária
        int sum = val1 + val2 + carry;

        carry = sum / 10; // pega o carry para a proxuma iteração
        int new_digit = sum % 10;  // Pega o resto, que é o resultado da coluna

        current->next =(struct ListNode*)malloc(sizeof(struct ListNode));
        current->next->val =new_digit;
        current->next->next = NULL;

        current = current->next;

        if(l1 != NULL) l1 = l1->next;
        if(l2 != NULL) l2 = l2->next;

    }


    struct ListNode* result = tmp->next;

    free(tmp);
    free(l1);
    free(l2);

    return result;
}

void printList(struct ListNode* node) {
    printf("[");
    while (node != NULL) {
        printf("%d", node->val);
        if (node->next != NULL) {
            printf(", ");
        }
        node = node->next;
    }
    printf("]\n");
}

int main(){
    struct ListNode* l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1->val = 2;
    l1->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1->next->val = 4;
    l1->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1->next->next->val = 3;
    l1->next->next->next = NULL;

    // Criando a lista l2: 5 -> 6 -> 4
    struct ListNode* l2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l2->val = 5;
    l2->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l2->next->val = 6;
    l2->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l2->next->next->val = 4;
    l2->next->next->next = NULL;

    printf("Lista 1: ");
    printList(l1);
    printf("Lista 2: ");
    printList(l2);  
    printf("\n");
    
    struct ListNode* result = addTwoNumbers(l1, l2);
    
    printf("Resultado: ");
    printList(result);

    
}