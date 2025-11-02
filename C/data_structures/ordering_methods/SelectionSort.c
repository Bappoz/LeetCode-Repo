/*
* 2. Selection Sort (Ordenação por Seleção)
 * ---------------------------------------------------------------------------------
 * - Conceito: A cada passagem 'i', encontra o *menor* elemento na parte não
 * ordenada do vetor (de v[i] até v[n-1]) e o troca com v[i].
 * Constrói a parte ordenada do início para o fim.
 * * - Complexidade de Tempo:
 * - Pior Caso:  O(n^2)
 * - Caso Médio: O(n^2)
 * - Melhor Caso: O(n^2) - (Sempre faz as mesmas comparações)
 * * - Complexidade de Espaço: O(1) - (In-place)
 * * - Vantagens: Simples. Faz o número mínimo de trocas (O(n)), o que é bom
 * se as operações de troca forem muito custosas.
 * - Desvantagens: Ineficiente em tempo, independentemente da ordem inicial.
*/


#include <stdio.h>
#include <stdlib.h>


void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void selection_sort(int* vetor, int n){
    int menor;

    for(size_t i = 0; i < n-1; i++){
        menor = i;

        for(size_t j = i+1; j < n; j++){
            if(vetor[j] < vetor[menor]){
                menor = j;
            }
        }
        if(menor != i){
            swap(&vetor[menor], &vetor[i]);
        }
    }

}


int main(){
    const int n;
    scanf("%d", &n);

    int *vetor = malloc(n*sizeof(int));

    for(int i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
    }

    selection_sort(vetor, n);

    for(int i = 0; i < n; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}