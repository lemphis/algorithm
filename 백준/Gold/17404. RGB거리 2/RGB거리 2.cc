#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

const int INF = 1e9;

int main() {
    fastio;

    int N;
    cin >> N;
    int w[1'000][3];
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < 3; ++c) {
            cin >> w[r][c];
        }
    }

    int dp[1'000][3][3];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                dp[i][j][k] = 1e9;
            }
        }
    }
    for (int c = 0; c < 3; ++c) {
        dp[0][c][c] = w[0][c];
    }

    for (int r = 1; r < N - 1; ++r) {
        dp[r][0][0] = min(dp[r - 1][1][0] + w[r][0], dp[r - 1][2][0] + w[r][0]);
        dp[r][0][1] = min(dp[r - 1][1][1] + w[r][0], dp[r - 1][2][1] + w[r][0]);
        dp[r][0][2] = min(dp[r - 1][1][2] + w[r][0], dp[r - 1][2][2] + w[r][0]);
        dp[r][1][0] = min(dp[r - 1][0][0] + w[r][1], dp[r - 1][2][0] + w[r][1]);
        dp[r][1][1] = min(dp[r - 1][0][1] + w[r][1], dp[r - 1][2][1] + w[r][1]);
        dp[r][1][2] = min(dp[r - 1][0][2] + w[r][1], dp[r - 1][2][2] + w[r][1]);
        dp[r][2][0] = min(dp[r - 1][0][0] + w[r][2], dp[r - 1][1][0] + w[r][2]);
        dp[r][2][1] = min(dp[r - 1][0][1] + w[r][2], dp[r - 1][1][1] + w[r][2]);
        dp[r][2][2] = min(dp[r - 1][0][2] + w[r][2], dp[r - 1][1][2] + w[r][2]);
    }

    int min_weight =
        min({dp[N - 2][0][0] + w[N - 1][1], dp[N - 2][0][0] + w[N - 1][2],
             dp[N - 2][1][0] + w[N - 1][2], dp[N - 2][2][0] + w[N - 1][1],
             dp[N - 2][0][1] + w[N - 1][2], dp[N - 2][1][1] + w[N - 1][0],
             dp[N - 2][1][1] + w[N - 1][2], dp[N - 2][2][1] + w[N - 1][0],
             dp[N - 2][0][2] + w[N - 1][1], dp[N - 2][1][2] + w[N - 1][0],
             dp[N - 2][2][2] + w[N - 1][0], dp[N - 2][2][2] + w[N - 1][1]});

    cout << min_weight;

    return 0;
}