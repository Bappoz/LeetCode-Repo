#include  <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}



int partition(int *array, int inicio, int fim){
    
    int pivot = array[fim];
    int i = inicio - 1;
    int j = inicio;
    
    for(;j <= fim - 1; j++){
        if(array[j] < pivot){
            i++;
            swap(&array[j], &array[i]);
        }
    }
    i++;
    swap(&array[i], &array[fim]);
    
    return i;
}

void quickSort(int *array, int inicio, int fim){

    if( fim <= inicio) return;

    int pivot = partition(array, inicio, fim);

    quickSort(array, inicio, pivot - 1);
    quickSort(array, pivot+1, fim);
    
}   


int main(){
    int n;
    scanf("%d", &n);

    int *array = malloc(n*sizeof(int));

    for(int i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }

    quickSort(array, 0, n-1);

    for(int i = 0; i < n; i++){
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}