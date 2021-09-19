#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>

#define endl '\n'
#define MAX 501

using std::cin;
using std::cout;
using std::ios;
using std::max;
using std::pair;
using std::queue;

int bfs(int row, int col, int n, int m, int dx[], int dy[]);

bool paper[MAX][MAX] = {0};

/**
 * @see [그림](https://www.acmicpc.net/problem/1926)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            cin >> paper[r][c];
        }
    }
    int sum = 0;
    int drawing_count = 0;
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            if (paper[r][c] == 1) {
                drawing_count++;
                sum = max(sum, bfs(r, c, n, m, dx, dy));
            }
        }
    }
    cout << drawing_count << endl << sum << endl;
}

int bfs(int row, int col, int n, int m, int dx[], int dy[]) {
    queue<pair<int, int> > q;
    q.push({row, col});
    paper[row][col] = 0;
    int sum = 1;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && paper[nx][ny] == 1) {
                q.push({nx, ny});
                paper[nx][ny] = 0;
                sum++;
            }
        }
    }
    return sum;
}