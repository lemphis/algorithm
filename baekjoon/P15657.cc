#include <algorithm>
#include <cstdio>

using namespace std;

void dfs(int N, int M, int depth, int idx, int nums[], int arr[]);

/**
 * @see [N과 M(8)](https://www.acmicpc.net/problem/15657)
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

    for (int i = idx; i < N; ++i) {
        arr[depth] = nums[i];
        dfs(N, M, depth + 1, i, nums, arr);
    }
}