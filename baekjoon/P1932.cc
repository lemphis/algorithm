#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

#define endl '\n'

/**
 * @see [정수 삼각형](https://www.acmicpc.net/problem/1932)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N;
    cin >> N;
    int nums[N][N], memo[N][N];
    memset(memo, 0, sizeof(memo));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= i; ++j) {
            cin >> nums[i][j];
            if (i == N - 1) {
                memo[i][j] = nums[i][j];
            }
        }
    }

    for (int i = N - 2; i >= 0; --i) {
        for (int j = 0; j <= i; ++j) {
            memo[i][j] = max(memo[i + 1][j], memo[i + 1][j + 1]) + nums[i][j];
        }
    }

    cout << memo[0][0] << endl;

    return 0;
}