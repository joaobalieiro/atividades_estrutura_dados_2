#include <cstdio>

// Função para trocar dois elementos
void swap(long long &a, long long &b) {
    long long tmp = a;
    a = b;
    b = tmp;
}

// Quicksort decrescente
void quicksort(long long arr[], int left, int right) {
    if (left >= right) return;
    long long pivot = arr[(left + right) / 2];
    int i = left, j = right;
    while (i <= j) {
        while (arr[i] > pivot) i++;
        while (arr[j] < pivot) j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++; j--;
        }
    }
    if (left < j)  quicksort(arr, left, j);
    if (i < right) quicksort(arr, i, right);
}

int main() {
    int N;
    if (scanf("%d", &N) != 1) return 0;

    static long long P[1000];
    for (int i = 0; i < N; i++) {
        scanf("%lld", &P[i]);
    }

    // Ordena em ordem decrescente
    quicksort(P, 0, N - 1);

    // Soma os descontos (índices 2, 5, 8, ...)
    long long desconto = 0;
    for (int i = 2; i < N; i += 3) {
        desconto += P[i];
    }

    printf("%lld\n", desconto);
    return 0;
}
