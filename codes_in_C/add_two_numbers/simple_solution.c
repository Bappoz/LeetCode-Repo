#include <stdio.h>
#include <math.h>

long long int resultIntVetor(int *v, int tamanho){
    int value = 0;
    int multiplier = 1;
    for(int i=0; i < tamanho; i++){
        value += (v[i]*multiplier);
        multiplier *= 10;
    }

    return value;
}
long long int sumList(int *v1, int *v2, int tamanho1, int tamanho2){
    
    long long int value1 = resultIntVetor(v1, tamanho1);
    long long int value2 = resultIntVetor(v2, tamanho2);

    return value1 + value2;
}

int main(){

    int v1[101] = {9, 9, 9, 9, 9, 9, 9};
    int v2[101] = {9, 9, 9, 9};

    int tamanho_util_v1 = 7;
    int tamanho_util_v2 = 4;

    long long int resultado = sumList(v1, v2, tamanho_util_v1, tamanho_util_v2);
    printf("%lld\n", resultado);
    
    return 0;
}   