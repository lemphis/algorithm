#include <cstdio>
#include <cstring>
#include <queue>
#include <tuple>

using namespace std;

#define MAX 31

char building[MAX][MAX][MAX];
bool visit[MAX][MAX][MAX];

int bfs(int start_h, int start_r, int start_c, int end_h, int end_r, int end_c, int L, int R, int C);

/**
 * @see [상범 빌딩](https://www.acmicpc.net/problem/6593)
 */
int main() {
    int L, R, C;
    while (1) {
        scanf("%d %d %d", &L, &R, &C);
        if (L == 0 && R == 0 && C == 0) {
            break;
        }
        memset(building, 0, sizeof(building));
        memset(visit, 0, sizeof(visit));
        int start_h, start_r, start_c, end_h, end_r, end_c;
        for (int h = 0; h < L; ++h) {
            for (int r = 0; r < R; ++r) {
                char row[C + 1];
                scanf("%s", row);
                for (int c = 0; c < C; ++c) {
                    if (row[c] == 'S') {
                        start_h = h;
                        start_r = r;
                        start_c = c;
                    }
                    if (row[c] == 'E') {
                        end_h = h;
                        end_r = r;
                        end_c = c;
                    }
                    building[h][r][c] = row[c];
                }
            }
        }
        int times = bfs(start_h, start_r, start_c, end_h, end_r, end_c, L, R, C);
        if (times == -1) {
            puts("Trapped!");
        } else {
            printf("Escaped in %d minute(s).\n", times);
        }
    }

    return 0;
}

int bfs(int start_h, int start_r, int start_c, int end_h, int end_r, int end_c, int L, int R, int C) {
    queue<tuple<int, int, int>> q;
    q.push({start_h, start_r, start_c});
    visit[start_h][start_r][start_c] = 1;
    int dh[6] = {0, 0, 0, 0, 1, -1};
    int dr[6] = {0, 1, 0, -1, 0, 0};
    int dc[6] = {1, 0, -1, 0, 0, 0};

    int count = 0;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            tuple<int, int, int> coordinate = q.front();
            q.pop();
            int h = get<0>(coordinate);
            int r = get<1>(coordinate);
            int c = get<2>(coordinate);
            if (h == end_h && r == end_r && c == end_c) {
                return count;
            }
            for (int idx = 0; idx < 6; ++idx) {
                int nh = h + dh[idx];
                int nr = r + dr[idx];
                int nc = c + dc[idx];
                if (nh >= 0 && nh < L && nr >= 0 && nr < R && nc >= 0 && nc < C && !visit[nh][nr][nc]) {
                    if (building[nh][nr][nc] != '#') {
                        q.push({nh, nr, nc});
                    }
                    visit[nh][nr][nc] = 1;
                }
            }
        }
        count++;
    }

    return -1;
}