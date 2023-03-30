#include <cstring>
#include <iostream>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

void dfs(string& s, int idx, int N, vector<int>& ans, bool visited[]);

int main() {
    fastio;
    string s;
    cin >> s;
    int N = 0;
    int length = s.length();
    if (length < 10) {
        N = length;
    } else {
        N = 9 + (length - 9) / 2;
    }
    bool visited[N + 1];
    memset(visited, 0, sizeof(visited));

    vector<int> ans;
    dfs(s, 0, N, ans, visited);

    return 0;
}

void dfs(string& s, int idx, int N, vector<int>& ans, bool visited[]) {
    if (ans.size() == N) {
        for (int i = 0; i < N; ++i) {
            cout << ans[i] << ' ';
        }
        exit(0);
    }
    if (idx < s.length()) {
        int one = stoi(s.substr(idx, 1));
        if (one != 0 && !visited[one]) {
            visited[one] = 1;
            ans.push_back(one);
            dfs(s, idx + 1, N, ans, visited);
            visited[one] = 0;
            ans.pop_back();
        }
    }
    if (idx < s.length() - 1) {
        int two = stoi(s.substr(idx, 2));
        if (two <= N && !visited[two]) {
            visited[two] = 1;
            ans.push_back(two);
            dfs(s, idx + 2, N, ans, visited);
            visited[two] = 0;
            ans.pop_back();
        }
    }
}