#include <iostream>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int dfs(const vector<vector<int>>& tree, const vector<bool>& is_apple,
        int start, int depth, int k);

int main() {
    fastio;
    int n, k;
    cin >> n >> k;
    vector<vector<int>> tree(n);
    for (int i = 0; i < n - 1; ++i) {
        int p, c;
        cin >> p >> c;
        tree[p].push_back(c);
    }
    vector<bool> is_apple(n);
    for (int i = 0; i < n; ++i) {
        int b;
        cin >> b;
        is_apple[i] = b == 1;
    }

    cout << dfs(tree, is_apple, 0, 0, k);

    return 0;
}

int dfs(const vector<vector<int>>& tree, const vector<bool>& is_apple,
        int start, int depth, int k) {
    if (depth > k) {
        return 0;
    }
    int sum = 0;
    if (is_apple[start]) {
        sum += 1;
    }
    for (int i = 0; i < tree[start].size(); ++i) {
        sum += dfs(tree, is_apple, tree[start][i], depth + 1, k);
    }

    return sum;
}