#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    int maze[n][m];
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            cin >> maze[r][c];
        }
    }

    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            int count = maze[r][c];
            if (r - 1 >= 0) {
                maze[r][c] = max(maze[r][c], maze[r - 1][c] + count);
            }
            if (c - 1 >= 0) {
                maze[r][c] = max(maze[r][c], maze[r][c - 1] + count);
            }
            if (r - 1 >= 0 && c - 1 >= 0) {
                maze[r][c] = max(maze[r][c], maze[r - 1][c - 1] + count);
            }
        }
    }

    cout << maze[n - 1][m - 1];

    return 0;
}
