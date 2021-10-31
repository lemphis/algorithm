#include <iostream>

using namespace std;

#define endl '\n'
#define MAX 20

char board[MAX][MAX];
bool visited_alp[MAX] = {0};
bool visited_pos[MAX][MAX] = {0};
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

void dfs(int row, int col, int depth, int R, int C, int& max_count);

/**
 * @see [알파벳](https://www.acmicpc.net/problem/1987)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int R, C;
    cin >> R >> C;
    for (int r = 0; r < R; ++r) {
        char row[C + 1];
        cin >> row;
        for (int c = 0; c < C; ++c) {
            board[r][c] = row[c];
        }
    }

    visited_alp[board[0][0] - 'A'] = true;
    visited_pos[0][0] = true;
    int max_count = 0;
    dfs(0, 0, 0, R, C, max_count);

    cout << max_count + 1 << endl;
    return 0;
}

void dfs(int row, int col, int depth, int R, int C, int& max_count) {
    if (max_count < depth) {
        max_count = depth;
    }
    for (int i = 0; i < 4; ++i) {
        int next_r = row + dr[i];
        int next_c = col + dc[i];
        if (next_r >= 0 && next_r < R && next_c >= 0 && next_c < C) {
            if (!visited_alp[board[next_r][next_c] - 'A'] && !visited_pos[next_r][next_c]) {
                visited_alp[board[next_r][next_c] - 'A'] = true;
                visited_pos[next_r][next_c] = true;
                dfs(next_r, next_c, depth + 1, R, C, max_count);
                visited_alp[board[next_r][next_c] - 'A'] = false;
                visited_pos[next_r][next_c] = false;
            }
        }
    }
}