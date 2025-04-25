#include <iostream>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

using pii = pair<int, int>;
using vvi = vector<vector<int>>;

int main() {
    fastio;

    int N, M;
    cin >> N >> M;
    vector<int> w(M + 1), v(M + 1);
    for (int i = 1; i <= M; ++i) {
        cin >> w[i] >> v[i];
    }

    vector<vector<int>> dp(M + 1, vector<int>(N + 1));
    for (int i = 1; i <= M; ++i) {
        for (int j = 1; j <= N; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (w[i] <= j) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
            }
        }
    }

    cout << dp[M][N];

    return 0;
}