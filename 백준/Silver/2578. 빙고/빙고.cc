#include <iostream>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;
using vvi = vector<vector<int>>;

void find_and_erase(vvi& board, int num);
int find_bingo(vvi& board);
int check_row_bingo(vvi& board);
int check_column_bingo(vvi& board);
int check_diagonal_bingo(vvi& board);

int main() {
    fastio;
    vvi board(5, vector<int>(5));
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin >> board[i][j];
        }
    }

    int count = 0;
    for (int i = 0; i < 25; ++i) {
        int num;
        cin >> num;
        if (count == 0) {
            find_and_erase(board, num);
            if (i >= 4) {
                if (find_bingo(board) >= 3) {
                    count = i;
                }
            }
        }
    }

    cout << count + 1;

    return 0;
}

void find_and_erase(vvi& board, int num) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (board[i][j] == num) {
                board[i][j] = 0;
                return;
            }
        }
    }
}

int find_bingo(vvi& board) {
    return check_row_bingo(board) + check_column_bingo(board) + check_diagonal_bingo(board);
}

int check_row_bingo(vvi& board) {
    int count = 0;
    for (int i = 0; i < 5; ++i) {
        bool bingo = true;
        for (int j = 0; j < 5; ++j) {
            if (board[i][j] > 0) {
                bingo = false;
                break;
            }
        }
        if (bingo) {
            ++count;
        }
    }
    return count;
}

int check_column_bingo(vvi& board) {
    int count = 0;
    for (int i = 0; i < 5; ++i) {
        bool bingo = true;
        for (int j = 0; j < 5; ++j) {
            if (board[j][i] > 0) {
                bingo = false;
                break;
            }
        }
        if (bingo) {
            ++count;
        }
    }
    return count;
}

int check_diagonal_bingo(vvi& board) {
    int count = 0;
    bool bingo = true;
    for (int i = 0; i < 5; ++i) {
        if (board[i][i] > 0) {
            bingo = false;
            break;
        }
    }
    if (bingo) {
        ++count;
    }

    bingo = true;
    for (int i = 0; i < 5; ++i) {
        if (board[i][(5 - 1) - i] > 0) {
            bingo = false;
            break;
        }
    }
    if (bingo) {
        ++count;
    }

    return count;
}