#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

#define MAX 5

typedef struct Pos {
    int h;
    int r;
    int c;
} Pos;

bool maze[MAX][MAX][MAX];
bool _maze[MAX][MAX][MAX];
bool visit[MAX][MAX][MAX];
int _count[MAX][MAX][MAX];

void set_copied_maze(int floor[]);
void rotate(int h, int rot, int floor[]);
int bfs();
inline bool is_contain(int h, int r, int c);

/**
 * @see [Maaaaaaaaaze](https://www.acmicpc.net/problem/16985)
 */
int main() {
    for (int h = 0; h < MAX; ++h) {
        for (int r = 0; r < MAX; ++r) {
            for (int c = 0; c < MAX; ++c) {
                int is_path;
                scanf("%d", &is_path);
                maze[h][r][c] = is_path ? 1 : 0;
            }
        }
    }

    int floor[] = {0, 1, 2, 3, 4};
    int min_count = 0xffffffff >> 1;

    do {
        set_copied_maze(floor);
        for (int a = 0; a < MAX - 1; ++a) {
            rotate(0, a, floor);
            if (!_maze[0][0][0]) continue;
            for (int b = 0; b < MAX - 1; ++b) {
                rotate(1, b, floor);
                for (int c = 0; c < MAX - 1; ++c) {
                    rotate(2, c, floor);
                    for (int d = 0; d < MAX - 1; ++d) {
                        rotate(3, d, floor);
                        for (int e = 0; e < MAX - 1; ++e) {
                            rotate(4, e, floor);
                            if (!_maze[MAX - 1][MAX - 1][MAX - 1]) continue;
                            memset(visit, 0, sizeof(visit));
                            memset(_count, 0, sizeof(_count));
                            int path_count = bfs();
                            if (path_count != 0) {
                                if (path_count == 12) {
                                    printf("%d\n", 12);
                                    return 0;
                                }
                                min_count = min(min_count, path_count);
                            }
                        }
                    }
                }
            }
        }
    } while (next_permutation(floor, floor + MAX));

    printf("%d\n", min_count > 999 ? -1 : min_count);
    return 0;
}

void set_copied_maze(int floor[]) {
    for (int h = 0; h < MAX; ++h) {
        memcpy(_maze[floor[h]], maze[h], sizeof(maze[h]));
    }
}

void rotate(int h, int rot, int floor[]) {
    for (int r = 0; r < MAX; ++r) {
        for (int c = 0; c < MAX; ++c) {
            switch (rot) {
                case 0:
                    _maze[h][r][c] = maze[floor[h]][r][c];
                    break;
                case 1:
                    _maze[h][r][c] = maze[floor[h]][c][MAX - 1 - r];
                    break;
                case 2:
                    _maze[h][r][c] = maze[floor[h]][MAX - 1 - r][MAX - 1 - c];
                    break;
                case 3:
                    _maze[h][r][c] = maze[floor[h]][MAX - 1 - c][r];
                    break;
            }
        }
    }
}

int bfs() {
    queue<Pos> q;
    q.push({0, 0, 0});
    visit[0][0][0] = true;
    int dh[6] = {0, 0, 0, 0, 1, -1};
    int dr[6] = {0, 1, 0, -1, 0, 0};
    int dc[6] = {1, 0, -1, 0, 0, 0};

    while (!q.empty()) {
        Pos now = q.front();
        q.pop();
        for (int i = 0; i < 6; ++i) {
            int nh = now.h + dh[i];
            int nr = now.r + dr[i];
            int nc = now.c + dc[i];
            if (is_contain(nh, nr, nc) && _maze[nh][nr][nc] && !visit[nh][nr][nc]) {
                q.push({nh, nr, nc});
                visit[nh][nr][nc] = true;
                _count[nh][nr][nc] = _count[now.h][now.r][now.c] + 1;
                if (nh == MAX - 1 && nr == MAX - 1 && nc == MAX - 1) {
                    return _count[nh][nr][nc];
                }
            }
        }
    }

    return 0;
}

inline bool is_contain(int h, int r, int c) {
    return h >= 0 && h < MAX && r >= 0 && r < MAX && c >= 0 && c < MAX;
}