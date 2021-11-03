#include <iostream>

using namespace std;

#define endl '\n'

/**
 * @see [경로 찾기](https://www.acmicpc.net/problem/11403)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N;
    cin >> N;
    bool adj[N][N];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> adj[i][j];
        }
    }

    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (adj[i][k] && adj[k][j]) {
                    adj[i][j] = true;
                }
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << adj[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}