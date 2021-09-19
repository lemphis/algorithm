#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>

#define endl '\n'
#define MAX 1000

using std::cin;
using std::cout;
using std::fill;
using std::ios;
using std::pair;
using std::queue;

int move(int start_row, int start_col, int r, int c);
void fire_bfs(int r, int c);

char maze[MAX][MAX] = {0};
bool visited[MAX][MAX] = {0};
int fire_distance[MAX][MAX];
int person_distance[MAX][MAX] = {0};

/**
 * @see [불!](https://www.acmicpc.net/problem/4179)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int R, C;
    cin >> R >> C;
    int start_row, start_col;
    for (int row = 0; row < R; ++row) {
        char temp_col[C + 1];
        cin >> temp_col;
        for (int col = 0; col < C; ++col) {
            if (temp_col[col] == 'J') {
                start_row = row;
                start_col = col;
            }
            maze[row][col] = temp_col[col];
            fire_distance[row][col] = 10000;
        }
    }

    fire_bfs(R, C);
    fill(visited[0], visited[0] + MAX * MAX, 0);
    int count = move(start_row, start_col, R, C);
    if (count == -1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << count << endl;
    }
}

int move(int start_row, int start_col, int r, int c) {
    queue<pair<int, int> > q;
    q.push({start_row, start_col});
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        visited[x][y] = 1;
        q.pop();
        if (x == 0 || x == r - 1 || y == 0 || y == c - 1) {
            return person_distance[x][y] + 1;
        }
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < r && ny >= 0 && ny < c && !visited[nx][ny] && maze[nx][ny] != '#' && fire_distance[nx][ny] > person_distance[x][y] + 1) {
                q.push({nx, ny});
                visited[nx][ny] = 1;
                person_distance[nx][ny] = person_distance[x][y] + 1;
            }
        }
    }
    return -1;
}

void fire_bfs(int r, int c) {
    queue<pair<int, int> > q;
    for (int row = 0; row < r; ++row) {
        for (int col = 0; col < c; ++col) {
            if (maze[row][col] == 'F') {
                q.push({row, col});
                fire_distance[row][col] = 0;
            }
        }
    }
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        visited[x][y] = 1;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < r && ny >= 0 && ny < c && !visited[nx][ny] && maze[nx][ny] != '#') {
                q.push({nx, ny});
                visited[nx][ny] = 1;
                fire_distance[nx][ny] = fire_distance[x][y] + 1;
            }
        }
    }
}