#include <cstdio>
#include <cstring>

using namespace std;

void dfs(int tc, int depth, int idx, int nums[], int ans[], bool visit[]);

/**
 * @see [로또](https://www.acmicpc.net/problem/6603)
 */
int main() {
    int tc;
    while (1) {
        scanf("%d", &tc);
        if (!tc) break;
        int nums[tc];
        bool visit[tc];
        memset(visit, 0, sizeof(visit));
        for (int i = 0; i < tc; ++i) {
            scanf("%d", &nums[i]);
        }
        int ans[6];
        dfs(tc, 0, 0, nums, ans, visit);
        puts("");
    }
    return 0;
}

void dfs(int tc, int depth, int idx, int nums[], int ans[], bool visit[]) {
    if (depth == 6) {
        for (int i = 0; i < 6; ++i) {
            printf("%d ", ans[i]);
        }
        puts("");
        return;
    }

    for (int i = idx; i < tc; ++i) {
        if (!visit[i]) {
            visit[i] = true;
            ans[depth] = nums[i];
            dfs(tc, depth + 1, i, nums, ans, visit);
            visit[i] = false;
        }
    }
}