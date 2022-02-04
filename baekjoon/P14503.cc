#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define MAX 50

using namespace std;

int map[MAX][MAX] = {0};
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, -1, 0, 1};

/**
 * @see [로봇 청소기](https://www.acmicpc.net/problem/14503)
 */
int main() {
    fastio;
    int N, M, r, c, d;
    cin >> N >> M >> r >> c >> d;
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < M; ++c) {
            cin >> map[r][c];
        }
    }

    if (d == 1)
        d = 3;
    else if (d == 3)
        d = 1;

    map[r][c] = -1;
    int count = 1;
    while (1) {
        int clean_cnt = 0;
        for (int i = 1; i <= 4; ++i) {
            int nd = d + i;
            if (nd >= 4) nd -= 4;
            int nr = r + dr[nd];
            int nc = c + dc[nd];
            if (!map[nr][nc]) {
                d = nd;
                r = nr;
                c = nc;
                map[nr][nc] = -1;
                count++;
                break;
            }
            if (map[nr][nc]) {
                clean_cnt++;
            }
        }
        if (clean_cnt == 4) {
            int nd = d + 2;
            if (nd >= 4) nd -= 4;
            int nr = r + dr[nd];
            int nc = c + dc[nd];
            if (map[nr][nc] == 1) {
                break;
            }
            r = nr;
            c = nc;
        }
    };

    cout << count << endl;

    return 0;
}