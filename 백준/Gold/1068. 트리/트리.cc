#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

void remove_node(map<int, vector<int>>& tree, int parent_node, int drop_target_node);
void dfs(map<int, vector<int>>& tree, int parent_node, int drop_target_node, int& count);

int main() {
    fastio;
    int N;
    cin >> N;
    map<int, vector<int>> tree;
    for (int i = 0; i < N; ++i) {
        tree[i] = vector<int>();
    }

    int root_node;
    for (int node = 0; node < N; ++node) {
        int parent_node;
        cin >> parent_node;
        if (parent_node == -1) {
            root_node = node;
            continue;
        }
        tree[parent_node].push_back(node);
    }

    int drop_target_node;
    cin >> drop_target_node;

    if (drop_target_node == root_node) {
        cout << 0;
        return 0;
    }

    remove_node(tree, root_node, drop_target_node);
    if (tree[root_node].empty()) {
        cout << 1;
        return 0;
    }

    int count = 0;
    dfs(tree, root_node, drop_target_node, count);

    cout << count;

    return 0;
}

void remove_node(map<int, vector<int>>& tree, int parent_node, int drop_target_node) {
    for (auto node : tree[parent_node]) {
        if (node == drop_target_node) {
            auto iter = find(tree[parent_node].begin(), tree[parent_node].end(), drop_target_node);
            if (iter != tree[parent_node].end()) {
                tree[parent_node].erase(iter);
                return;
            }
        } else {
            remove_node(tree, node, drop_target_node);
        }
    }
}

void dfs(map<int, vector<int>>& tree, int parent_node, int drop_target_node, int& count) {
    for (auto node : tree[parent_node]) {
        if (tree[node].size() > 0) {
            dfs(tree, node, drop_target_node, count);
        } else {
            ++count;
        }
    }
}