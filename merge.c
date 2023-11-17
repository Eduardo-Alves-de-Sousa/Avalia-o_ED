#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Estrutura para armazenar métricas de desempenho
struct MetricasDesempenho {
    double tempo_execucao;
    int comparacoes;
    int movimentos;
};

// Função de mesclagem para mesclar dois arrays ordenados
void merge(int arr[], int left[], int tamanho_left, int right[], int tamanho_right, struct MetricasDesempenho* metricas) {
    int i = 0, j = 0, k = 0;

    while (i < tamanho_left && j < tamanho_right) {
        metricas->comparacoes++;

        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }

        metricas->movimentos++;
    }

    while (i < tamanho_left) {
        arr[k++] = left[i++];
        metricas->movimentos++;
    }

    while (j < tamanho_right) {
        arr[k++] = right[j++];
        metricas->movimentos++;
    }
}

// Função recursiva para realizar o merge sort
void merge_sort(int arr[], int tamanho, struct MetricasDesempenho* metricas) {
    if (tamanho <= 1) {
        return;
    }

    int meio = tamanho / 2;
    int esquerda[meio];
    int direita[tamanho - meio];

    for (int i = 0; i < meio; i++) {
        esquerda[i] = arr[i];
    }

    for (int i = meio; i < tamanho; i++) {
        direita[i - meio] = arr[i];
    }

    merge_sort(esquerda, meio, metricas);
    merge_sort(direita, tamanho - meio, metricas);

    merge(arr, esquerda, meio, direita, tamanho - meio, metricas);
}

// Função para gerar um array com valores aleatórios
void gerar_array_aleatorio(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        arr[i] = rand() % 1000 + 1;
    }
}

// Função para imprimir os elementos de um array
void imprimir_array(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Função para testar o merge sort com vetores aleatórios
void testar_merge_sort(int tamanho, struct MetricasDesempenho* metricas) {
    int arr[tamanho];

    gerar_array_aleatorio(arr, tamanho);

    clock_t tempo_inicio = clock();
    merge_sort(arr, tamanho, metricas);
    clock_t tempo_fim = clock();

    metricas->tempo_execucao = ((double)(tempo_fim - tempo_inicio)) / CLOCKS_PER_SEC;
}

// Função principal
int main() {
    srand(time(NULL));

    int tamanho, opcao_impressao;
    char tipo_array;

    // Entrada do usuário para o tamanho do array
    printf("Selecione o tamanho do array (100, 1000, 10000, 100000): ");
    scanf("%d", &tamanho);

    // // Entrada do usuário para o tipo do array
    printf("Selecione o tipo do array (a para aleatório, o para ordenado, i para inversamente ordenado): ");
    scanf(" %c", &tipo_array);

    // Entrada do usuário para a opção de impressão
    printf("Deseja imprimir os vetores antes e depois da execução? (1 para Sim, 0 para Não): ");
    scanf("%d", &opcao_impressao);

    // Verificar se o tamanho e o tipo de entrada são válidos
    if ((tamanho == 100 || tamanho == 1000 || tamanho == 10000 || tamanho == 100000) &&
        (tipo_array == 'a' || tipo_array == 'o' || tipo_array == 'i')) {

        double soma_tempo_execucao = 0.0;
        int soma_comparacoes = 0;
        
        for (int i = 0; i < 10; i++) {
            printf("\nTeste %d:\n", i + 1);

            // Testar o merge sort para o tipo de array selecionado
            struct MetricasDesempenho metricas = {0.0, 0, 0};
            testar_merge_sort(tamanho, &metricas);

            // Imprimir os resultados
            printf("\nResultados para array de tamanho %d (Tipo: %c):\n", tamanho, tipo_array);
            printf("Método utilizado: MergeSort\n");
            printf("Tamanho do vetor: %d\n", tamanho);
            printf("Tipo do vetor: %c\n", tipo_array);
            printf("Tempo de execução: %f segundos\n", metricas.tempo_execucao);
            printf("Número de comparações: %d\n", metricas.comparacoes);
            printf("Número de movimentações: %d\n\n", metricas.movimentos);

            // Acumular métricas para calcular a média
            soma_tempo_execucao += metricas.tempo_execucao;
            soma_comparacoes += metricas.comparacoes;

            sleep(1);
        }

        // Calcular e imprimir a média
        double media_tempo_execucao = soma_tempo_execucao / 10.0;
        int media_comparacoes = soma_comparacoes / 10;

        printf("\nMédia dos Resultados para array de tamanho %d (Tipo: %c):\n", tamanho, tipo_array);
        printf("Tempo de execução médio: %f segundos\n", media_tempo_execucao);
        printf("Número médio de comparações: %d\n", media_comparacoes);
    } else {
        printf("Tamanho ou tipo do array inválido.\n");
    }

    return 0;
}
