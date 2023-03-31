#include <algorithm>
#include <iostream>
#include <queue>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;
using pii = pair<int, int>;

int bfs(int now_r, int now_c, int row, int col);
inline bool is_inside(int row, int col, int next_r, int next_c);

const int MAX = 100;
bool map[MAX][MAX];
bool visited[MAX][MAX];
int dr[] = {0, -1, 0, 1};
int dc[] = {1, 0, -1, 0};

int main() {
    fastio;
    int N, M, K;
    cin >> N >> M >> K;
    while (K--) {
        int r, c;
        cin >> r >> c;
        map[r - 1][c - 1] = 1;
    }

    int ans = 0;
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < M; ++c) {
            if (map[r][c]) {
                ans = max(ans, bfs(r, c, N, M));
            }
        }
    }

    cout << ans;

    return 0;
}

int bfs(int now_r, int now_c, int row, int col) {
    queue<pii> q;
    q.push({now_r, now_c});
    visited[now_r][now_c] = 1;
    int count = 1;
    while (!q.empty()) {
        pii now = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int next_r = now.first + dr[i];
            int next_c = now.second + dc[i];
            if (is_inside(row, col, next_r, next_c) && map[next_r][next_c] && !visited[next_r][next_c]) {
                q.push({next_r, next_c});
                visited[next_r][next_c] = 1;
                ++count;
            }
        }
    }

    return count;
}

inline bool is_inside(int row, int col, int next_r, int next_c) {
    return next_r >= 0 && next_r < row && next_c >= 0 && next_c < col;
}