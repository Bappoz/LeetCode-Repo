#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char* longestPalindrome(char* s){
    int n = strlen(s);

    if(s == NULL || n == 0) return calloc(1, sizeof(char));
    if(n < 2){
        char* resultado = (char*)malloc(sizeof(char)*2);
        resultado[0] = s[0];
        resultado[1] = '\0';
        return resultado;
    }


    int max_length = 1;
    int start_of_palindrome = 0;

    for(int i = 0; i < n; i++ ){
        int left = i;
        int right = i;
        while(left >=0 && right < n && s[left] == s[right]){
                left--; right++;
        }

        int current_length = (right - 1) - (left + 1) + 1;
        
        if(current_length > max_length){
            max_length = current_length;
            start_of_palindrome = left + 1;
            // Temos então o indicer onde começa o palindrome achado e o tamanho do palindromre 
            // => Com isso conseguimos adicionar à string resultado o resultado do palindrome
        }
    
    // --------------------------------------------------

        left = i;
        right = i+1;

        while(left >= 0 && right < n && s[left] == s[right]){
            left--; right++;
        }
        
        current_length = (right - 1) - (left + 1) + 1;
        
        if(current_length > max_length){
            max_length= current_length;
            start_of_palindrome = left+1;
        }
    }

        char* resultado = (char*)malloc(sizeof(char)*(max_length+1));
        if(resultado == NULL) return NULL;
        
        for(int j = 0; j < max_length; j++){
            resultado[j] = s[start_of_palindrome+j];
        }
        resultado[max_length] = '\0';
        
        return resultado;

}


int main(){
    char s[1000];
    scanf("%s", s);

    char* resultado = longestPalindrome(s);
    printf("\n%s\n", resultado);
    free(resultado);

    return 0;
}