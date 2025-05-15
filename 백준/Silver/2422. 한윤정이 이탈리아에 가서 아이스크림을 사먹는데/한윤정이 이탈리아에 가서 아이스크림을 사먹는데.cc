#include <cstring>
#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;

    int N, M;
    cin >> N >> M;
    bool bad[201][201];
    memset(bad, 0, sizeof(bad));
    while (M--) {
        int a, b;
        cin >> a >> b;
        bad[a][b] = true;
        bad[b][a] = true;
    }

    long count = 0;
    for (int i = 1; i <= N - 2; ++i) {
        for (int j = i + 1; j <= N - 1; ++j) {
            if (bad[i][j]) {
                continue;
            }
            for (int k = j + 1; k <= N; ++k) {
                if (bad[i][k] || bad[j][k]) {
                    continue;
                }
                ++count;
            }
        }
    }

    cout << count;

    return 0;
}