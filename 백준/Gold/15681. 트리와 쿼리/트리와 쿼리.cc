#include <iostream>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

using vvi = vector<vector<int>>;

void dfs(const vvi& tree, int node, int parent);

int dp[100'001];

int main() {
    fastio;

    int N, R, Q;
    cin >> N >> R >> Q;
    vvi tree(N + 1, vector<int>());
    for (int i = 0; i < N - 1; ++i) {
        int U, V;
        cin >> U >> V;
        tree[U].push_back(V);
        tree[V].push_back(U);
    }

    for (int i = 1; i < 100'001; ++i) {
        dp[i] = -1;
    }

    dfs(tree, R, -1);

    string output;
    output.reserve(300'000);
    while (Q--) {
        int U;
        cin >> U;
        output += to_string(dp[U]);
        output += '\n';
    }

    cout << output;

    return 0;
}

void dfs(const vvi& tree, int node, int parent) {
    dp[node] = 1;
    for (int next : tree[node]) {
        if (next != parent) {
            dfs(tree, next, node);
            dp[node] += dp[next];
        }
    }
}