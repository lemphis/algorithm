#include <iostream>
#include <queue>

using namespace std;

#define endl '\n'
#define MAX 100

int box[MAX][MAX][MAX];

/**
 * @see [토마토](https://www.acmicpc.net/problem/7569)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int M, N, H;
    cin >> M >> N >> H;
    for (int h = 0; h < H; ++h) {
        for (int n = 0; n < N; ++n) {
            for (int m = 0; m < M; ++m) {
                cin >> box[h][n][m];
            }
        }
    }
}