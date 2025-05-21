#include <cstring>
#include <iostream>
#include <queue>
#include <tuple>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

bool map[50][50];
bool visited[50][50];

const int DR[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int DC[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int bfs(int N, int M, int row, int col);

int main() {
    fastio;

    int N, M;
    cin >> N >> M;
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < M; ++c) {
            cin >> map[r][c];
        }
    }

    int max_dist = 0;
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < M; ++c) {
            int dist = bfs(N, M, r, c);
            if (dist > max_dist) {
                max_dist = dist;
            }
        }
    }

    cout << max_dist;

    return 0;
}

int bfs(int N, int M, int row, int col) {
    queue<tuple<int, int, int>> q;
    q.push({row, col, 0});

    memset(visited, 0, sizeof(visited));
    visited[row][col] = true;

    while (!q.empty()) {
        auto [now_r, now_c, now_dist] = q.front();
        if (map[now_r][now_c]) {
            return now_dist;
        }
        q.pop();
        for (int i = 0; i < 8; ++i) {
            int next_r = now_r + DR[i];
            int next_c = now_c + DC[i];
            if (!visited[next_r][next_c] && next_r >= 0 && next_r < N &&
                next_c >= 0 && next_c < M) {
                q.push({next_r, next_c, now_dist + 1});
                visited[next_r][next_c] = true;
            }
        }
    }

    return 0;
}