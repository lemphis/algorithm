#include <algorithm>
#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int factorial(int n);

/**
 * @see [수들의 합 6](https://www.acmicpc.net/problem/1821)
 */
int main() {
    fastio;
    int N, F;
    cin >> N >> F;

    int perm[10] = {0};
    for (int i = 0; i < N; ++i)
        perm[i] = i + 1;

    int n_factorial = factorial(N - 1);
    do {
        int sum = 0;
        for (int k = 0; k < N; ++k)
            sum += (n_factorial / (factorial((N - 1) - k) * factorial(k))) * perm[k];
        if (sum == F) break;
    } while (next_permutation(perm, perm + N));

    for (int i = 0; i < N; ++i)
        cout << perm[i] << ' ';

    return 0;
}

int factorial(int n) {
    return n == 0 ? 1 : n * factorial(n - 1);
}