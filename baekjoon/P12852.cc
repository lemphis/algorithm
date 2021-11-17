#include <algorithm>
#include <iostream>

using namespace std;

#define endl '\n'

/**
 * @see [1로 만들기 2](https://www.acmicpc.net/problem/12852)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N;
    cin >> N;

    int memo[N + 1];
    memo[1] = 0;
    for (int i = 2; i <= N; ++i) {
        memo[i] = memo[i - 1] + 1;
        if (i % 2 == 0) memo[i] = min(memo[i / 2] + 1, memo[i]);
        if (i % 3 == 0) memo[i] = min(memo[i / 3] + 1, memo[i]);
    }

    cout << memo[N] << endl;
    cout << N << ' ';
    while (N > 1) {
        if (N % 3 == 0 && memo[N / 3] + 1 == memo[N]) {
            cout << N / 3 << ' ';
            N /= 3;
        } else if (N % 2 == 0 && memo[N / 2] + 1 == memo[N]) {
            cout << N / 2 << ' ';
            N /= 2;
        } else {
            cout << N - 1 << ' ';
            N -= 1;
        }
    }

    return 0;
}