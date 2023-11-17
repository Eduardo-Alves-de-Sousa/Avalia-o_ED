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

// Função para gerar um array ordenado
void gerar_array_ordenado(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        arr[i] = i + 1;
    }
}

// Função para gerar um array ordenado inversamente
void gerar_array_inverso(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        arr[i] = tamanho - i;
    }
}

// Função para imprimir os elementos de um array
void imprimir_array(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Função para testar o merge sort com diferentes tipos e tamanhos de arrays
void testar_merge_sort(int tamanho, char tipo_array, int opcao_impressao) {
    int arr[tamanho];
    struct MetricasDesempenho metricas = {0.0, 0, 0};

    switch (tipo_array) {
        case 'a':
            gerar_array_aleatorio(arr, tamanho);
            break;
        case 'o':
            gerar_array_ordenado(arr, tamanho);
            break;
        case 'i':
            gerar_array_inverso(arr, tamanho);
            break;
        default:
            printf("Tipo de array inválido.\n");
            return;
    }

    // Imprimir o array original se a opção de impressão estiver selecionada
    if (opcao_impressao) {
        printf("Array original:\n");
        imprimir_array(arr, tamanho);
    }

    clock_t tempo_inicio = clock();
    merge_sort(arr, tamanho, &metricas);
    clock_t tempo_fim = clock();

    // Imprimir o array ordenado se a opção de impressão estiver selecionada
    if (opcao_impressao) {
        printf("Array ordenado:\n");
        imprimir_array(arr, tamanho);
    }

    metricas.tempo_execucao = ((double)(tempo_fim - tempo_inicio)) / CLOCKS_PER_SEC;

    printf("\nResultados para array de tamanho %d (Tipo: %c):\n", tamanho, tipo_array);
    printf("Método utilizado: MergeSort\n");
    printf("Tamanho do vetor: %d\n", tamanho);
    printf("Tipo do vetor: %c\n", tipo_array);
    printf("Tempo de execução: %f segundos\n", metricas.tempo_execucao);
    printf("Número de comparações: %d\n", metricas.comparacoes);
    printf("Número de movimentações: %d\n\n", metricas.movimentos);
}

// Função principal
int main() {
    srand(time(NULL));

    int tamanho, opcao_impressao;
    char tipo_array;

    // Entrada do usuário para o tamanho do array
    printf("Selecione o tamanho do array (100, 1000, 10000, 100000): ");
    scanf("%d", &tamanho);

    // Entrada do usuário para o tipo do array
    printf("Selecione o tipo do array (a para aleatório, o para ordenado, i para inversamente ordenado): ");
    scanf(" %c", &tipo_array);

    // Entrada do usuário para a opção de impressão
    printf("Deseja imprimir os vetores antes e depois da execução? (1 para Sim, 0 para Não): ");
    scanf("%d", &opcao_impressao);

    // Verificar se o tamanho e o tipo de entrada são válidos
    if ((tamanho == 100 || tamanho == 1000 || tamanho == 10000 || tamanho == 100000) &&
        (tipo_array == 'a' || tipo_array == 'o' || tipo_array == 'i')) {
        // Testar o merge sort para o tipo de array selecionado
        testar_merge_sort(tamanho, tipo_array, opcao_impressao);
    } else {
        printf("Tamanho ou tipo do array inválido.\n");
    }

    return 0;
}
