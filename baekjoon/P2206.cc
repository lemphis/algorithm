#include <iostream>
#include <queue>

using namespace std;

#define endl '\n'
#define MAX 1000

bool map[MAX][MAX] = {0};
int visit[MAX][MAX][2] = {0};

int bfs(int n, int m);

typedef struct {
    int row;
    int col;
    bool passed;
    int count;
} Node;

/**
 * @see [벽 부수고 이동하기](https://www.acmicpc.net/problem/2206)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    for (int r = 0; r < N; ++r) {
        char row[M + 1];
        cin >> row;
        for (int c = 0; c < M; ++c) {
            map[r][c] = row[c] - 48;
        }
    }

    cout << bfs(N, M) << endl;
}

int bfs(int n, int m) {
    queue<Node> q;
    q.push({0, 0, 0, 1});
    visit[0][0][0] = 1;
    int dr[4] = {1, 0, -1, 0};
    int dc[4] = {0, 1, 0, -1};

    while (!q.empty()) {
        Node now = q.front();
        int r = now.row;
        int c = now.col;
        bool passed = now.passed;
        int count = now.count;
        if (r == n - 1 && c == m - 1) {
            return count;
        }
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                if (map[nr][nc] == 0 && !visit[nr][nc][passed]) {
                    visit[nr][nc][passed] = 1;
                    q.push({nr, nc, passed, count + 1});
                }
                if (map[nr][nc] == 1) {
                    if (!passed && !visit[nr][nc][1]) {
                        visit[nr][nc][1] = 1;
                        q.push({nr, nc, 1, count + 1});
                    }
                }
            }
        }
    }

    return -1;
}