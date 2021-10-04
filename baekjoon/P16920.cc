#include <cctype>
#include <cstdio>
#include <queue>
#include <utility>

using namespace std;

#define MAX 1000
#define MAX_PLAYER 10

int map[MAX][MAX] = {0};
int player_max_move[MAX_PLAYER] = {0};
int player_castle[MAX_PLAYER] = {0};
bool is_end = false;

queue<pair<int, int>> player_queue[MAX_PLAYER];
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

void bfs(int max_r, int max_c, int player_num);

/**
 * @see [확장 게임](https://www.acmicpc.net/problem/16920)
 */
int main() {
    int N, M, P;
    scanf("%d %d %d", &N, &M, &P);
    for (int i = 1; i <= P; ++i) {
        scanf("%d", &player_max_move[i]);
    }
    for (int r = 0; r < N; ++r) {
        char row[M + 1];
        scanf("%s", row);
        for (int c = 0; c < M; ++c) {
            if (isdigit(row[c])) {
                int player_num = row[c] - 48;
                player_queue[player_num].push({r, c});
                player_castle[player_num]++;
            }
            map[r][c] = row[c];
        }
    }
    while (!is_end) {
        is_end = true;
        for (int i = 1; i <= P; ++i) {
            bfs(N, M, i);
        }
    }
    for (int i = 1; i <= P; ++i) {
        printf("%d ", player_castle[i]);
    }
    return 0;
}

void bfs(int max_r, int max_c, int player_num) {
    for (int i = 0; i < player_max_move[player_num] && !player_queue[player_num].empty(); ++i) {
        int size = player_queue[player_num].size();
        while (size--) {
            int r = player_queue[player_num].front().first;
            int c = player_queue[player_num].front().second;
            player_queue[player_num].pop();
            for (int idx = 0; idx < 4; ++idx) {
                int nr = r + dr[idx];
                int nc = c + dc[idx];
                if (nr >= 0 && nr < max_r && nc >= 0 && nc < max_c) {
                    if (map[nr][nc] == '.') {
                        player_queue[player_num].push({nr, nc});
                        map[nr][nc] = player_num;
                        player_castle[player_num]++;
                        is_end = false;
                    }
                }
            }
        }
    }
}