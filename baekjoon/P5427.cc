#include <cstring>
#include <iostream>
#include <queue>
#include <utility>

#define endl '\n'
#define MAX 1000

using std::cin;
using std::cout;
using std::ios;
using std::pair;
using std::queue;

void clear();
int move(int start_row, int start_col, int r, int c);
void fire_bfs(int r, int c);

char maze[MAX][MAX];
bool visited[MAX][MAX];
int fire_distance[MAX][MAX];
int person_distance[MAX][MAX];

/**
 * @see [불](https://www.acmicpc.net/problem/5427)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        clear();
        int w, h;
        cin >> w >> h;
        int start_row, start_col;
        for (int row = 0; row < h; ++row) {
            char temp_col[w + 1];
            cin >> temp_col;
            for (int col = 0; col < w; ++col) {
                if (temp_col[col] == '@') {
                    start_row = row;
                    start_col = col;
                }
                maze[row][col] = temp_col[col];
                fire_distance[row][col] = 10000;
            }
        }
        fire_bfs(h, w);
        memset(visited, 0, sizeof(visited));
        int count = move(start_row, start_col, h, w);
        if (count == -1) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            cout << count << endl;
        }
    }
}

void clear() {
    memset(maze, 0, sizeof(maze));
    memset(visited, 0, sizeof(visited));
    memset(fire_distance, 0, sizeof(fire_distance));
    memset(person_distance, 0, sizeof(person_distance));
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
            if (maze[row][col] == '*') {
                q.push({row, col});
                fire_distance[row][col] = 0;
                visited[row][col] = 1;
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