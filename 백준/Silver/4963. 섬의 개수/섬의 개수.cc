#include <iostream>
#include <queue>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;

int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void bfs(vvi& map, int h, int w, int r, int c);

int main() {
    fastio;
    while (1) {
        int w, h;
        cin >> w >> h;
        if (w == 0 && h == 0) {
            break;
        }
        vvi map(h, vector<int>(w));
        for (int r = 0; r < h; ++r) {
            for (int c = 0; c < w; ++c) {
                cin >> map[r][c];
            }
        }
        int count = 0;
        for (int r = 0; r < h; ++r) {
            for (int c = 0; c < w; ++c) {
                if (map[r][c]) {
                    bfs(map, h, w, r, c);
                    ++count;
                }
            }
        }
        cout << count << endl;
    }

    return 0;
}

void bfs(vvi& map, int h, int w, int r, int c) {
    queue<pii> q;
    q.push({r, c});
    map[r][c] = 0;
    while (!q.empty()) {
        pii pos = q.front();
        int now_r = pos.first;
        int now_c = pos.second;
        q.pop();
        for (int i = 0; i < 8; ++i) {
            int next_r = now_r + dr[i];
            int next_c = now_c + dc[i];
            if (next_r >= 0 && next_r < h && next_c >= 0 && next_c < w &&
                map[next_r][next_c]) {
                map[next_r][next_c] = 0;
                q.push({next_r, next_c});
            }
        }
    }
}
