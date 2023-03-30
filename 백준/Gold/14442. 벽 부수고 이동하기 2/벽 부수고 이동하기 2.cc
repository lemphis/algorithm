#include <algorithm>
#include <iostream>
#include <queue>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

typedef struct Pos {
    int row;
    int col;
    int wall_count;
    int count;
} Pos;

int bfs(int row, int col, int max_wall_count);
inline bool is_inside(int row, int col, int next_r, int next_c);

const int MAX = 1'001;
const int WALL_MAX = 11;
bool map[MAX][MAX];
bool visited[MAX][MAX][WALL_MAX];
int dr[] = {0, -1, 0, 1};
int dc[] = {1, 0, -1, 0};

int main() {
    fastio;
    int N, M, K;
    cin >> N >> M >> K;
    for (int r = 1; r <= N; ++r) {
        string s;
        cin >> s;
        for (int c = 1; c <= M; ++c) {
            map[r][c] = s[c - 1] == '1';
        }
    }

    cout << bfs(N, M, K);

    return 0;
}

int bfs(int row, int col, int max_wall_count) {
    queue<Pos> q;
    q.push({1, 1, 0, 1});
    int count = 0xffffffff >> 1;
    visited[1][1][0] = 1;
    while (!q.empty()) {
        Pos now = q.front();
        if (now.row == row && now.col == col) {
            count = min(count, now.count);
        }
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int next_r = now.row + dr[i];
            int next_c = now.col + dc[i];
            if (is_inside(row, col, next_r, next_c)) {
                if (map[next_r][next_c] && now.wall_count < max_wall_count && !visited[next_r][next_c][now.wall_count + 1]) {
                    q.push({next_r, next_c, now.wall_count + 1, now.count + 1});
                    visited[next_r][next_c][now.wall_count + 1] = 1;
                }
                if (!map[next_r][next_c] && !visited[next_r][next_c][now.wall_count]) {
                    q.push({next_r, next_c, now.wall_count, now.count + 1});
                    visited[next_r][next_c][now.wall_count] = 1;
                }
            }
        }
    }

    return count == 0xffffffff >> 1 ? -1 : count;
}

inline bool is_inside(int row, int col, int next_r, int next_c) {
    return next_r > 0 && next_r <= row && next_c > 0 && next_c <= col;
}