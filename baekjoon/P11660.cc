#include <iostream>

using namespace std;

#define endl '\n'
#define MAX 1024 + 1

int nums[MAX][MAX];
int tree[MAX][MAX] = {0};

int sum(int row, int col);
void update(int row, int col, int diff, int N);

/**
 * @see [구간 합 구하기 5](https://www.acmicpc.net/problem/11660)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> nums[i][j];
            update(i, j, nums[i][j], N);
        }
    }

    while (M--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << sum(x2, y2) - (sum(x1 - 1, y2) + sum(x2, y1 - 1)) + sum(x1 - 1, y1 - 1) << endl;
    }

    return 0;
}

int sum(int row, int col) {
    if (row == 0 || col == 0) return 0;
    int res = 0;
    int temp_col = col;
    while (row > 0) {
        while (col > 0) {
            res += tree[row][col];
            col -= (col & -col);
        }
        col = temp_col;
        row -= (row & -row);
    }

    return res;
}

void update(int row, int col, int diff, int N) {
    int temp_col = col;
    while (row <= N) {
        while (col <= N) {
            tree[row][col] += diff;
            col += (col & -col);
        }
        row += (row & -row);
        col = temp_col;
    }
}