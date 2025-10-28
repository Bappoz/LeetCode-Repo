#include <stdio.h>
#include <stdlib.h>

// Metódo: Primeiro Ordenar o vetor e depois fazer uma busca binário
// Complexidade: O(nlog(n))

typedef struct ParVI{
    int valor;
    int indice_original;
} ParVI;



void merge(ParVI* array, ParVI* leftArray, ParVI* rightArray, int numSize){
    int left_length = numSize/2;
    int right_length = numSize - left_length;
    
    int i = 0, l = 0, r = 0;
    
    while(l < left_length && r < right_length){
        if(leftArray[l].valor <= rightArray[r].valor){
            array[i] = leftArray[l];
            l++; i++;
        }
        else{
            array[i] = rightArray[r];
            r++; i++;
        }
    }
    // Ainda pode ser que sobre valores em algum vetor

    while(l < left_length){
        array[i] = leftArray[l];
        l++; i++;
    }
    while(r < right_length){
        array[i] = rightArray[r];
        r++; i++;
    }
    
    free(leftArray);
    free(rightArray);
}


void merge_sort(ParVI* array, int numSize){
    if(numSize <= 1 ) return;

    int middle = numSize/2;
    int left_length = middle;
    int right_length = numSize - middle;

    ParVI *leftArray = malloc(left_length*sizeof(ParVI));
    ParVI *rightArray = malloc(right_length*sizeof(ParVI));

    if(!leftArray || !rightArray){
        free(leftArray);
        free(rightArray);
        return;
    }

    int i = 0, j = 0;
    for(;i < numSize; i++){
        if(i < middle){
            leftArray[i] = array[i];
        }
        else{
            rightArray[j] = array[i];
            j++;
        }
    }

    merge_sort(leftArray, left_length);
    merge_sort(rightArray, right_length);
    merge(array, leftArray, rightArray, numSize);

}


int* twoSum(int* nums, int numsSize, int target, int* returnSize){

    ParVI* pares = malloc(numsSize * sizeof(ParVI));
    if(pares == NULL){
        *returnSize = 0;
        return NULL;
    } 

    
    for(int i = 0; i < numsSize; i++){
        pares[i].valor = nums[i];
        pares[i].indice_original = i;
    }
    
    merge_sort(pares, numsSize);

    int esquerda = 0;
    int direita = numsSize - 1;

    while(esquerda < direita){
        int soma = pares[esquerda].valor + pares[direita].valor;
        
        if(soma == target){
            int* result = malloc(sizeof(int) * 2);
            if(result == NULL){
                *returnSize = 0;
                return NULL;
            }
            
            *returnSize = 2;
            result[0] = pares[esquerda].indice_original;
            result[1] = pares[direita].indice_original;

            free(pares);
            return result;
        }
        if(soma < target){
            esquerda++;
        }
        else{
            direita--;
        }

    }

    free(pares);
    *returnSize = 0;
    return NULL;

}
