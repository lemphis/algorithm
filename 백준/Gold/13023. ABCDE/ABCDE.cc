#include <iostream>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;
using vvi = vector<vector<int>>;

const int MAX = 2'000;

bool visited[MAX] = {false};

void dfs(vvi& relations, int num, int depth, bool& ans);

int main() {
    fastio;
    int N, M;
    cin >> N >> M;
    vvi relations(N, vector<int>());
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        relations[a].push_back(b);
        relations[b].push_back(a);
    }

    bool ans = false;
    for (int i = 0; i < N; ++i) {
        visited[i] = true;
        dfs(relations, i, 1, ans);
        visited[i] = false;
    }

    cout << (ans ? 1 : 0);

    return 0;
}

void dfs(vvi& relations, int num, int depth, bool& ans) {
    if (depth == 5) {
        ans = true;
        return;
    }
    for (int i = 0; i < relations[num].size(); ++i) {
        if (ans) {
            break;
        }
        if (!visited[relations[num][i]]) {
            visited[relations[num][i]] = true;
            dfs(relations, relations[num][i], depth + 1, ans);
            visited[relations[num][i]] = false;
        }
    }
}