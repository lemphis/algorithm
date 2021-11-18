#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

#define endl '\n'

/**
 * @see [이친수](https://www.acmicpc.net/problem/2193)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N;
    cin >> N;

    long long memo[N + 1];
    if (N == 1 || N == 2) {
        cout << 1 << endl;
        return 0;
    } else if (N == 2) {
        cout << 2 << endl;
        return 0;
    } else {
        memo[1] = memo[2] = 1;
        for (int i = 3; i <= N; ++i) {
            memo[i] = memo[i - 1] + memo[i - 2];
        }
    }

    cout << memo[N] << endl;

    return 0;
}