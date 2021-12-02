#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

#define endl '\n'

/**
 * @see [평범한 배낭](https://www.acmicpc.net/problem/12865)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N, K;
    cin >> N >> K;
    int weight[N], value[N];
    for (int i = 0; i < N; ++i) {
        cin >> weight[i] >> value[i];
    }

    int memo[N + 1][K + 1];
    memset(memo, 0, sizeof(memo));

    for (int r = 1; r <= N; ++r) {
        for (int c = 1; c <= K; ++c) {
            if (c - weight[r - 1] >= 0) {
                memo[r][c] = max(memo[r - 1][c], memo[r - 1][c - weight[r - 1]] + value[r - 1]);
            } else {
                memo[r][c] = memo[r - 1][c];
            }
        }
    }

    cout << memo[N][K] << endl;

    return 0;
}