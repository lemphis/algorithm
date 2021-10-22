#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

void dfs(int N, int M, int depth, int idx, int nums[], int arr[]);

/**
 * @see [N과 M(12)](https://www.acmicpc.net/problem/15666)
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
    dfs(N, M, 0, 0, nums, arr);
    return 0;
}

void dfs(int N, int M, int depth, int idx, int nums[], int arr[]) {
    if (M == depth) {
        for (int i = 0; i < M; ++i) {
            printf("%d ", arr[i]);
        }
        puts("");
        return;
    }

    int prev_num = -1;
    for (int i = idx; i < N; ++i) {
        if (prev_num != nums[i]) {
            arr[depth] = prev_num = nums[i];
            dfs(N, M, depth + 1, i, nums, arr);
        }
    }
}