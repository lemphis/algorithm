#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>

#define endl '\n'
#define MAX 1000

using std::cin;
using std::cout;
using std::ios;
using std::max;
using std::pair;
using std::queue;

int bfs(int r, int c, int n, int m);
bool is_riped(int n, int m);

int box[MAX][MAX];
int distance[MAX][MAX] = {0};

/**
 * @see [토마토](https://www.acmicpc.net/problem/7576)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int M, N;
    cin >> M >> N;
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < M; ++c) {
            cin >> box[r][c];
        }
    }
    if (is_riped(N, M)) {
        cout << 0 << endl;
        return 0;
    }
    int max_count = bfs(0, 0, N, M);
    cout << (is_riped(N, M) ? max_count : -1) << endl;
}

int bfs(int r, int c, int n, int m) {
    queue<pair<int, int> > q;
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            if (box[r][c] == 1) {
                q.push({r, c});
            }
        }
    }
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int max_count = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && box[nx][ny] == 0) {
                box[nx][ny] = 1;
                distance[nx][ny] += distance[x][y] + 1;
                max_count = max(max_count, distance[nx][ny]);
                q.push({nx, ny});
            }
        }
    }
    return max_count;
}

bool is_riped(int n, int m) {
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            if (box[r][c] == 0) {
                return false;
            }
        }
    }
    return true;
}