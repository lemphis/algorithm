#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

#define MAX 51

typedef struct Fluid {
    int time = 0;
    char color = 0;
} Fluid;

int land[MAX][MAX];
Fluid drop_land[MAX][MAX] = {0};
vector<pair<int, int>> drop_pos;
queue<pair<int, int>> green_q;
queue<pair<int, int>> red_q;

bool check(int G, int R, int perm[], int prev_perm[]);
void bfs(int N, int M, bool is_green, int& flower_count);

/**
 * @see [Gaaaaaaaaaarden](https://www.acmicpc.net/problem/18809)
 */
int main() {
    int N, M, G, R;
    scanf("%d %d %d %d", &N, &M, &G, &R);

    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < M; ++c) {
            scanf("%d", &land[r][c]);
            if (land[r][c] == 2) {
                drop_pos.push_back(make_pair(r, c));
            }
        }
    }

    int max_count = 0;

    int size = drop_pos.size();
    int perm[size];
    int prev_perm[size];
    for (int i = 0; i < size; ++i) {
        perm[i] = i;
    }

    do {
        if (!check(G, R, perm, prev_perm)) {
            continue;
        }

        for (int i = 0; i < size; ++i) {
            if (i < G) {
                green_q.push(drop_pos[perm[i]]);
                drop_land[drop_pos[perm[i]].first][drop_pos[perm[i]].second].color = 'G';
            }
            if (i >= G && i < G + R) {
                red_q.push(drop_pos[perm[i]]);
                drop_land[drop_pos[perm[i]].first][drop_pos[perm[i]].second].color = 'R';
            }
        }

        int flower_count = 0;
        while (!green_q.empty() || !red_q.empty()) {
            bfs(N, M, true, flower_count);
            bfs(N, M, false, flower_count);
        }

        max_count = max(max_count, flower_count);
        queue<pair<int, int>> empty_queue;
        green_q = red_q = empty_queue;
        memset(drop_land, 0, sizeof(drop_land));
        memcpy(prev_perm, perm, sizeof(perm));
    } while (next_permutation(perm, perm + size));

    printf("%d\n", max_count);
    return 0;
}

bool check(int G, int R, int perm[], int prev_perm[]) {
    bool through_next_step = false;
    for (int i = 0; i < G + R; ++i) {
        if (perm[i] != prev_perm[i]) {
            through_next_step = true;
            break;
        }
    }
    if (!through_next_step) {
        return false;
    }
    for (int i = 0; i < G - 1; ++i) {
        if (perm[i] > perm[i + 1]) {
            return false;
        }
    }
    for (int i = G; i < G + R - 1; ++i) {
        if (perm[i] > perm[i + 1]) {
            return false;
        }
    }

    return true;
}

void bfs(int N, int M, bool is_green, int& flower_count) {
    queue<pair<int, int>>& q = is_green ? green_q : red_q;
    int size = q.size();
    while (size--) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        if (drop_land[r][c].color == 'B') {
            continue;
        }
        int dr[4] = {1, 0, -1, 0};
        int dc[4] = {0, 1, 0, -1};
        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < N && nc >= 0 && nc < M && land[nr][nc]) {
                if (drop_land[nr][nc].color != 'G' && drop_land[nr][nc].color != 'R' && drop_land[nr][nc].color != 'B') {
                    q.push(make_pair(nr, nc));
                    drop_land[nr][nc].time = drop_land[r][c].time + 1;
                    drop_land[nr][nc].color = is_green ? 'G' : 'R';
                }
                if (!is_green && drop_land[nr][nc].color == 'G' && drop_land[nr][nc].time == drop_land[r][c].time + 1) {
                    drop_land[nr][nc].color = 'B';
                    flower_count++;
                }
            }
        }
    }
}