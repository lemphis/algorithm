#include <cstdio>

using namespace std;

void dfs(int N, int M, int idx, int depth, int arr[]);

/**
 * @see [N과 M(4)](https://www.acmicpc.net/problem/15652)
 */
int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    int arr[M];
    dfs(N, M, 0, 0, arr);
    return 0;
}

void dfs(int N, int M, int idx, int depth, int arr[]) {
    if (M == depth) {
        for (int i = 0; i < M; ++i) {
            printf("%d ", arr[i]);
        }
        puts("");
        return;
    }

    for (int i = idx; i < N; ++i) {
        arr[depth] = i + 1;
        dfs(N, M, i, depth + 1, arr);
        idx++;
    }
}