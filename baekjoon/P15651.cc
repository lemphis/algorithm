#include <cstdio>

using namespace std;

void dfs(int N, int M, int depth, int arr[]);

/**
 * @see [N과 M(3)](https://www.acmicpc.net/problem/15651)
 */
int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    int arr[M];
    dfs(N, M, 0, arr);
    return 0;
}

void dfs(int N, int M, int depth, int arr[]) {
    if (M == depth) {
        for (int i = 0; i < M; ++i) {
            printf("%d ", arr[i]);
        }
        puts("");
        return;
    }

    for (int i = 0; i < N; ++i) {
        arr[depth] = i + 1;
        dfs(N, M, depth + 1, arr);
    }
}