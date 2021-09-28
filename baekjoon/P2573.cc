#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

#define endl '\n'
#define MAX 300

int iceberg[MAX][MAX] = {0};
bool visit[MAX][MAX] = {0};

bool all_melted(int n, int m);
int checks(int n, int m);
void count_iceberg(int row, int col, int n, int m);
void melt(int row, int col, int n, int m);

/**
 * @see [빙산](https://www.acmicpc.net/problem/2573)
 */
int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < M; ++c) {
            scanf("%d", &iceberg[r][c]);
        }
    }

    int count = 0;
    while (1) {
        if (all_melted(N, M)) {
            count = 0;
            break;
        }
        for (int r = 0; r < N; ++r) {
            for (int c = 0; c < M; ++c) {
                if (!visit[r][c] && !iceberg[r][c]) {
                    melt(r, c, N, M);
                }
            }
        }
        count++;
        memset(visit, 0, sizeof(visit));
        if (checks(N, M) >= 2) {
            break;
        }
        memset(visit, 0, sizeof(visit));
    }

    printf("%d", count);
}

bool all_melted(int n, int m) {
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            if (iceberg[r][c]) {
                return false;
            }
        }
    }
    return true;
}

int checks(int n, int m) {
    int count = 0;
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            if (!visit[r][c] && iceberg[r][c]) {
                count_iceberg(r, c, n, m);
                count++;
            }
        }
    }
    return count;
}

void count_iceberg(int row, int col, int n, int m) {
    queue<pair<int, int> > q;
    q.push({row, col});
    visit[row][col] = 1;
    int dr[4] = {1, 0, -1, 0};
    int dc[4] = {0, 1, 0, -1};

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && !visit[nr][nc] && iceberg[nr][nc]) {
                q.push({nr, nc});
                visit[nr][nc] = 1;
            }
        }
    }
}

void melt(int row, int col, int n, int m) {
    queue<pair<int, int> > q;
    q.push({row, col});
    visit[row][col] = 1;
    int dr[4] = {1, 0, -1, 0};
    int dc[4] = {0, 1, 0, -1};

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && !visit[nr][nc]) {
                if (!iceberg[nr][nc]) {
                    q.push({nr, nc});
                    visit[nr][nc] = 1;
                } else {
                    if (!--iceberg[nr][nc]) {
                        visit[nr][nc] = 1;
                    }
                }
            }
        }
    }
}