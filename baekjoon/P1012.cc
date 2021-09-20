#include <cstring>
#include <iostream>
#include <queue>
#include <utility>

using namespace std;

#define endl '\n'
#define MAX 50
#define FR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR(i, n) FR(i, 0, n)
#define CLEAR(x, a) memset(x, a, sizeof(x))

void bfs(int start_x, int start_y, int n, int m);

bool field[MAX][MAX];

/**
 * @see [유기농 배추](https://www.acmicpc.net/problem/1012)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        int M, N, K;
        cin >> M >> N >> K;
        int count = 0;
        CLEAR(field, 0);
        while (K--) {
            int X, Y;
            cin >> X >> Y;
            field[Y][X] = 1;
        }
        FOR(i, N) {
            FOR(j, M) {
                if (field[i][j] == 1) {
                    bfs(i, j, N, M);
                    count++;
                }
            }
        }
        cout << count << endl;
    }
}

void bfs(int start_x, int start_y, int n, int m) {
    queue<pair<int, int> > q;
    q.push({start_x, start_y});
    field[start_x][start_y] = 0;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        FOR(i, 4) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && field[nx][ny]) {
                q.push({nx, ny});
                field[nx][ny] = 0;
            }
        }
    }
}