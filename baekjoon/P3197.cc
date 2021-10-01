#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;

#define MAX 1500

char lake[MAX][MAX] = {0};
int melt_time[MAX][MAX] = {0};
bool visit[MAX][MAX] = {0};

int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

bool metable(pair<int, int> swans[], int max_time, int max_r, int max_c);
int melt(int max_r, int max_c);
queue<pair<int, int>> melt_queue;

/**
 * @see [백조의 호수](https://www.acmicpc.net/problem/3197)
 */
int main() {
    int R, C;
    scanf("%d %d", &R, &C);
    pair<int, int> swans[2];
    int swan_idx = 0;
    for (int r = 0; r < R; ++r) {
        char row[C + 1];
        scanf("%s", row);
        for (int c = 0; c < C; ++c) {
            if (row[c] == '.' || row[c] == 'L') {
                melt_queue.push({r, c});
                if (row[c] == 'L') {
                    swans[swan_idx++] = {r, c};
                }
            }
            lake[r][c] = row[c];
        }
    }
    int start = 0;
    int end = melt(R, C);
    while (start <= end) {
        int mid = (start + end) / 2;
        if (metable(swans, mid, R, C)) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    printf("%d\n", start);
    return 0;
}

bool metable(pair<int, int> swans[], int max_time, int max_r, int max_c) {
    memset(visit, 0, sizeof(visit));
    queue<pair<int, int>> q;
    pair<int, int> src = swans[0];
    pair<int, int> dest = swans[1];
    q.push({src.first, src.second});
    visit[src.first][src.second] = 1;

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        if (r == dest.first && c == dest.second) {
            return true;
        }
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < max_r && nc >= 0 && nc < max_c) {
                if (!visit[nr][nc] && melt_time[nr][nc] <= max_time) {
                    q.push({nr, nc});
                    visit[nr][nc] = 1;
                }
            }
        }
    }

    return false;
}

int melt(int max_r, int max_c) {
    int time = 1;
    while (!melt_queue.empty()) {
        int size = melt_queue.size();
        while (size--) {
            int r = melt_queue.front().first;
            int c = melt_queue.front().second;
            melt_queue.pop();
            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nr < max_r && nc >= 0 && nc < max_c) {
                    if (!visit[nr][nc] && lake[nr][nc] == 'X') {
                        melt_queue.push({nr, nc});
                        melt_time[nr][nc] = time;
                        visit[nr][nc] = 1;
                    }
                }
            }
        }
        time++;
    }

    return time - 1;
}