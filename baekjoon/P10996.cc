#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

/**
 * @see [별 찍기 - 21](https://www.acmicpc.net/problem/10996)
 */
int main() {
    fastio;
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) cout << (j & 1 ? " " : "*");
        cout << endl;
        for (int j = 0; j < N; ++j) cout << (j & 1 ? "*" : " ");
        cout << endl;
    }

    return 0;
}