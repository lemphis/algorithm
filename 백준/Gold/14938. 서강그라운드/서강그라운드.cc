#include <iostream>
#include <queue>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

using pii = pair<int, int>;

int main() {
    fastio;

    int n, m, r;
    cin >> n >> m >> r;
    vector<int> t(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }
    vector<vector<pii>> field(n, vector<pii>());
    for (int i = 0; i < r; ++i) {
        int a, b, l;
        cin >> a >> b >> l;
        --a, --b;
        field[a].push_back({b, l});
        field[b].push_back({a, l});
    }

    int max_count = 0;
    vector<int> dist(n, 1e9);
    for (int i = 0; i < n; ++i) {
        fill(dist.begin(), dist.end(), 1e9);
        queue<int> q;
        dist[i] = 0;
        q.push(i);
        while (!q.empty()) {
            int now = q.front();
            q.pop();
            for (int i = 0; i < field[now].size(); ++i) {
                int next = field[now][i].first;
                if (dist[now] + field[now][i].second < dist[next]) {
                    dist[next] = dist[now] + field[now][i].second;
                    q.push(next);
                }
            }
        }
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (dist[i] <= m) {
                count += t[i];
            }
        }
        max_count = max(max_count, count);
    }

    cout << max_count;

    return 0;
}