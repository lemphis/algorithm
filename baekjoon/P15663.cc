#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

void dfs(int N, int M, int depth, int nums[], int arr[], bool visit[]);

/**
 * @see [N과 M(9)](https://www.acmicpc.net/problem/15663)
 */
int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    int nums[N];
    for (int i = 0; i < N; ++i) {
        scanf("%d", &nums[i]);
    }
    sort(nums, nums + N);
    int arr[M];
    bool visit[N];
    memset(visit, 0, sizeof(visit));
    dfs(N, M, 0, nums, arr, visit);
    return 0;
}

void dfs(int N, int M, int depth, int nums[], int arr[], bool visit[]) {
    if (M == depth) {
        for (int i = 0; i < M; ++i) {
            printf("%d ", arr[i]);
        }
        puts("");
        return;
    }

    int prev_num = -1;
    for (int i = 0; i < N; ++i) {
        if (!visit[i] && prev_num != nums[i]) {
            visit[i] = true;
            arr[depth] = prev_num = nums[i];
            dfs(N, M, depth + 1, nums, arr, visit);
            visit[i] = false;
        }
    }
}