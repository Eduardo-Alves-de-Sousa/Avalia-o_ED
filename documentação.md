**1. Introdução:**
   **Descrição do Problema:**
   O programa aborda a implementação do algoritmo Merge Sort para ordenação eficiente de arrays. O problema específico é a necessidade de ordenar arrays de diferentes tipos (aleatório, ordenado e inversamente ordenado) com tamanhos variados.

   **Visão Geral:**
   O programa foi desenvolvido para fornecer métricas de desempenho, incluindo tempo de execução, comparações e movimentações, ao aplicar o algoritmo Merge Sort em arrays específicos.

**2. Implementação:**
   **Estrutura de Dados:**
   Utilização de Arrays:
   - O programa utiliza arrays para representar os conjuntos de dados a serem ordenados. As estruturas de dados adicionais incluem uma estrutura MetricasDesempenho para armazenar métricas.

   **Funcionamento das Principais Funções:**
   - `merge`: A função de mesclagem é responsável por combinar dois arrays ordenados em um único array ordenado.
   - `merge_sort`: O algoritmo principal, implementado de forma recursiva, divide o array em duas metades, aplica o merge_sort a cada metade e, em seguida, mescla as metades ordenadas.

   **Formato de Entrada e Saída de Dados:**
   - **Entrada do Usuário:**
     - Tamanho do Array: O usuário seleciona o tamanho do array (100, 1000, 10000, 100000).
     - Tipo do Array: O usuário escolhe entre aleatório (a), ordenado (o) ou inversamente ordenado (i).
     - Opção de Impressão: O usuário decide se deseja ou não imprimir os arrays antes e depois da execução.
   - **Saída do Programa:**
     - O programa exibe os arrays original e ordenado, métricas de desempenho (tempo de execução, comparações e movimentações).

   **Decisões Tomadas:**
   - Utilização de um algoritmo de ordenação eficiente (Merge Sort).
   - Representação dos arrays como estruturas de dados básicas.

   **Detalhes de Especificação:**
   - O código é projetado para aceitar tamanhos específicos de array (100, 1000, 10000, 100000) e tipos (aleatório, ordenado, inversamente ordenado).

**3. Listagem de Testes Executados:**
   - **Teste 1: Array Aleatório**
     - Tamanho: 1000
     - Tipo: Aleatório (a)
     - Resultados: Tempo de execução, comparações, movimentações.
   - **Teste 2: Array Ordenado**
     - Tamanho: 10000
     - Tipo: Ordenado (o)
     - Resultados: Tempo de execução, comparações, movimentações.
   - **Teste 3: Array Inversamente Ordenado**
     - Tamanho: 100000
     - Tipo: Inversamente Ordenado (i)
     - Resultados: Tempo de execução, comparações, movimentações.

**Conclusão:**
   - O programa demonstra a eficácia do algoritmo Merge Sort em diferentes cenários, fornecendo métricas de desempenho para avaliação.

**Referências:**
   - Nenhuma referência específica foi utilizada na implementação deste código.
