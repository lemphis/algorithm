#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>

using namespace std;

#define endl '\n'
#define MAX 100

int bfs(int row, int col, int M, int N);

bool paper[MAX][MAX] = {0};

/**
 * @see [영역 구하기](https://www.acmicpc.net/problem/2583)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int M, N, K;
    cin >> M >> N >> K;
    while (K--) {
        int l_x, l_y, r_x, r_y;
        cin >> l_x >> l_y >> r_x >> r_y;
        for (int i = l_y; i < r_y; ++i) {
            for (int j = l_x; j < r_x; ++j) {
                paper[i][j] = 1;
            }
        }
    }

    int count = 0;
    int widths[10000] = {0};
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!paper[i][j]) {
                int width = bfs(i, j, M, N);
                widths[count] = width;
                count++;
            }
        }
    }

    cout << count << endl;
    sort(widths, widths + count);
    for (int i = 0; i < count; ++i) {
        cout << widths[i] << ' ';
    }
}

int bfs(int row, int col, int M, int N) {
    queue<pair<int, int> > q;
    q.push({row, col});
    paper[row][col] = 1;
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
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && !paper[ny][nx]) {
                q.push({ny, nx});
                paper[ny][nx] = 1;
                width++;
            }
        }
    }

    return width;
}