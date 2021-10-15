#include <cstdio>
#include <cstring>

using namespace std;

void dfs(int N, int M, int idx, int depth, int arr[], bool visit[]);

/**
 * @see [N과 M(2)](https://www.acmicpc.net/problem/15650)
 */
int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    int arr[M];
    bool visit[M];
    memset(visit, 0, sizeof(visit));
    dfs(N, M, 0, 0, arr, visit);
    return 0;
}

void dfs(int N, int M, int idx, int depth, int arr[], bool visit[]) {
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
            arr[depth] = i + 1;
            dfs(N, M, i, depth + 1, arr, visit);
            visit[i] = false;
        }
    }
}