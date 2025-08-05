#include <bits/stdc++.h>
using namespace std;

// Retorna (base^exp) mod 1000 usando divisão e conquista (fast exponentiation)
int mod_pow(int base, long long exp) {
    if (exp == 0) return 1;
    int half = mod_pow(base, exp / 2);
    half = (half * half) % 1000;
    if (exp % 2 == 1)
        half = (half * (base % 1000)) % 1000;
    return half;
}

int main() {
    int n;
    long long k;
    // Le n e k (0 < n ≤ 99, 0 < k ≤ 10^9)
    if (!(cin >> n >> k)) return 0;

    int result = mod_pow(n, k);
    // Imprime o resultado sem zeros s esquerda
    cout << result << "\n";

    return 0;
}
