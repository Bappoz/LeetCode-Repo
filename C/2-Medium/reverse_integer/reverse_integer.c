#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>


int int_size(int x){
    int count = 0;
    int tmp = x;

    while (tmp != 0){
        tmp /= 10;
        count++;
    }
    return count;
}

int* create_array_from_int(int x, int count){

    int *vetor_aux = malloc(count * sizeof(int));
    if(vetor_aux == NULL){
        return NULL;
    }
    for(int i = count-1; i >= 0; i--){
        int mod = 0;
        
        mod = x % 10;
        x = x / 10;
        vetor_aux[i] = mod;  
    }
    
    return vetor_aux;

}

int reverse(int x){
    
    long long x_reversed = 0;
    int count = int_size(x);

    if (x == 0){
        return 0;
    }

    int *arrayInt = create_array_from_int(x, count);
    if(arrayInt == NULL){
        return 0;
    }


    long long multiplier = 1;
    for(int i = 0; i < count; i++){
        x_reversed += (long long)arrayInt[i]*multiplier;
        multiplier *= 10;
    }

    free(arrayInt);

    if(x_reversed > INT_MAX || x_reversed < INT_MIN){
        return 0;
    }

    return (int)x_reversed;
}

int main(){
    int x;
    scanf("%d", &x);

    int x_reversed = reverse(x);
    printf("%d", x_reversed);

    return 0;
}