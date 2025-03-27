#include <iostream>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

using vii = vector<vector<int>>;

int dfs(const vii& tree, int node, int parent, int depth);

int main() {
    fastio;
    int N;
    cin >> N;
    vii tree(N);
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    cout << (dfs(tree, 0, -1, 0) & 1 ? "Yes" : "No");

    return 0;
}

int dfs(const vii& tree, int node, int parent, int depth) {
    if (node != 0 && tree[node].size() == 1) {
        return depth;
    }

    int count = 0;
    for (int next : tree[node]) {
        if (next != parent) {
            count += dfs(tree, next, node, depth + 1);
        }
    }

    return count;
}