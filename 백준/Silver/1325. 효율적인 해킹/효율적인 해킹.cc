#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;
using pii = pair<int, int>;

const int MAX = 10'001;
vector<int> graph[MAX];
vector<pii> ans;
bool visited[MAX];

void bfs(int start);

int main() {
    fastio;
    int N, M;
    cin >> N >> M;
    while (M--) {
        int A, B;
        cin >> A >> B;
        graph[B].push_back(A);
    }

    for (int i = 1; i <= N; ++i) {
        bfs(i);
        memset(visited, 0, sizeof(visited));
    }

    sort(ans.begin(), ans.end(), [](pii& a, pii& b) -> bool {
        if (a.second == b.second) {
            return a.first < b.first;
        }
        return a.second > b.second;
    });

    int max_count = ans[0].second;
    for (int i = 0; i < ans.size(); ++i) {
        if (max_count != ans[i].second) {
            break;
        }
        cout << ans[i].first << ' ';
    }

    return 0;
}

void bfs(int start) {
    int count = 0;
    queue<int> q;
    q.push(start);
    visited[start] = 1;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        ++count;
        for (int i = 0; i < graph[now].size(); ++i) {
            if (!visited[graph[now][i]]) {
                q.push(graph[now][i]);
                visited[graph[now][i]] = 1;
            }
        }
    }

    ans.push_back({start, count});
}