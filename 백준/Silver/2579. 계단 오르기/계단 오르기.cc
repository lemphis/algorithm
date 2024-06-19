#include <cmath>
#include <iostream>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;
    int n;
    cin >> n;
    vector<int> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i];
    }

    int dp[2][n];
    dp[0][0] = points[0];
    dp[0][1] = points[1];
    dp[1][0] = 0;
    dp[1][1] = dp[0][0] + dp[0][1];
    for (int i = 2; i < n; ++i) {
        dp[0][i] = max(dp[0][i - 2], dp[1][i - 2]) + points[i];
        dp[1][i] = dp[0][i - 1] + points[i];
    }

    cout << max(dp[0][n - 1], dp[1][n - 1]);

    return 0;
}