#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;
    int N, M, K;
    cin >> N >> M >> K;
    if (N + M - 1 > K) {
        cout << "NO";
        return 0;
    }

    cout << "YES" << endl;
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < M; ++c) {
            cout << r + c + 1 << ' ';
        }
        cout << endl;
    }

    return 0;
}