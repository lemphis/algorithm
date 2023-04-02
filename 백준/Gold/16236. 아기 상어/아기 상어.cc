#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

typedef struct Pos {
    int row;
    int col;
    int count;
} Pos;

bool compare(Pos& a, Pos& b) {
    if (a.row == b.row) {
        return a.col < b.col;
    }
    return a.row < b.row;
}

int bfs(int N, int& shark_row, int& shark_col, int& shark_size, int& bigger_ready_count);
inline bool is_inside(int N, int next_r, int next_c);

const int MAX = 20;
int map[MAX][MAX];
bool visited[MAX][MAX];
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, -1, 0, 1};

int main() {
    fastio;
    int N;
    cin >> N;
    int shark_row, shark_col;
    int shark_size = 2;
    int bigger_ready_count = 0;
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            cin >> map[r][c];
            if (map[r][c] == 9) {
                map[r][c] = 0;
                shark_row = r;
                shark_col = c;
            }
        }
    }

    int ans = 0;
    while (int count = bfs(N, shark_row, shark_col, shark_size, bigger_ready_count)) {
        ans += count;
        memset(visited, 0, sizeof(visited));
    }

    cout << ans;

    return 0;
}

int bfs(int N, int& shark_row, int& shark_col, int& shark_size, int& bigger_ready_count) {
    queue<Pos> q;
    vector<Pos> items;
    q.push({shark_row, shark_col, 0});
    visited[shark_row][shark_col] = 1;
    int distance = 0;
    while (!q.empty()) {
        Pos now = q.front();
        if (map[now.row][now.col] > 0 && map[now.row][now.col] < shark_size) {
            if (distance == 0) {
                distance = now.count;
            }
            if (distance == now.count) {
                items.push_back(now);
            }
        }
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int next_r = now.row + dr[i];
            int next_c = now.col + dc[i];
            if (is_inside(N, next_r, next_c) && !visited[next_r][next_c] && map[next_r][next_c] <= shark_size) {
                q.push({next_r, next_c, now.count + 1});
                visited[next_r][next_c] = 1;
            }
        }
    }

    sort(items.begin(), items.end(), compare);

    if (items.size() > 0) {
        Pos first = items[0];
        map[first.row][first.col] = 0;
        shark_row = first.row;
        shark_col = first.col;
        ++bigger_ready_count;
        if (bigger_ready_count == shark_size) {
            bigger_ready_count = 0;
            ++shark_size;
        }
    }

    return distance;
}

inline bool is_inside(int N, int next_r, int next_c) { return next_r >= 0 && next_r < N && next_c >= 0 && next_c < N; }