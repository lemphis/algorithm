#include <iostream>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;
    int n, k;
    cin >> n >> k;
    vector<int> coins;
    for (int i = 0; i < n; ++i) {
        int coin;
        cin >> coin;
        if (coin <= k) {
            coins.push_back(coin);
        }
    }

    vector<int> dp(k + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < coins.size(); ++i) {
        for (int j = coins[i]; j <= k; ++j) {
            dp[j] += dp[j - coins[i]];
        }
    }

    cout << dp[k];

    return 0;
}
