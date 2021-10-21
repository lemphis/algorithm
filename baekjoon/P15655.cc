#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

void dfs(int N, int M, int depth, int idx, int nums[], int arr[], bool visit[]);

/**
 * @see [N과 M(6)](https://www.acmicpc.net/problem/15655)
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
    dfs(N, M, 0, 0, nums, arr, visit);
    return 0;
}

void dfs(int N, int M, int depth, int idx, int nums[], int arr[], bool visit[]) {
    if (M == depth) {
        for (int i = 0; i < M; ++i) {
            printf("%d ", arr[i]);
        }
        puts("");
        return;
    }

    for (int i = idx; i < N; ++i) {
        if (!visit[i]) {
            visit[i] = true;
            arr[depth] = nums[i];
            dfs(N, M, depth + 1, i, nums, arr, visit);
            visit[i] = false;
        }
    }
}