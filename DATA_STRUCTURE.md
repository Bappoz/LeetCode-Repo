# Tabela Teórica: Métodos e Formas de Resolução para Problemas Específicos de Estruturas de Dados

Esta tabela apresenta uma visão teórica de **métodos e estruturas de dados** para resolver problemas específicos, focando em algoritmos eficientes. Cada problema inclui múltiplas abordagens (ex.: brute force, otimizada), com ênfase em complexidade de tempo/espaço e estruturas usadas (ex.: arrays, hash maps, stacks). O vetor booleano `seen[]` é apenas um exemplo de método (usado em sliding window para unicidade). Use isso para fixar conceitos de resolução de problemas.

| Problema Específico | Métodos/Formas de Resolução | Descrição Teórica (Estruturas de Dados e Complexidade) | Exemplo |
|---------------------|-----------------------------|-------------------------------------------------------|---------|
| **Longest Substring Without Repeating Characters** | 1. Brute Force (Nested Loops) | Verifica todas as substrings possíveis com um set temporário. Complexidade: O(n^3) tempo (devido a verificações lineares), O(min(n, m)) espaço (set). Ineficiente para n grande. | Para `"abcabcbb"`, testa substrings como `"abc"` (3). |
| | 2. Sliding Window com HashSet | Usa janela deslizante com set para rastrear caracteres únicos. Move ponteiro direito, remove duplicatas movendo esquerdo. Complexidade: O(n) tempo, O(min(n, m)) espaço. | Expande janela até duplicata, atualiza máximo. |
| | 3. Sliding Window com Array Booleano (`seen[]`) | Array fixo (ex.: `seen[256]`) para marcar presença (0/1). Resetado por substring ou janela. Complexidade: O(n) tempo, O(1) espaço (ASCII). | Marca `seen['a'] = 1`, detecta duplicata em O(1). |
| | 4. Sliding Window com HashMap (Contagem) | Mapa para índices de última ocorrência. Move esquerdo baseado em duplicatas. Complexidade: O(n) tempo, O(min(n, m)) espaço. | Para Unicode, usa mapa dinâmico. |
| **Longest Palindromic Substring** | 1. Brute Force (Expandir de Cada Centro) | Para cada centro possível, expande enquanto palíndromo. Complexidade: O(n^2) tempo, O(1) espaço. | Para `"babad"`, centros em 'a' ou 'b', encontra `"bab"`. |
| | 2. Dynamic Programming (DP Table) | Tabela 2D `dp[i][j]` para substrings palindrômicas. Complexidade: O(n^2) tempo, O(n^2) espaço. | Marca diagonais, expande se caracteres iguais. |
| | 3. Manacher's Algorithm | Algoritmo otimizado com expansão simétrica e array de raios. Complexidade: O(n) tempo, O(n) espaço. | Usa transformação para lidar com centros pares/ímpares. |
| **Two Sum** | 1. Brute Force (Nested Loops) | Verifica todos os pares. Complexidade: O(n^2) tempo, O(1) espaço. | Para `[2,7,11,15]`, encontra 9=2+7. |
| | 2. HashMap (One-Pass) | Mapeia valores para índices, verifica complemento em O(1). Complexidade: O(n) tempo, O(n) espaço. | Para cada num, checa se `target - num` existe no mapa. |
| | 3. Sort + Two Pointers | Ordena array, usa ponteiros para somar. Complexidade: O(n log n) tempo, O(1) espaço (se permitido modificar). | Move ponteiros baseado na soma. |
| **Valid Parentheses** | 1. Stack (Pilha) | Empilha aberturas, desempilha fechamentos. Complexidade: O(n) tempo, O(n) espaço. | Para `"()[]{}"`, stack vazio no fim. |
| | 2. Counter (Contador) | Conta aberturas/fechamentos, mas falha em ordem (ex.: `"(]"`). Complexidade: O(n) tempo, O(1) espaço. | Só para casos simples. |
| **Merge Intervals** | 1. Sort + Merge | Ordena intervalos, mescla sobrepostos. Complexidade: O(n log n) tempo, O(n) espaço. | Para `[[1,3],[2,6]]`, resulta em `[1,6]`. |
| | 2. Sweep Line (Linha de Varredura) | Usa eventos para início/fim, conta ativos. Complexidade: O(n log n) tempo, O(n) espaço. | Para contagem de sobreposições. |
| **Climbing Stairs (DP Básico)** | 1. Recursão com Memoization | Armazena resultados em array/map. Complexidade: O(n) tempo, O(n) espaço. | Para n=3, caminhos: 1+1+1, 1+2, 2+1. |
| | 2. Bottom-Up DP (Iterativo) | Array `dp[i]` para passos. Complexidade: O(n) tempo, O(n) espaço (otimizável para O(1)). | `dp[i] = dp[i-1] + dp[i-2]`. |
| | 3. Fibonacci Closed-Form | Fórmula matemática. Complexidade: O(1) tempo, O(1) espaço. | Usa constantes de Fibonacci. |

### Explicação Teórica Geral
- **Estruturas de Dados Chave**: Arrays (fixos/dinâmicos), HashMaps/Sets (para lookups O(1)), Stacks (para ordem/LIFO), Queues (para BFS), Trees/Heaps (para prioridades).
- **Padrões de Algoritmos**: Brute Force (simples, ineficiente), Greedy (escolhas locais ótimas), Divide & Conquer (recursão), Dynamic Programming (subproblemas), Sliding Window (janelas móveis), Two Pointers (dois índices).
- **Escolha de Método**: Depende de constraints (tempo/espaço). Otimize para O(n) onde possível, usando estruturas auxiliares.
- **Fixação**: Para cada problema, pense: "Qual estrutura rastreia o estado necessário?" (ex.: `seen[]` para unicidade).

Essa tabela cobre métodos para problemas comuns. Se quiser expandir para um problema específico ou adicionar mais, diga!