#include <iostream>
#include <map>
#include <queue>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

void bfs(map<int, vector<int>>& tree, vector<int>& child);

int main() {
    fastio;
    int N;
    cin >> N;
    map<int, vector<int>> tree;
    for (int i = 1; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    vector<int> child(N + 1);
    bfs(tree, child);
    for (int i = 2; i <= N; ++i) {
        cout << child[i] << endl;
    }

    return 0;
}

void bfs(map<int, vector<int>>& tree, vector<int>& child) {
    queue<int> q;
    child[0] = 1;
    q.push(1);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int i = 0; i < tree[node].size(); ++i) {
            int child_node = tree[node][i];
            if (child[child_node] == 0) {
                child[child_node] = node;
                q.push(child_node);
            }
        }
    }
}