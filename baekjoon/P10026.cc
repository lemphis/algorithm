#include <cstring>
#include <iostream>
#include <queue>
#include <utility>

using namespace std;

#define endl '\n'
#define MAX 100

void bfs(int start_y, int start_x, char target, bool is_blindness, int N);
bool can_search(int y, int x, char target, bool is_blindness, int N);

char grid[MAX][MAX] = {0};
bool visited[MAX][MAX] = {0};

/**
 * @see [적록색약](https://www.acmicpc.net/problem/10026)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N;
    cin >> N;
    for (int r = 0; r < N; ++r) {
        char row[N + 1];
        cin >> row;
        for (int c = 0; c < N; ++c) {
            grid[r][c] = row[c];
        }
    }
    int normal_count = 0;
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            if (!visited[r][c]) {
                bfs(r, c, grid[r][c], false, N);
                normal_count++;
            }
        }
    }
    memset(visited, 0, sizeof(visited));
    int blindness_count = 0;
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            if (!visited[r][c]) {
                bfs(r, c, grid[r][c], true, N);
                blindness_count++;
            }
        }
    }
    cout << normal_count << ' ' << blindness_count << endl;
}

void bfs(int start_y, int start_x, char target, bool is_blindness, int N) {
    queue<pair<int, int> > q;
    visited[start_y][start_x] = 1;
    q.push({start_y, start_x});
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    while (!q.empty()) {
        int x = q.front().second;
        int y = q.front().first;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (can_search(ny, nx, target, is_blindness, N)) {
                q.push({ny, nx});
                visited[ny][nx] = 1;
            }
        }
    }
}

bool can_search(int y, int x, char target, bool is_blindness, int N) {
    bool condition = x >= 0 && x < N && y >= 0 && y < N && !visited[y][x];
    if (is_blindness) {
        if (target == 'R' || target == 'G') {
            return condition && (grid[y][x] == 'R' || grid[y][x] == 'G');
        }
    }
    return condition && grid[y][x] == target;
}