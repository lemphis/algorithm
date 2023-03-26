#include <iostream>
#include <set>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

void dfs(int num[], int size, int depth, int idx, int k, string value, set<string>& set, bool visited[]);

int main() {
    fastio;
    int n, k;
    cin >> n >> k;
    int num[n];
    bool visited[n];
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
        visited[i] = 0;
    }

    set<string> set;
    dfs(num, n, 0, 0, k, "", set, visited);

    cout << set.size();

    return 0;
}

void dfs(int num[], int size, int depth, int idx, int k, string value, set<string>& set, bool visited[]) {
    if (depth == k) {
        set.insert(value);
        return;
    }
    for (int i = 0; i < size; ++i) {
        if (!visited[i]) {
            visited[i] = 1;
            value += to_string(num[i]);
            dfs(num, size, depth + 1, i + 1, k, value, set, visited);
            visited[i] = 0;
            value.erase(value.size() - to_string(num[i]).size());
        }
    }
}