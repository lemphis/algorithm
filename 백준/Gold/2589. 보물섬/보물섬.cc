#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <tuple>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

bool map[50][50];
bool visited[50][50];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int bfs(int row, int col, int r, int c);

int main() {
    fastio;
    int row, col;
    cin >> row >> col;
    for (int r = 0; r < row; ++r) {
        string line;
        cin >> line;
        for (int c = 0; c < line.length(); ++c) {
            map[r][c] = line[c] == 'L';
            visited[r][c] = false;
        }
    }

    int ans = 0;
    for (int r = 0; r < row; ++r) {
        for (int c = 0; c < col; ++c) {
            if (map[r][c]) {
                ans = max(ans, bfs(row, col, r, c));
                memset(visited, 0, sizeof(visited));
            }
        }
    }

    cout << ans;

    return 0;
}

int bfs(int row, int col, int r, int c) {
    int max_count = 0;
    queue<tuple<int, int, int> > q;
    q.push({r, c, 0});
    visited[r][c] = true;
    while (!q.empty()) {
        tuple<int, int, int> pos = q.front();
        int now_r = get<0>(pos);
        int now_c = get<1>(pos);
        int now_count = get<2>(pos);
        q.pop();
        max_count = max(max_count, now_count);
        for (int i = 0; i < 4; ++i) {
            int next_r = now_r + dr[i];
            int next_c = now_c + dc[i];
            if (next_r >= 0 && next_r < row && next_c >= 0 && next_c < col && map[next_r][next_c] &&
                !visited[next_r][next_c]) {
                visited[next_r][next_c] = true;
                q.push({next_r, next_c, now_count + 1});
            }
        }
    }

    return max_count;
}