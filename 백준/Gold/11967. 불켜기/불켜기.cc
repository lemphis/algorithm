#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

#define MAX 101

vector<pair<int, int>> pos[MAX][MAX];
queue<pair<int, int>> q;
bool light[MAX][MAX] = {0};
bool visit[MAX][MAX] = {0};

int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

void bfs(int max_r, int max_c, int& count);

/**
 * @see [불켜기](https://www.acmicpc.net/problem/11967)
 */
int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; ++i) {
        int x, y, a, b;
        scanf("%d %d %d %d", &x, &y, &a, &b);
        pos[x][y].push_back({a, b});
    }
    light[1][1] = 1;
    int count = 1;
    int before_count = 0;
    while (before_count != count) {
        before_count = count;
        bfs(N, M, count);
        memset(visit, 0, sizeof(visit));
    }
    printf("%d", count);
    return 0;
}

void bfs(int max_r, int max_c, int& count) {
    q.push({1, 1});
    visit[1][1] = 1;
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        for (int i = 0; i < pos[r][c].size(); ++i) {
            if (!light[pos[r][c][i].first][pos[r][c][i].second]) {
                light[pos[r][c][i].first][pos[r][c][i].second] = 1;
                count++;
            }
        }
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr > 0 && nr <= max_r && nc > 0 && nc <= max_c) {
                if (!visit[nr][nc] && light[nr][nc]) {
                    q.push({nr, nc});
                    visit[nr][nc] = 1;
                }
            }
        }
    }
}