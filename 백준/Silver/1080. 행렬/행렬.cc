#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;
    int N, M;
    cin >> N >> M;
    bool A[N][M], B[N][M];
    for (int i = 0; i < N; ++i) {
        string line;
        cin >> line;
        for (int j = 0; j < M; ++j) {
            A[i][j] = line[j] == '1';
        }
    }
    for (int i = 0; i < N; ++i) {
        string line;
        cin >> line;
        for (int j = 0; j < M; ++j) {
            B[i][j] = line[j] == '1';
        }
    }

    int ans = 0;
    for (int r = 0; r < N - 2; ++r) {
        for (int c = 0; c < M - 2; ++c) {
            if (A[r][c] != B[r][c]) {
                ++ans;
                for (int i = 0; i < 3; ++i) {
                    for (int j = 0; j < 3; ++j) {
                        A[r + i][c + j] = !A[r + i][c + j];
                    }
                }
            }
        }
    }

    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < M; ++c) {
            if (A[r][c] != B[r][c]) {
                cout << -1;
                return 0;
            }
        }
    }

    cout << ans;

    return 0;
}
