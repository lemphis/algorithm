#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'
#define INF 1e9
#define MAX 16

int memo[MAX][1 << MAX];
vector<int> adj[MAX];

int tsp(int now, int visited, int N);

/**
 * @see [외판원 순회](https://www.acmicpc.net/problem/2098)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int weight;
            cin >> weight;
            adj[i].push_back(weight);
        }
    }

    fill((int*)memo[0], (int*)memo[MAX], INF);

    cout << tsp(0, 1 << 0, N) << endl;

    return 0;
}

int tsp(int now, int visited, int N) {
    if (visited == (1 << N) - 1) {
        return adj[now][0] ? adj[now][0] : INF;
    }

    if (memo[now][visited] != INF) {
        return memo[now][visited];
    }

    for (int i = 1; i < N; ++i) {
        if ((adj[now][i] > 0) && ((visited & (1 << i)) == 0)) {
            memo[now][visited] = min(memo[now][visited], tsp(i, visited | (1 << i), N) + adj[now][i]);
        }
    }

    return memo[now][visited];
}