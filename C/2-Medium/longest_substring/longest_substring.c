/*
ENTRADA: Uma string 's'.

PROCESS: Achar o tamanho do maior substring da string 's' sem caracteres duplicados

SAÍDA: Número inteiro que corresponde ao tamanho da substring
*/

/*
RASCUNHO:
    - Dado uma string s = "abcabcbb" a saída será 3
        -> PORQUE: Pelo oque eu entendi, enquanto não se repetir uma letra logo em seguida, o 
                   sistema responderá com o tamanho desse pedaço da string.
    
    DADOS IMPORTANTES:
        - como a entrada "pwwkew" gera um output 3, por conta do wke, percebemos que vamos 
          quer fazer uma única análise numa só direção de loop para a string, à escolha do 
          programador

        - Teremos uma função para checar se tal length é maior que a anterior para checar qual é maior.
          Caso empate, simplemente escolher o valor de qualquer um.

        - Talvez criar um vetor booleano para armazenar o indice ASCII do char que coloca como 1, caso 
          é sua primeira ocorrência e checar se ele ja apareceu antes .
*/


#include <stdio.h> 
#include <string.h>

int lengthOfLongestSubstring(char* s){
    int maior = 0;
    
    for(int i = 0; i < strlen(s); i++){
        int seen[256] = {0};
        int contador = 0;

        for(int j = i; j < strlen(s); j++){
            if (seen[s[j]]) break;
            // EX: seen['a'] = seen[97] ==> Valor em ASCII 
            seen[s[j]] = 1;
            contador++;
        }

        if(contador > maior) maior = contador;

    }

    return maior;

}

int main(){
    char s[101];
    
    printf("Escreva uma string: ");
    scanf("%s", s);

    int resultado = lengthOfLongestSubstring(s);
    printf("\n%d\n", resultado);

    return 0;
}
