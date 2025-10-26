/*
* 4. Merge Sort (Ordenação por Intercalação)
* ---------------------------------------------------------------------------------
* - Conceito: Algoritmo "Dividir para Conquistar".
* 1. Dividir: Divide recursivamente o vetor em duas metades até que cada
* sub-vetor tenha 0 ou 1 elemento (que já estão "ordenados").
* 2. Conquistar: Funde (merge) as metades ordenadas em um novo vetor
* ordenado.
* * - Complexidade de Tempo:
* - Pior Caso:  O(n log n)
* - Caso Médio: O(n log n)
* - Melhor Caso: O(n log n)
* * - Complexidade de Espaço: O(n) - (Precisa de um vetor auxiliar para a fusão)
* * - Vantagens: Desempenho garantido e estável (não altera a ordem relativa
* de elementos iguais).
* - Desvantagens: Requer memória extra, o que pode ser um problema.
*/


#include  <stdio.h>
#include <stdlib.h>

void MergeSort(int *array, int length);
void Merge(int *leftArray, int *rightArray, int *array, int length);


int main(){
    int array[10] = {8,2,5,1,7,3,9,5,6,4};
    MergeSort(array, 10);


    for(int i=0; i<10; i++){
        printf("%d ", array[i]);
    }

    return 0;
}

void MergeSort(int *array, int length){
    if(length <= 1) return;

    int middle = length / 2;

    int left_length = middle;
    int right_length = length - middle;
    
    int *leftArray = malloc(left_length*sizeof(int));
    int *rightArray = malloc(right_length*sizeof(int));
    
    if(!leftArray || !rightArray){
        free(leftArray);
        free(rightArray);
        return;
    }


    int i = 0; // left array
    int j = 0; // right array
    
    for(; i < length; i++){
        if(i < middle){
            leftArray[i] = array[i];
        }
        else{
            rightArray[j] = array[i];
            j++; 
        }
    }
    
    MergeSort(leftArray, left_length);
    MergeSort(rightArray, right_length);
    Merge(leftArray, rightArray, array, length);
}

void Merge(int *leftArray, int *rightArray, int *array, int length){
    int left_length = length/2;
    int right_length = length - left_length;

    int i = 0; // Original array
    int l = 0; // left array
    int r = 0; // right array

    while(l < left_length && r < right_length){

        if(leftArray[l] <= rightArray[r]){
            array[i] = leftArray[l];
            l++; i++;
        }
        else{
            array[i] = rightArray[r];
            r++; i++;
        }
    }

    while(l < left_length){
        array[i] = leftArray[l];
        i++; l++;
    }

    while(r < right_length){
        array[i] = rightArray[r];
        r++; i++;
    }


    free(leftArray);
    free(rightArray);
    
}