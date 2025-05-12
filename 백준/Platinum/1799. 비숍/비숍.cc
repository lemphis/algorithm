#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

using pii = pair<int, int>;

const int MAX_SIZE = 10;

pii poses[MAX_SIZE * MAX_SIZE];
bool board[MAX_SIZE][MAX_SIZE];
bool active_board[MAX_SIZE][MAX_SIZE];
int poses_size = 0;

void dfs(int row, int col, int board_size, int& max_count, int idx,
         bool is_odd);
bool is_possible(int row, int col, int board_size);
int count_board(int board_size);

int main() {
    fastio;

    int board_size;
    cin >> board_size;
    for (int r = 0; r < board_size; ++r) {
        for (int c = 0; c < board_size; ++c) {
            cin >> board[r][c];
            if (board[r][c]) {
                poses[poses_size] = {r, c};
                ++poses_size;
            }
            active_board[r][c] = 0;
        }
    }

    int even_max_count = 0;
    for (int i = 0; i < poses_size; ++i) {
        int r = poses[i].first;
        int c = poses[i].second;
        if (((r + c) & 1) == 0) {
            active_board[r][c] = true;
            dfs(r, c, board_size, even_max_count, i, false);
            even_max_count = max(even_max_count, count_board(board_size));
            active_board[r][c] = false;
        }
    }

    int odd_max_count = 0;
    for (int i = 0; i < poses_size; ++i) {
        int r = poses[i].first;
        int c = poses[i].second;
        if (((r + c) & 1) == 1) {
            active_board[r][c] = true;
            dfs(r, c, board_size, odd_max_count, i, true);
            odd_max_count = max(odd_max_count, count_board(board_size));
            active_board[r][c] = false;
        }
    }

    cout << even_max_count + odd_max_count;

    return 0;
}

void dfs(int row, int col, int board_size, int& max_count, int idx,
         bool is_odd) {
    for (int i = idx + 1; i < poses_size; ++i) {
        int r = poses[i].first;
        int c = poses[i].second;
        if (((r + c) & 1) == is_odd && is_possible(r, c, board_size)) {
            active_board[r][c] = true;
            dfs(r, c, board_size, max_count, i, is_odd);
            max_count = max(max_count, count_board(board_size));
            active_board[r][c] = false;
        }
    }
}

bool is_possible(int row, int col, int board_size) {
    if (!board[row][col]) {
        return false;
    }

    int min_pos = min(row, col);

    int r = row - min_pos;
    int c = col - min_pos;
    while (r < board_size && c < board_size) {
        if (active_board[r][c]) {
            return false;
        }
        ++r, ++c;
    }

    min_pos = min(row, board_size - 1 - col);
    r = row - min_pos;
    c = col + min_pos;
    while (r < board_size && c >= 0) {
        if (active_board[r][c]) {
            return false;
        }
        ++r, --c;
    }

    return true;
}

int count_board(int board_size) {
    int count = 0;
    for (int r = 0; r < board_size; ++r) {
        for (int c = 0; c < board_size; ++c) {
            if (active_board[r][c]) {
                ++count;
            }
        }
    }

    return count;
}