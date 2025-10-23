#include <stdio.h>
#include <stdlib.h>

// Dont Forget => Vetores de inteiros não tem \n no final!!

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 0;
    int *resposta = malloc(sizeof(int)*2);

    if(nums == NULL || numsSize == 0){
        free(resposta);
        *returnSize = 0;
        return NULL;
    }

    for(int i = 0; i < numsSize; i++){
        for(int j = i+1; j < numsSize; j++){
            if(nums[i] + nums[j] == target){
                resposta[0] = i;
                resposta[1] = j;
                *returnSize = 2;
                return resposta;
            }
        }
    }
    free(resposta);
    *returnSize = 0;
    return NULL;
}

int main(){
    int numsSize;
    scanf("%d", &numsSize);
    int nums[numsSize];
    for (size_t i = 0; i < numsSize; i++)
    {
        printf("Numero %d do vetor: ", i);
        scanf("%d", &nums[i]);
        printf("\n");
    }
    
    
    int target;
    printf("Selecione um target: ");
    scanf("%d", &target);
    int returnSize;
    int *resposta;
    resposta = twoSum(nums, numsSize, target, &returnSize);

    printf("\n%d\n", returnSize);
    printf("[");
    for(int i =0; i < returnSize; i++){
        printf("%d,", resposta[i]);
    }
    printf("]");

    free(resposta);
    return 0;
}