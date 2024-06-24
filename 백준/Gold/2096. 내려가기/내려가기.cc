#include <cmath>
#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;
using pii = pair<int, int>;

int main() {
    fastio;
    int N;
    cin >> N;
    int table[N][3];
    pii dp[3];
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < 3; ++c) {
            cin >> table[r][c];
        }
    }
    for (int i = 0; i < 3; ++i) {
        dp[i] = {table[0][i], table[0][i]};
    }

    for (int r = 1; r < N; ++r) {
        pii temp[3];
        for (int c = 0; c < 3; ++c) {
            if (c == 0) {
                temp[c].first = max(dp[c].first, dp[c + 1].first) + table[r][c];
                temp[c].second = min(dp[c].second, dp[c + 1].second) + table[r][c];
            } else if (c == 1) {
                temp[c].first = max(dp[c].first, max(dp[c - 1].first, dp[c + 1].first)) + table[r][c];
                temp[c].second = min(dp[c].second, min(dp[c - 1].second, dp[c + 1].second)) + table[r][c];
            } else {
                temp[c].first = max(dp[c - 1].first, dp[c].first) + table[r][c];
                temp[c].second = min(dp[c - 1].second, dp[c].second) + table[r][c];
            }
        }
        for (int i = 0; i < 3; ++i) {
            dp[i] = temp[i];
        }
    }

    cout << max(dp[0].first, max(dp[1].first, dp[2].first)) << ' '
         << min(dp[0].second, min(dp[1].second, dp[2].second));

    return 0;
}