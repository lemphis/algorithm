#include <iostream>

using namespace std;

#define endl '\n'
#define MAX 501

int map[MAX][MAX], memo[MAX][MAX];
bool visited[MAX][MAX] = {false};
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int dfs(int row, int col, int M, int N);

/**
 * @see [내리막 길](https://www.acmicpc.net/problem/1520)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int M, N;
    cin >> M >> N;
    for (int r = 0; r < M; ++r) {
        for (int c = 0; c < N; ++c) {
            memo[r][c] = -1;
            cin >> map[r][c];
        }
    }

    memo[0][0] = 1;

    cout << dfs(M - 1, N - 1, M, N) << endl;

    return 0;
}

int dfs(int row, int col, int M, int N) {
    if (memo[row][col] >= 0) {
        return memo[row][col];
    }

    memo[row][col] = 0;
    for (int i = 0; i < 4; ++i) {
        int next_row = row + dr[i];
        int next_col = col + dc[i];
        if (next_row >= 0 && next_row < M && next_col >= 0 && next_col < N) {
            if (map[row][col] < map[next_row][next_col]) {
                memo[row][col] += dfs(next_row, next_col, M, N);
            }
        }
    }

    return memo[row][col];
}