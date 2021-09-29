#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;

#define MAX 100

int map[MAX][MAX] = {0};
bool visit[MAX][MAX] = {0};

void set_number(int row, int col, int n, int land_count);
int bfs(int row, int col, int n, int land_count);

/**
 * @see [다리 만들기](https://www.acmicpc.net/problem/2146)
 */
int main() {
    int N;
    scanf("%d", &N);
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            int num;
            scanf("%d", &num);
            map[r][c] = num ? 1 : 0;
        }
    }
    int land_count = 1;
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            if (map[r][c] && !visit[r][c]) {
                set_number(r, c, N, land_count);
                land_count++;
            }
        }
    }
    memset(visit, 0, sizeof(visit));
    int min_bridge = 0x7fffffff;
    for (int i = 1; i < land_count; ++i) {
        min_bridge = min(min_bridge, bfs(0, 0, N, i));
        memset(visit, 0, sizeof(visit));
    }

    printf("%d\n", min_bridge);
    return 0;
}

void set_number(int row, int col, int n, int land_count) {
    queue<pair<int, int>> q;
    q.push({row, col});
    visit[row][col] = 1;
    int dr[4] = {1, 0, -1, 0};
    int dc[4] = {0, 1, 0, -1};

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        map[r][c] = land_count;
        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visit[nr][nc] && map[nr][nc]) {
                q.push({nr, nc});
                visit[nr][nc] = 1;
            }
        }
    }
}

int bfs(int row, int col, int n, int land_count) {
    queue<pair<int, int>> q;
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            if (map[r][c] == land_count) {
                q.push({r, c});
                visit[r][c] = 1;
            }
        }
    }
    int dr[4] = {1, 0, -1, 0};
    int dc[4] = {0, 1, 0, -1};
    int count = 0;

    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                    if (!visit[nr][nc] && !map[nr][nc]) {
                        q.push({nr, nc});
                        visit[nr][nc] = 1;
                    }
                    if (map[nr][nc] && map[nr][nc] != land_count) {
                        return count;
                    }
                }
            }
        }
        count++;
    }

    return count;
}