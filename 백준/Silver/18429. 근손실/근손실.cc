#include <cstring>
#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

void dfs(int N, int K, int depth, int sum, int kits[], bool visited[], int& count);

int main() {
    fastio;
    int N, K;
    cin >> N >> K;
    int kits[N];
    bool visited[N];
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < N; ++i) {
        cin >> kits[i];
    }

    int count = 0;
    dfs(N, K, 0, 500, kits, visited, count);

    cout << count;

    return 0;
}

void dfs(int N, int K, int depth, int sum, int kits[], bool visited[], int& count) {
    if (depth == N) {
        ++count;
        return;
    }
    for (int i = 0; i < N; ++i) {
        if (!visited[i] && sum - K + kits[i] >= 500) {
            visited[i] = 1;
            dfs(N, K, depth + 1, sum - K + kits[i], kits, visited, count);
            visited[i] = 0;
        }
    }
}