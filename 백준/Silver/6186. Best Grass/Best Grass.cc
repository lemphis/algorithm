#include <iostream>
#include <queue>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

using vvi = vector<vector<char>>;
using pii = pair<int, int>;

int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

void bfs(vvi& grassland, int r, int c);

int main() {
    fastio;

    int R, C;
    cin >> R >> C;
    vvi grassland(R, vector<char>(C));
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            cin >> grassland[r][c];
        }
    }

    int count = 0;
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            if (grassland[r][c] == '#') {
                bfs(grassland, r, c);
                ++count;
            }
        }
    }

    cout << count;

    return 0;
}

void bfs(vvi& grassland, int r, int c) {
    int row = grassland.size();
    int col = grassland[0].size();
    queue<pii> q;
    q.push({r, c});
    grassland[r][c] = '.';
    while (!q.empty()) {
        auto& [now_r, now_c] = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int next_r = now_r + dr[i];
            int next_c = now_c + dc[i];
            if (next_r >= 0 && next_r < row && next_c >= 0 && next_c < col &&
                grassland[next_r][next_c] == '#') {
                q.push({next_r, next_c});
                grassland[next_r][next_c] = '.';
            }
        }
    }
}