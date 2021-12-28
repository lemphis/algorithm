#include <iostream>
#include <queue>
#include <tuple>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define MAX 200

using namespace std;
using ti = tuple<int, int, int>;

int dr[] = {-2, -2, 0, 0, 2, 2};
int dc[] = {-1, 1, -2, 2, -1, 1};
bool visited[MAX][MAX] = {0};

int bfs(int r1, int c1, int r2, int c2, int N);

/**
 * @see [데스 나이트](https://www.acmicpc.net/problem/16948)
 */
int main() {
    fastio;
    int N, r1, c1, r2, c2;
    cin >> N >> r1 >> c1 >> r2 >> c2;

    cout << bfs(r1, c1, r2, c2, N) << endl;

    return 0;
}

int bfs(int r1, int c1, int r2, int c2, int N) {
    queue<ti> q;
    q.push({r1, c1, 0});
    visited[r1][c1] = 1;

    int count = -1;
    while (!q.empty()) {
        auto [r, c, times] = q.front();
        if (r == r2 && c == c2) {
            count = times;
            break;
        }
        q.pop();
        for (int i = 0; i < 6; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < N && nc >= 0 && nc < N && !visited[nr][nc]) {
                q.push({nr, nc, times + 1});
                visited[nr][nc] = 1;
            }
        }
    }

    return count;
}