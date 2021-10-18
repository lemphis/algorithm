#include <cstdio>
#include <queue>

using namespace std;

void combination(int depth, int idx, int y_cnt, char pos[], int group[], bool visit[], int& count);
bool check(int group[], char pos[]);

/**
 * @see [소문난 칠공주](https://www.acmicpc.net/problem/1941)
 */
int main() {
    char pos[25];
    for (int i = 0; i < 25; ++i) {
        scanf(" %c", &pos[i]);
    }
    int group[7];
    bool visit[25] = {0};
    int count = 0;
    combination(0, 0, 0, pos, group, visit, count);
    printf("%d\n", count);
    return 0;
}

void combination(int depth, int idx, int y_cnt, char pos[], int group[], bool visit[], int& count) {
    if (y_cnt > 3) {
        return;
    }
    if (depth == 7) {
        if (check(group, pos)) {
            count++;
        }
        return;
    }

    for (int i = idx; i < 25; ++i) {
        if (!visit[i]) {
            visit[i] = true;
            group[depth] = i;
            bool is_y = pos[i] == 'Y';
            combination(depth + 1, i, y_cnt + is_y, pos, group, visit, count);
            visit[i] = false;
        }
    }
}

bool check(int group[], char pos[]) {
    queue<int> q;
    bool visit[7] = {0};
    int count = 1;
    visit[0] = true;
    q.push(group[0]);
    while (!q.empty()) {
        int coor = q.front();
        q.pop();
        for (int i = 1; i < 7; ++i) {
            if (!visit[i]) {
                if (coor % 5 == 0) {
                    if (coor - 1 == group[i]) {
                        continue;
                    }
                }
                if (coor % 5 == 4) {
                    if (coor + 1 == group[i]) {
                        continue;
                    }
                }
                if (group[i] == coor + 5 || group[i] == coor + 1 || group[i] == coor - 1 || group[i] == coor - 5) {
                    q.push(group[i]);
                    visit[i] = true;
                    count++;
                }
            }
        }
    }

    return count == 7;
}