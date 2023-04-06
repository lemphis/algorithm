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
    for (int r = row; r < N; ++r) {
        for (int c = col; c < M; ++c) {
            if (visited[r][c]) {
                continue;
            }
            if (is_inside(N, M, r - 1, c) && is_inside(N, M, r, c + 1) && !visited[r][c] && !visited[r - 1][c] && !visited[r][c + 1]) {  // 위 오른쪽
                visited[r][c] = 1;
                visited[r - 1][c] = 1;
                visited[r][c + 1] = 1;
                temp += ((wood[r][c] * 2) + wood[r - 1][c] + wood[r][c + 1]);
                dfs(N, M, r, c + 1, temp, ans);
                temp -= ((wood[r][c] * 2) + wood[r - 1][c] + wood[r][c + 1]);
                visited[r][c] = 0;
                visited[r - 1][c] = 0;
                visited[r][c + 1] = 0;
            }
            if (is_inside(N, M, r, c + 1) && is_inside(N, M, r + 1, c) && !visited[r][c] && !visited[r][c + 1] && !visited[r + 1][c]) {  // 오른쪽 아래
                visited[r][c] = 1;
                visited[r][c + 1] = 1;
                visited[r + 1][c] = 1;
                temp += ((wood[r][c] * 2) + wood[r][c + 1] + wood[r + 1][c]);
                dfs(N, M, r, c + 1, temp, ans);
                temp -= ((wood[r][c] * 2) + wood[r][c + 1] + wood[r + 1][c]);
                visited[r][c] = 0;
                visited[r][c + 1] = 0;
                visited[r + 1][c] = 0;
            }
            if (is_inside(N, M, r + 1, c) && is_inside(N, M, r, c - 1) && !visited[r][c] && !visited[r + 1][c] && !visited[r][c - 1]) {  // 아래 왼쪽
                visited[r][c] = 1;
                visited[r + 1][c] = 1;
                visited[r][c - 1] = 1;
                temp += ((wood[r][c] * 2) + wood[r + 1][c] + wood[r][c - 1]);
                dfs(N, M, r, c + 1, temp, ans);
                temp -= ((wood[r][c] * 2) + wood[r + 1][c] + wood[r][c - 1]);
                visited[r][c] = 0;
                visited[r + 1][c] = 0;
                visited[r][c - 1] = 0;
            }
            if (is_inside(N, M, r, c - 1) && is_inside(N, M, r - 1, c) && !visited[r][c] && !visited[r][c - 1] && !visited[r - 1][c]) {  // 왼쪽 위
                visited[r][c] = 1;
                visited[r][c - 1] = 1;
                visited[r - 1][c] = 1;
                temp += ((wood[r][c] * 2) + wood[r][c - 1] + wood[r - 1][c]);
                dfs(N, M, r, c + 1, temp, ans);
                temp -= ((wood[r][c] * 2) + wood[r][c - 1] + wood[r - 1][c]);
                visited[r][c] = 0;
                visited[r][c - 1] = 0;
                visited[r - 1][c] = 0;
            }
        }
    }
    dfs(N, M, row, col + 1, temp, ans);
}

inline bool is_inside(int N, int M, int row, int col) { return row >= 0 && row < N && col >= 0 && col < M; }