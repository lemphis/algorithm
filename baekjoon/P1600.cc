#include <iostream>
#include <queue>
#include <utility>

using namespace std;

#define MAX 200
#define MAX_K 30

int bfs(int max_r, int max_c, int k);

bool zoo[MAX][MAX] = {0};
bool visit[MAX][MAX][MAX_K + 1] = {0};

typedef struct {
    int row;
    int col;
    int knight_count;
    int times;
} Pos;

/**
 * @see [말이 되고픈 원숭이](https://www.acmicpc.net/problem/1600)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int K;
    cin >> K;
    int W, H;
    cin >> W >> H;
    for (int r = 0; r < H; ++r) {
        for (int c = 0; c < W; ++c) {
            cin >> zoo[r][c];
        }
    }
    cout << bfs(H, W, K) << endl;
    return 0;
}

int bfs(int max_r, int max_c, int k) {
    queue<Pos> q;
    q.push({0, 0, 0, 0});
    visit[0][0][0] = 1;
    int monkey_dr[4] = {1, 0, -1, 0};
    int monkey_dc[4] = {0, 1, 0, -1};
    int horse_dr[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    int horse_dc[8] = {2, 1, -1, -2, -2, -1, 1, 2};

    while (!q.empty()) {
        Pos now = q.front();
        int r = now.row;
        int c = now.col;
        int knight_count = now.knight_count;
        int times = now.times;
        if (r == max_r - 1 && c == max_c - 1) {
            return times;
        }
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nr = r + monkey_dr[i];
            int nc = c + monkey_dc[i];
            if (nr >= 0 && nr < max_r && nc >= 0 && nc < max_c && !visit[nr][nc][knight_count] && !zoo[nr][nc]) {
                q.push({nr, nc, knight_count, times + 1});
                visit[nr][nc][knight_count] = 1;
            }
        }
        if (knight_count != k) {
            for (int i = 0; i < 8; ++i) {
                int nr = r + horse_dr[i];
                int nc = c + horse_dc[i];
                if (nr >= 0 && nr < max_r && nc >= 0 && nc < max_c && !visit[nr][nc][knight_count + 1] && !zoo[nr][nc]) {
                    q.push({nr, nc, knight_count + 1, times + 1});
                    visit[nr][nc][knight_count + 1] = 1;
                }
            }
        }
    }

    return -1;
}