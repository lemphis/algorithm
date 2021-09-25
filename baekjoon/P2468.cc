#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <utility>

using namespace std;

#define endl '\n'
#define MAX 100

void bfs(int row, int col, int height, int n);

int area[MAX][MAX] = {0};
bool visited[MAX][MAX] = {0};

/**
 * @see [안전 영역](https://www.acmicpc.net/problem/2468)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N;
    cin >> N;
    int max_height = 0;
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            cin >> area[r][c];
            max_height = max(max_height, area[r][c]);
        }
    }
    int max_safe_area = 1;
    for (int h = 1; h < max_height; ++h) {
        int temp = 0;
        for (int r = 0; r < N; ++r) {
            for (int c = 0; c < N; ++c) {
                if (!visited[r][c] && area[r][c] > h) {
                    bfs(r, c, h, N);
                    temp++;
                }
            }
        }
        max_safe_area = max(max_safe_area, temp);
        memset(visited, 0, sizeof(visited));
    }
    cout << max_safe_area << endl;
}

void bfs(int row, int col, int height, int n) {
    queue<pair<int, int> > q;
    q.push({row, col});
    visited[row][col] = 1;
    int dr[4] = {1, 0, -1, 0};
    int dc[4] = {0, 1, 0, -1};

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc] && area[nr][nc] > height) {
                q.push({nr, nc});
                visited[nr][nc] = 1;
            }
        }
    }
}