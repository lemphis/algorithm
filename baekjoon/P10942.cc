#include <cstdio>

using namespace std;

/**
 * @see [팰린드롬?](https://www.acmicpc.net/problem/10942)
 */
int main() {
    int N;
    scanf("%d", &N);
    int nums[N];
    for (int i = 0; i < N; ++i) {
        scanf("%d", &nums[i]);
    }

    bool memo[N][N];
    for (int i = 0; i < N; ++i) {
        memo[i][i] = 1;
    }
    for (int i = 0; i < N - 1; ++i) {
        memo[i][i + 1] = nums[i] == nums[i + 1];
    }
    for (int k = 3; k <= N; ++k) {
        for (int i = 0; i < N - k + 1; ++i) {
            int j = i + k - 1;
            memo[i][j] = memo[i + 1][j - 1] && nums[i] == nums[j];
        }
    }

    int M;
    scanf("%d", &M);
    while (M--) {
        int S, E;
        scanf("%d %d", &S, &E);
        printf("%d\n", memo[S - 1][E - 1]);
    }

    return 0;
}