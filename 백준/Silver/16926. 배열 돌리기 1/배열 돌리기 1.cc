#include <algorithm>
#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;
    int N, M, R;
    cin >> N >> M >> R;
    int arr[N][M], temp[N][M];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> arr[i][j];
        }
    }
    int count = min(N, M);
    while (R--) {
        for (int i = 0; i < count / 2; ++i) {
            for (int r = N - i - 1; r > i; --r) {
                temp[r][i] = arr[r - 1][i];
            }
            for (int r = M - i - 1; r > i; --r) {
                temp[N - 1 - i][r] = arr[N - 1 - i][r - 1];
            }
            for (int r = i; r < N - 1 - i; ++r) {
                temp[r][M - 1 - i] = arr[r + 1][M - 1 - i];
            }
            for (int r = i; r < M - 1 - i; ++r) {
                temp[i][r] = arr[i][r + 1];
            }
        }
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                arr[i][j] = temp[i][j];
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}