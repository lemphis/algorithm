#include <iostream>

using namespace std;

#define endl '\n'
#define DIVISOR 1'000'000'000

/**
 * @see [쉬운 계단 수](https://www.acmicpc.net/problem/10844)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N;
    cin >> N;
    int memo[N + 1][10];
    memo[1][0] = 0;
    for (int i = 1; i < 10; ++i) {
        memo[1][i] = 1;
    }

    for (int i = 2; i <= N; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (j == 0)
                memo[i][j] = memo[i - 1][j + 1];
            else if (j == 9)
                memo[i][j] = memo[i - 1][j - 1];
            else
                memo[i][j] = (memo[i - 1][j - 1] + memo[i - 1][j + 1]) % DIVISOR;
        }
    }

    int sum = 0;
    for (int i = 0; i < 10; ++i) {
        sum = (sum + memo[N][i]) % DIVISOR;
    }

    cout << sum << endl;

    return 0;
}