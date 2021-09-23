#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>

using namespace std;

#define endl '\n'
#define MAX 25

int bfs(int row, int col, int N);

bool map[MAX][MAX] = {0};

/**
 * @see [단지번호붙이기](https://www.acmicpc.net/problem/2667)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N;
    cin >> N;
    for (int r = 0; r < N; ++r) {
        char row[N + 1];
        cin >> row;
        for (int c = 0; c < N; ++c) {
            map[r][c] = row[c] - 48;
        }
    }

    int count = 0;
    int widths[MAX * MAX] = {0};
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (map[i][j]) {
                int width = bfs(i, j, N);
                widths[count] = width;
                count++;
            }
        }
    }

    cout << count << endl;
    sort(widths, widths + count);
    for (int i = 0; i < count; ++i) {
        cout << widths[i] << endl;
    }
}

int bfs(int row, int col, int N) {
    queue<pair<int, int> > q;
    q.push({row, col});
    map[row][col] = 0;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    int width = 1;
    while (!q.empty()) {
        int x = q.front().second;
        int y = q.front().first;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < N && map[ny][nx]) {
                q.push({ny, nx});
                map[ny][nx] = 0;
                width++;
            }
        }
    }

    return width;
}