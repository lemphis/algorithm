#include <algorithm>
#include <iostream>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

using pii = pair<int, int>;
using vvi = vector<vector<int>>;

int main() {
    fastio;

    int N;
    cin >> N;
    vector<pii> LJ(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> LJ[i].first;
    }
    for (int i = 1; i <= N; ++i) {
        cin >> LJ[i].second;
    }

    vvi dp(N + 1, vector<int>(100));
    for (int i = 1; i <= N; ++i) {
        for (int w = 1; w < 100; ++w) {
            dp[i][w] = dp[i - 1][w];
            if (w >= LJ[i].first) {
                dp[i][w] =
                    max(dp[i][w], dp[i - 1][w - LJ[i].first] + LJ[i].second);
            }
        }
    }

    cout << dp[N][99];

    return 0;
}