/*
* 3. Insertion Sort (Ordenação por Inserção)
 * ---------------------------------------------------------------------------------
 * - Conceito: Percorre o vetor a partir do segundo elemento (i=1). Pega o
 * elemento v[i] (a "chave") e o "insere" em sua posição correta na parte
 * já ordenada (v[0]...v[i-1]), "empurrando" os elementos maiores para a direita.
 * * - Complexidade de Tempo:
 * - Pior Caso:  O(n^2) - (Vetor em ordem inversa)
 * - Caso Médio: O(n^2)
 * - Melhor Caso: O(n)   - (Vetor já está ordenado)
 * * - Complexidade de Espaço: O(1) - (In-place)
 * * - Vantagens: Muito eficiente para vetores pequenos ou "quase ordenados".
 * - Desvantagens: Lento (quadrático) para vetores grandes e desordenados.
*/


#include <stdio.h>
#include <stdlib.h>


void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void inserction_sort(int* vetor, int n){

    for(size_t i = 1; i < n; i++){
        int j = i;
        while(j > 0 && vetor[j] < vetor[j-1]){
            swap(&vetor[j], &vetor[j-1]);
            j--;
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

    inserction_sort(vetor, n);

    for(int i = 0; i < n; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}