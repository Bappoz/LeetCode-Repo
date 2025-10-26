/*
* 1. Bubble Sort (Ordenação por Bolha)
 ----------------------------------------------------------------------------------------------------------
 * - Conceito: Compara repetidamente elementos adjacentes (v[j] e v[j+1]) e os
 * troca se estiverem fora de ordem. Os maiores elementos "borbulham" para o final do vetor a cada passagem.
 * * - Complexidade de Tempo:
 * - Pior Caso:  O(n^2) - (Vetor em ordem inversa)
 * - Caso Médio: O(n^2)
 * - Melhor Caso: O(n)   - (Com otimização/flag, se o vetor já está ordenado)
 * * - Complexidade de Espaço: O(1) - (In-place, não usa memória extra)
 * * - Vantagens: Muito simples de entender e implementar.
 * - Desvantagens: Extremamente lento para vetores grandes.
*/



#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubble_sort(int *vetor, int n){
    
    int swapped;

    for(int i = 0; i < n - 1 ; i++){
        swapped = 0;
        for(int j = 0; j < n - 1 - i; j++){
            if(vetor[j] > vetor[j+1]){
                swap(&vetor[j], &vetor[j+1]);
                swapped = 1;
            }
        }
        if(swapped == 0) break;
    }
}


int main(){
    const int n;
    scanf("%d", &n);

    int *vetor = malloc(n*sizeof(int));

    for(int i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
    }

    bubble_sort(vetor, n);

    for(int i = 0; i < n; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}