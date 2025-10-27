#include <stdio.h>
#include <string.h>


int strStr(char* haystack, char* needle){
    int tamanho_haystack = strlen(haystack);
    int tamanho_needle = strlen(needle);
    
    
    if(tamanho_needle > tamanho_haystack) return -1;
    if(tamanho_haystack == tamanho_needle && haystack == needle) return 0;
    
    int first_index = 0;
    
    int i = 0;
    while(i < tamanho_haystack){
       
        int j = 0;
        int aux = i;
        while(haystack[aux] == needle[j] && j < tamanho_needle){
            aux++; j++;
            if(j == tamanho_needle){
                first_index = aux - j;
                return first_index;
            }
        }
        i++;
    }
    return -1;
}


int main(){
    char haystack[1000];
    char needle[1000];

    printf("Primeira string: ");
    scanf("%s", haystack);
    printf("\n");
    printf("Segunda string: ");
    scanf("%s", needle);

    int result = strStr(haystack, needle);
    printf("%d\n", result);

    return 0;
}