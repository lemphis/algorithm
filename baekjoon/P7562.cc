#include <cstring>
#include <iostream>
#include <queue>
#include <utility>

using namespace std;

#define endl '\n'
#define MAX 300

int bfs(int start_x, int start_y, int end_x, int end_y, int l);

int chess_board[MAX][MAX] = {0};

/**
 * @see [나이트의 이동](https://www.acmicpc.net/problem/7562)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--) {
        memset(chess_board, 0, sizeof(chess_board));
        int l, start_x, start_y, end_x, end_y;
        cin >> l >> start_x >> start_y >> end_x >> end_y;
        cout << bfs(start_x, start_y, end_x, end_y, l) << endl;
    }
}

int bfs(int start_x, int start_y, int end_x, int end_y, int l) {
    queue<pair<int, int> > q;
    q.push({start_y, start_x});
    int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

    int count = 0;
    while (!q.empty()) {
        int x = q.front().second;
        int y = q.front().first;
        if (x == end_x && y == end_y) {
            count = chess_board[y][x];
            break;
        }
        q.pop();
        for (int i = 0; i < 8; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < l && ny >= 0 && ny < l && !chess_board[ny][nx]) {
                q.push({ny, nx});
                chess_board[ny][nx] = chess_board[y][x] + 1;
            }
        }
    }

    return count;
}