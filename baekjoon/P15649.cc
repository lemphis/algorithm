#include <iostream>

#define MAX 8
#define endl '\n'

using std::cin;
using std::cout;
using std::ios;

void dfs(int N, int M, int depth, int arr[], bool visit[]);

/**
 * @see [N과 M(1)](https://www.acmicpc.net/problem/15649)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int arr[MAX] = {0};
    bool visit[MAX] = {0};
    int N, M;
    cin >> N >> M;
    dfs(N, M, 0, arr, visit);
}

void dfs(int N, int M, int depth, int arr[], bool visit[]) {
    if (M == depth) {
        for (int i = 0; i < M; ++i) {
            cout << arr[i] << ' ';
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < N; ++i) {
        if (!visit[i]) {
            visit[i] = true;
            arr[depth] = i + 1;
            dfs(N, M, depth + 1, arr, visit);
            visit[i] = false;
        }
    }
}