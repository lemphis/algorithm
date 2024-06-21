#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;
    int N, K;
    cin >> N >> K;
    int dp[K + 1][N + 1];
    for (int i = 0; i <= K; ++i) {
        dp[i][0] = 1;
    }
    for (int i = 0; i <= N; ++i) {
        dp[1][i] = 1;
    }
    for (int r = 2; r <= K; ++r) {
        for (int c = 1; c <= N; ++c) {
            dp[r][c] = (dp[r - 1][c] + dp[r][c - 1]) % 1'000'000'000;
        }
    }

    cout << dp[K][N];

    return 0;
}