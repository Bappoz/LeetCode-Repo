#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

int obterValorRomano(char c){
    switch (c){
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }

}
int romanToInt(char* s){
    int size = strlen(s); 
    
    if(size == 0){
        return 0;
    }

    int total = obterValorRomano(s[size-1]);
    for(int i = size - 2; i >= 0; i--){
        int atual = obterValorRomano(s[i]); 
        int anterior = obterValorRomano(s[i+1]); 

        if(atual < anterior){
            total -= atual; 
        }
        else{
            total += atual;
        }
    }

    return total;
}


int main(){
    char vetor[100];
    scanf("%s", vetor);

    int resultado = romanToInt(vetor);

    printf("%d", resultado);

    return 0;
}