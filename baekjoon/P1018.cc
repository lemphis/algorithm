#include <algorithm>
#include <cstdio>

using namespace std;

/**
 * @see [체스판 다시 칠하기](https://www.acmicpc.net/problem/1018)
 */
int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    char board[N][M];
    for (int r = 0; r < N; ++r) {
        char row[M + 1];
        scanf("%s", row);
        for (int c = 0; c < M; ++c) {
            board[r][c] = row[c];
        }
    }

    int min_count = 2147483647;
    for (int start_r = 0; start_r < N - 8 + 1; ++start_r) {
        for (int start_c = 0; start_c < M - 8 + 1; ++start_c) {
            int count_w = 0, count_b = 0;
            for (int r = 0; r < 8; ++r) {
                for (int c = 0; c < 8; ++c) {
                    if ((start_r + r + start_c + c) % 2 == 0 && board[start_r + r][start_c + c] == 'B') {
                        count_w++;
                    }
                    if ((start_r + r + start_c + c) % 2 == 1 && board[start_r + r][start_c + c] == 'W') {
                        count_w++;
                    }
                    if ((start_r + r + start_c + c) % 2 == 0 && board[start_r + r][start_c + c] == 'W') {
                        count_b++;
                    }
                    if ((start_r + r + start_c + c) % 2 == 1 && board[start_r + r][start_c + c] == 'B') {
                        count_b++;
                    }
                }
            }
            min_count = min({min_count, count_w, count_b});
        }
    }

    printf("%d", min_count);
    return 0;
}