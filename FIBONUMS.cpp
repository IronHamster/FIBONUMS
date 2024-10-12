#include <iostream>
#include <vector>

const long long MOD = 1000000007;

void macierze(long long A[2][2], long long B[2][2]) {
    long long a = (A[0][0] * B[0][0] % MOD + A[0][1] * B[1][0] % MOD) % MOD;
    long long b = (A[0][0] * B[0][1] % MOD + A[0][1] * B[1][1] % MOD) % MOD;
    long long c = (A[1][0] * B[0][0] % MOD + A[1][1] * B[1][0] % MOD) % MOD;
    long long d = (A[1][0] * B[0][1] % MOD + A[1][1] * B[1][1] % MOD) % MOD;

    A[0][0] = a;
    A[0][1] = b;
    A[1][0] = c;
    A[1][1] = d;
}

long long fibonacci(long long N) {
    if (N <= 1) return N;

    long long F[2][2] = {{1, 1}, {1, 0}};
    long long wynik[2][2] = {{1, 0}, {0, 1}};

    while (N > 0) {
        if (N % 2 == 1) {
            macierze(wynik, F);
        }
        macierze(F, F);
        N /= 2;
    }

    return wynik[0][1];
}

int main() {
    int T;
    std::cin >> T;
    std::vector<long long> Ni(T);

    for (int i = 0; i < T; ++i) {
        std::cin >> Ni[i];
    }

    for (int i = 0; i < T; ++i) {
        std::cout << fibonacci(Ni[i]) << std::endl;
    }

    return 0;
}
