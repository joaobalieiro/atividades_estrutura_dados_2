#include <cstdio>
#include <algorithm>
#include <limits>

using namespace std;

#define MAX_N 100       // n maximo de moedas 
#define MAX_W 500       // peso maximo de cada moeda
#define MAX_SUM (MAX_N * MAX_W)  // soma maxima possivel

// dp[i][j] = true se for possivel atingir soma j usando as i primeiras moedas
static bool dp[MAX_N + 1][MAX_SUM + 1];

int main() {
    int N;
    // leitura da quantidade de moedas
    if (scanf("%d", &N) != 1) return 0;

    static int W[MAX_N];
    int total = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d", &W[i]);
        total += W[i];
    }

    // inicializa dp, so dp[0][0] = true
    for (int i = 0; i <= N; i++)
        for (int j = 0; j <= total; j++)
            dp[i][j] = false;
    dp[0][0] = true;

    // preenche dp usando bottom-up
    for (int i = 1; i <= N; i++) {
        int w = W[i-1];
        for (int j = 0; j <= total; j++) {
            // sem usar a moeda i-esima
            if (dp[i-1][j])
                dp[i][j] = true;
            // Usando a moeda i-esima
            if (j >= w && dp[i-1][j-w])
                dp[i][j] = true;
        }
    }

    // busca a melhor soma ate total/2
    int metade = total / 2;
    int melhor = 0;
    for (int j = metade; j >= 0; j--) {
        if (dp[N][j]) {
            melhor = j;
            break;
        }
    }

    // a diferença minima entre as duas partes
    int diff = total - 2 * melhor;
    printf("%d\n", diff);

    return 0;
}

