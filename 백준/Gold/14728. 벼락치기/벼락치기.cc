#include <cstring>
#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;

    int N, T;
    cin >> N >> T;
    int v[100], w[100], dp[10'001];
    memset(dp, 0, sizeof(int) * (T + 1));
    for (int i = 0; i < N; ++i) {
        cin >> w[i] >> v[i];
    }

    for (int i = 0; i < N; ++i) {
        for (int j = T; j > 0; --j) {
            if (j >= w[i]) {
                dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
            }
        }
    }

    cout << dp[T];

    return 0;
}