#include <iostream>
#include <queue>
#include <utility>

#define endl '\n'

using std::cin;
using std::cout;
using std::ios;
using std::pair;
using std::queue;

bool maze[100][100] = {0};
int distance[100][100] = {0};

void bfs(int r, int c, int n, int m, int dx[], int dy[]);

/**
 * @see [미로 탐색](https://www.acmicpc.net/problem/2178)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    for (int r = 0; r < N; ++r) {
        char row[M + 1];
        cin >> row;
        for (int c = 0; c < M; ++c) {
            maze[r][c] = row[c] - 48;
        }
    }
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    distance[0][0] = 1;
    bfs(0, 0, N, M, dx, dy);
    cout << distance[N - 1][M - 1] << endl;
}

void bfs(int r, int c, int n, int m, int dx[], int dy[]) {
    queue<pair<int, int> > q;
    q.push({r, c});
    maze[r][c] = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && maze[nx][ny]) {
                maze[nx][ny] = 0;
                q.push({nx, ny});
                distance[nx][ny] = distance[x][y] + 1;
            }
        }
    }
}