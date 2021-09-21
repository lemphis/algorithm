#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

#define endl '\n'
#define MAX 100

bool is_riped(int H, int N, int M);
int bfs(int H, int N, int M);

int box[MAX][MAX][MAX];

/**
 * @see [토마토](https://www.acmicpc.net/problem/7569)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int M, N, H;
    cin >> M >> N >> H;
    for (int h = 0; h < H; ++h) {
        for (int r = 0; r < N; ++r) {
            for (int c = 0; c < M; ++c) {
                cin >> box[h][r][c];
            }
        }
    }
    if (is_riped(H, N, M)) {
        cout << 0 << endl;
    } else {
        int count = bfs(H, N, M);
        cout << (is_riped(H, N, M) ? count : -1) << endl;
    }
}

bool is_riped(int H, int N, int M) {
    for (int h = 0; h < H; ++h) {
        for (int r = 0; r < N; ++r) {
            for (int c = 0; c < M; ++c) {
                if (box[h][r][c] == 0) {
                    return false;
                }
            }
        }
    }
    return true;
}

int bfs(int H, int N, int M) {
    queue<tuple<int, int, int>> q;
    int dh[6] = {0, 0, 0, 0, 1, -1};
    int dr[6] = {0, 1, 0, -1, 0, 0};
    int dc[6] = {1, 0, -1, 0, 0, 0};
    for (int h = 0; h < H; ++h) {
        for (int r = 0; r < N; ++r) {
            for (int c = 0; c < M; ++c) {
                if (box[h][r][c] == 1) {
                    q.push({h, r, c});
                }
            }
        }
    }

    int count = 0;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            tuple<int, int, int> coordinate = q.front();
            q.pop();
            int h = get<0>(coordinate);
            int r = get<1>(coordinate);
            int c = get<2>(coordinate);
            for (int idx = 0; idx < 6; ++idx) {
                int nh = h + dh[idx];
                int nr = r + dr[idx];
                int nc = c + dc[idx];
                if (nh >= 0 && nh < H && nr >= 0 && nr < N && nc >= 0 && nc < M && !box[nh][nr][nc]) {
                    q.push({nh, nr, nc});
                    box[nh][nr][nc] = 1;
                }
            }
        }
        if (q.empty()) {
            break;
        }
        count++;
    }
    return count;
}