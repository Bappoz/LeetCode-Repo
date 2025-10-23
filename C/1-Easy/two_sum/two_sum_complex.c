
// Achando uma solução com complexidade menor que O(n^2)
// Usando Tabela Hash


#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    // Funcionaria como um dicionário
    int chave; // "chave" refere-se nesse exercício ao valor da array, ex: vetor[1] = 50
    int data; // "data" refere-se nesse exercício ao índice do array, ou seja, no exemplo vertor[1], data seria 1.
    struct Node* next;
} Node;

typedef struct hashTable{
    int size;
    Node** bucket;
} hashTable;


hashTable* crete_table(int size){
    hashTable* table = malloc(sizeof(hashTable));
    if(table == NULL) return NULL;
    table->size = size;

    table->bucket = calloc(size, sizeof(Node*));
    if(table->bucket == NULL) {
        free(table); 
        return NULL;
    }
    
    return table;
}

int hash_function(int chave, int size){
    int index = chave % size;

    return (index < 0) ? (index + size) : index;
}

void free_table(hashTable* table){
    if(table == NULL) return;

    // Aqui estarei liberando a memória para cada nó de cada lista encadeada de cada espaço armazenado da tabela hash
    for(int i = 0; i < table->size; i++){
        Node* current_list = table->bucket[i];

        while(current_list != NULL){
            Node* tmp = current_list;
            current_list = current_list->next; // Próximo nó do vetor da lista encadeada
            free(tmp);
        }
    }
    free(table->bucket);
    free(table);
}

void put(hashTable* table, int chave, int data){
    int index = hash_function(chave, table->size);

    Node* newNode = malloc(sizeof(Node));
    if(newNode == NULL) return;

    newNode->chave = chave;
    newNode->data = data;

    newNode->next = table->bucket[index];
    table->bucket[index] = newNode;

}

int get(hashTable* table, int chave){
    // Descobrir qual o bucket está armazenado de acordo com o hash_function
    int index = hash_function(chave, table->size);

    //Pegar o começo da corrente
    Node* current = table->bucket[index];
    
    while(current != NULL){
        if(current->chave == chave){
            return current->data;
        }
        current = current->next;
    }

    return -1;
}




int* twoSum(int* nums, int numsSize, int target, int* returnSize){

    const int tableSize = 1021;
    hashTable* table = crete_table(tableSize);
    if(table == NULL){
        *returnSize = 0; 
        return NULL;
    } 

    for(int i = 0; i < numsSize; i++){
        
        int complement = target - nums[i];

        int complement_index = get(table, complement);
        if(complement_index != -1){
            int* result = malloc(sizeof(int) * 2);
            if(result == NULL){
                *returnSize = 0;
                free_table(table);
                return NULL;
            }

            result[0] = complement_index;
            result[1] = i;
            *returnSize = 2;

            free_table(table);
            return result;
        }
        
        put(table, nums[i], i);   
    }

    free_table(table);
    *returnSize = 0;
    return NULL;

}

int main(){
    int numsSize;
    printf("Entre uma valor inteiro para o tamanho do vetor: ");
    scanf("%d", &numsSize);

    int *nums = malloc(numsSize * sizeof(int));
    if(nums == NULL) return 1;


    for (size_t i = 0; i < numsSize; i++)
    {
        printf("Numero %zu do vetor: ", i);
        scanf("%d", &nums[i]);
    }
    
    
    int target;
    printf("Selecione um target: ");
    scanf("%d", &target);
    
    int returnSize;
    int *resposta; 

    resposta = twoSum(nums, numsSize, target, &returnSize);

    if (returnSize == 2) {
        printf("\nIndices encontrados: [%d, %d]\n", resposta[0], resposta[1]);
    } else {
        printf("\nNenhuma solucao encontrada.\n");
    }

    // Libera a memória alocada pela 'main' e pela 'twoSum'
    free(nums);
    free(resposta); 

    return 0;
}
