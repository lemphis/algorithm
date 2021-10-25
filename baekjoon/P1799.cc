#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <utility>

using namespace std;

#define MAX 10

bool board[MAX][MAX];
bool visit[MAX][MAX];

void clear_pairs(pair<int, int> target[], int size);
void dfs(int n, int depth, int now_r, int now_c, pair<int, int> exist[], int& count);
bool is_promise(int depth, int r, int c, pair<int, int> exist[]);

/**
 * @see [비숍](https://www.acmicpc.net/problem/1799)
 */
int main() {
    int n;
    scanf("%d", &n);
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            int temp;
            scanf("%d", &temp);
            board[r][c] = temp ? 1 : 0;
        }
    }

    pair<int, int> exist[n * 2 - 1];
    clear_pairs(exist, n * 2 - 1);
    int count = 0;
    dfs(n, 0, 0, 0, exist, count);

    printf("%d\n", count);
    return 0;
}

void clear_pairs(pair<int, int> target[], int size) {
    pair<int, int> init_pair = make_pair(-1, -1);
    fill(target, target + size, init_pair);
}

void dfs(int n, int depth, int now_r, int now_c, pair<int, int> exist[], int& count) {
    if (depth == n * 2 - 1) {
        int temp_count = 0;
        for (int i = 0; i < n * 2 - 1; ++i) {
            if (exist[i].first != -1) {
                temp_count++;
            }
        }
        if (count > 6) printf("%d\n", temp_count);
        count = max(count, temp_count);
        return;
    }

    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            if (!visit[r][c] && board[r][c]) {
                visit[r][c] = true;
                if (depth == 0 || is_promise(depth, r, c, exist)) {
                    exist[depth] = make_pair(r, c);
                } else {
                    exist[depth] = make_pair(-1, -1);
                }
                dfs(n, depth + 1, r, c, exist, count);
                // int temp_count = 0;
                // for (int i = 0; i < n * 2 - 1; ++i) {
                //     if (exist[i].first != -1) {
                //         temp_count++;
                //     }
                // }
                // count = max(count, temp_count);
                visit[r][c] = false;
            }
        }
    }
}

bool is_promise(int depth, int r, int c, pair<int, int> exist[]) {
    for (int i = 0; i < depth; ++i) {
        if (exist[i].first != -1) {
            continue;
        }
        if (abs(exist[i].first - r) == abs(exist[i].second - c)) {
            return false;
        }
    }

    return true;
}