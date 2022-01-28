#include <string>
#include <vector>

using namespace std;

void rotate(vector<vector<int>>& target) {
    int size = target.size();
    vector<vector<int>> src = target;
    for (int r = 0; r < size; ++r) {
        for (int c = 0; c < size; ++c) {
            target[r][c] = src[(size - 1) - c][r];
        }
    }
}

void set_lock(int M, int N, vector<vector<int>>& board, const vector<vector<int>>& lock) {
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            board[r + (M - 1)][c + (M - 1)] = lock[r][c];
        }
    }
}

void match(int dr, int dc, const vector<vector<int>>& key, vector<vector<int>>& board) {
    int M = key.size();
    for (int r = 0; r < M; ++r) {
        for (int c = 0; c < M; ++c) {
            board[r + dr][c + dc] ^= key[r][c];
        }
    }
}

bool can_open(int M, int N, const vector<vector<int>>& board) {
    for (int r = M - 1; r < M - 1 + N; ++r) {
        for (int c = M - 1; c < M - 1 + N; ++c) {
            if (!board[r][c]) {
                return false;
            }
        }
    }

    return true;
}

/**
 * @see [자물쇠와 열쇠](https://programmers.co.kr/learn/courses/30/lessons/60059)
 */
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int M = key.size();
    int N = lock.size();
    int board_size = (M - 1) * 2 + N;
    vector<vector<int>> board(board_size, vector<int>(board_size));

    int rot_cnt = 0;
    do {
        for (int dr = 0; dr <= ((M - 1) + (N - 1)); ++dr) {
            for (int dc = 0; dc <= ((M - 1) + (N - 1)); ++dc) {
                set_lock(M, N, board, lock);
                match(dr, dc, key, board);
                if (can_open(M, N, board)) {
                    return true;
                }
            }
        }
        rotate(key);
        rot_cnt++;
    } while (rot_cnt < 4);

    return false;
}