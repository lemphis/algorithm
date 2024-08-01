#include <iostream>
#include <queue>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

struct Pos {
    int r;
    int c;
};

int main() {
    fastio;
    int R, C;
    cin >> R >> C;
    char map[R][C];
    bool visited[R][C];
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            cin >> map[r][c];
            visited[r][c] = false;
        }
    }

    int dr[4] = {1, 0, -1, 0};
    int dc[4] = {0, 1, 0, -1};
    int live_sheep_count = 0;
    int live_wolf_count = 0;
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            if (map[r][c] != '#' && !visited[r][c]) {
                int sheep_count = 0;
                int wolf_count = 0;
                queue<Pos> q;
                q.push(Pos{r, c});
                visited[r][c] = true;
                while (!q.empty()) {
                    Pos p = q.front();
                    q.pop();
                    if (map[p.r][p.c] == 'o') {
                        ++sheep_count;
                    }
                    if (map[p.r][p.c] == 'v') {
                        ++wolf_count;
                    }
                    for (int i = 0; i < 4; ++i) {
                        int next_r = p.r + dr[i];
                        int next_c = p.c + dc[i];
                        if (next_r >= 0 && next_r < R && next_c >= 0 &&
                            next_c < C && !visited[next_r][next_c] &&
                            map[next_r][next_c] != '#') {
                            visited[next_r][next_c] = true;
                            q.push(Pos{next_r, next_c});
                        }
                    }
                }
                if (sheep_count > wolf_count) {
                    live_sheep_count += sheep_count;
                } else {
                    live_wolf_count += wolf_count;
                }
            }
        }
    }

    cout << live_sheep_count << ' ' << live_wolf_count;

    return 0;
}
