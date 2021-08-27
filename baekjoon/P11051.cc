#include <iostream>

#define endl '\n'

using std::cin;
using std::cout;
using std::ios;

/**
 * @see [이항 계수 2](https://www.acmicpc.net/problem/11051)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    int cache[n + 1][k + 1] = {0};
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            if (j == 0 || i == j)
                cache[i][j] = 1;
            else
                cache[i][j] = (cache[i - 1][j - 1] + cache[i - 1][j]) % 10007;
        }
    }
    cout << cache[n][k] << endl;
}