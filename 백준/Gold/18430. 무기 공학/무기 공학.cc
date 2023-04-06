#include <algorithm>
#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

const int MAX = 5;
int wood[MAX][MAX];
bool visited[MAX][MAX];

void dfs(int N, int M, int row, int col, int temp, int& ans);
inline bool is_inside(int N, int M, int row, int col);

int main() {
    fastio;
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> wood[i][j];
        }
    }

    int ans = 0;
    dfs(N, M, 0, 0, 0, ans);

    cout << ans;

    return 0;
}

void dfs(int N, int M, int row, int col, int temp, int& ans) {
    if (col == M) {
        ++row;
        col = 0;
    }
    if (row == N) {
        ans = max(ans, temp);
        return;
    }
    if (!visited[row][col]) {
        if (is_inside(N, M, row - 1, col) && is_inside(N, M, row, col + 1) && !visited[row][col] && !visited[row - 1][col] && !visited[row][col + 1]) {  // 위 오른쪽
            visited[row][col] = 1;
            visited[row - 1][col] = 1;
            visited[row][col + 1] = 1;
            temp += ((wood[row][col] * 2) + wood[row - 1][col] + wood[row][col + 1]);
            dfs(N, M, row, col + 1, temp, ans);
            temp -= ((wood[row][col] * 2) + wood[row - 1][col] + wood[row][col + 1]);
            visited[row][col] = 0;
            visited[row - 1][col] = 0;
            visited[row][col + 1] = 0;
        }
        if (is_inside(N, M, row, col + 1) && is_inside(N, M, row + 1, col) && !visited[row][col] && !visited[row][col + 1] && !visited[row + 1][col]) {  // 오른쪽 아래
            visited[row][col] = 1;
            visited[row][col + 1] = 1;
            visited[row + 1][col] = 1;
            temp += ((wood[row][col] * 2) + wood[row][col + 1] + wood[row + 1][col]);
            dfs(N, M, row, col + 1, temp, ans);
            temp -= ((wood[row][col] * 2) + wood[row][col + 1] + wood[row + 1][col]);
            visited[row][col] = 0;
            visited[row][col + 1] = 0;
            visited[row + 1][col] = 0;
        }
        if (is_inside(N, M, row + 1, col) && is_inside(N, M, row, col - 1) && !visited[row][col] && !visited[row + 1][col] && !visited[row][col - 1]) {  // 아래 왼쪽
            visited[row][col] = 1;
            visited[row + 1][col] = 1;
            visited[row][col - 1] = 1;
            temp += ((wood[row][col] * 2) + wood[row + 1][col] + wood[row][col - 1]);
            dfs(N, M, row, col + 1, temp, ans);
            temp -= ((wood[row][col] * 2) + wood[row + 1][col] + wood[row][col - 1]);
            visited[row][col] = 0;
            visited[row + 1][col] = 0;
            visited[row][col - 1] = 0;
        }
        if (is_inside(N, M, row, col - 1) && is_inside(N, M, row - 1, col) && !visited[row][col] && !visited[row][col - 1] && !visited[row - 1][col]) {  // 왼쪽 위
            visited[row][col] = 1;
            visited[row][col - 1] = 1;
            visited[row - 1][col] = 1;
            temp += ((wood[row][col] * 2) + wood[row][col - 1] + wood[row - 1][col]);
            dfs(N, M, row, col + 1, temp, ans);
            temp -= ((wood[row][col] * 2) + wood[row][col - 1] + wood[row - 1][col]);
            visited[row][col] = 0;
            visited[row][col - 1] = 0;
            visited[row - 1][col] = 0;
        }
    }
    dfs(N, M, row, col + 1, temp, ans);
}

inline bool is_inside(int N, int M, int row, int col) { return row >= 0 && row < N && col >= 0 && col < M; }