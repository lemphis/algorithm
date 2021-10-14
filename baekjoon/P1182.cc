#include <cstdio>

using namespace std;

void dfs(int nums[], int idx, int sum, int n, int s, int& count);

/**
 * @see [부분수열의 합](https://www.acmicpc.net/problem/1182)
 */
int main() {
    int N, S;
    scanf("%d %d", &N, &S);
    int nums[N];
    for (int i = 0; i < N; ++i) {
        scanf("%d", &nums[i]);
    }
    int count = 0;
    dfs(nums, 0, 0, N, S, count);
    printf("%d\n", count);
    return 0;
}

void dfs(int nums[], int idx, int sum, int n, int s, int& count) {
    if (idx >= n) {
        return;
    }
    sum += nums[idx];
    if (sum == s) {
        count++;
    }
    dfs(nums, idx + 1, sum - nums[idx], n, s, count);
    dfs(nums, idx + 1, sum, n, s, count);
}