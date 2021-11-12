#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

#define endl '\n'

/**
 * @see [RGB거리](https://www.acmicpc.net/problem/1149)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N;
    cin >> N;
    int rgb[N][3];
    int dp[N][3];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> rgb[i][j];
            dp[i][j] = rgb[i][j];
        }
    }

    for (int i = 1; i < N; ++i) {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + rgb[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + rgb[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + rgb[i][2];
    }

    cout << min(min(dp[N - 1][0], dp[N - 1][1]), dp[N - 1][2]) << endl;

    return 0;
}