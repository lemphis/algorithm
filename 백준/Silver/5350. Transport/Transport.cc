#include <cstring>
#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;

    int tc;
    cin >> tc;
    int v[20], w[20], dp[1'001];
    string output;
    output.reserve(20 * 100);
    while (tc--) {
        int n, W;
        cin >> n >> W;
        memset(dp, 0, sizeof(int) * (W + 1));
        for (int i = 0; i < n; ++i) {
            cin >> w[i] >> v[i];
        }

        for (int i = 0; i < n; ++i) {
            for (int j = W; j >= 0; --j) {
                if (j >= w[i]) {
                    dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
                }
            }
        }

        output += to_string(dp[W]);
        output += '\n';
    }

    cout << output;

    return 0;
}