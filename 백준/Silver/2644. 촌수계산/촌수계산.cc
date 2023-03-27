#include <iostream>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

void dfs(int n, int a, int b, int depth, vector<vector<int>>& people, int& ans, vector<bool>& visited);

int main() {
    fastio;
    int n, a, b;
    cin >> n >> a >> b;
    int m;
    cin >> m;
    vector<vector<int>> people(n + 1, vector<int>());
    vector<bool> visited(n + 1);
    while (m--) {
        int x, y;
        cin >> x >> y;
        people[x].push_back(y);
        people[y].push_back(x);
    }

    int ans = -1;
    dfs(n, a, b, 1, people, ans, visited);

    cout << ans;

    return 0;
}

void dfs(int n, int a, int b, int depth, vector<vector<int>>& people, int& ans, vector<bool>& visited) {
    for (int i = 0; i < people[a].size(); ++i) {
        if (!visited[a]) {
            visited[a] = 1;
            if (people[a][i] == b) {
                ans = depth;
                return;
            }
            dfs(n, people[a][i], b, depth + 1, people, ans, visited);
            visited[a] = 0;
        }
    }
}