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


#include <stdio.h> 
#include <stdlib.h>


void merge_sorted_array(int *vetor, int left, int m, int right){
    int left_length = m - left + 1;
    int right_length = right - m;
    
    int *temp_left = malloc(left_length * sizeof(int));
    int *temp_right = malloc(right_length * sizeof(int));
    if(!temp_left || !temp_right){
        free(temp_left);
        free(temp_right);
        return;
    }


    for(int i = 0; i < left_length; i++){
        temp_left[i] = vetor[left + i];
    }
    
    for(int i = 0; i < right_length; i++){
        temp_right[i] = vetor[m + 1 + i];
    }

    int i, j, k;
    for( i = 0, j = 0, k = left; i < (left_length) && (j < right_length); k++){
        if( temp_left[i] <= temp_right[j]){
            vetor[k] = temp_left[i];
            i++;
        }
        else{
            vetor[k] = temp_right[j];
            j++;
        }
    }

    // Copia os elementos restantes de temp_left (se houver)
    while (i < left_length) { 
        vetor[k] = temp_left[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de temp_right (se houver)
    while (j < right_length) {
        vetor[k] = temp_right[j];
        j++;
        k++;
    }

    free(temp_left);
    free(temp_right);
}   

void merge_sort_recursion(int *vetor, int left, int right){
    if( left < right ){
        int m = left + (right - left) / 2;
        merge_sort_recursion(vetor, left, m);
        merge_sort_recursion(vetor, m + 1, right);
        
        merge_sorted_array(vetor, left, m, right);
    }

}

void merge_sort(int *vetor, int tamanho){
    merge_sort_recursion(vetor, 0, tamanho-1);

}


int main(){

    int vetor[9] = {9,8,3,4,1,6,2,7,3};
    merge_sort(vetor, 9);

    for(int i = 0; i < 9; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}