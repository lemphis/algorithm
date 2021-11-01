#include <cstring>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

#define endl '\n'
#define SUDOKU_SIZE 9

int sudoku[SUDOKU_SIZE][SUDOKU_SIZE];

void dfs(vector<pair<int, int>>& targets, size_t idx);
bool is_promise(int row, int col);

/**
 * @see [스도쿠](https://www.acmicpc.net/problem/2580)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    vector<pair<int, int>> targets;
    for (int r = 0; r < SUDOKU_SIZE; ++r) {
        for (int c = 0; c < SUDOKU_SIZE; ++c) {
            cin >> sudoku[r][c];
            if (sudoku[r][c] == 0) {
                targets.push_back(make_pair(r, c));
            }
        }
    }

    dfs(targets, 0);

    return 0;
}

void dfs(vector<pair<int, int>>& targets, size_t idx) {
    if (idx == targets.size()) {
        for (int r = 0; r < SUDOKU_SIZE; ++r) {
            for (int c = 0; c < SUDOKU_SIZE; ++c) {
                cout << sudoku[r][c] << ' ';
            }
            cout << endl;
        }

        exit(0);
    }

    for (int i = 1; i <= 9; ++i) {
        int row = targets[idx].first;
        int col = targets[idx].second;
        int temp = sudoku[row][col];
        sudoku[row][col] = i;
        if (is_promise(row, col)) {
            dfs(targets, idx + 1);
        }
        sudoku[row][col] = temp;
    }
}

bool is_promise(int row, int col) {
    int row_pos = row / 3 * 3;
    int col_pos = col / 3 * 3;

    bool visit[SUDOKU_SIZE + 1];
    memset(visit, 0, sizeof(visit));
    for (int r = row_pos; r < row_pos + 3; ++r) {
        for (int c = col_pos; c < col_pos + 3; ++c) {
            if (sudoku[r][c] != 0 && visit[sudoku[r][c]]) {
                return false;
            }
            visit[sudoku[r][c]] = true;
        }
    }

    memset(visit, 0, sizeof(visit));
    for (int r = 0; r < SUDOKU_SIZE; ++r) {
        if (sudoku[r][col] != 0 && visit[sudoku[r][col]]) {
            return false;
        }
        visit[sudoku[r][col]] = true;
    }

    memset(visit, 0, sizeof(visit));
    for (int c = 0; c < SUDOKU_SIZE; ++c) {
        if (sudoku[row][c] != 0 && visit[sudoku[row][c]]) {
            return false;
        }
        visit[sudoku[row][c]] = true;
    }

    return true;
}