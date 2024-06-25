#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;
using pii = pair<int, int>;

vector<pii>::iterator find_item(vector<pii>& items, int pos);

int main() {
    fastio;
    int N, M;
    cin >> N >> M;
    vector<pii> items(N + M);
    bool visited[101] = {false};
    for (int i = 0; i < N + M; ++i) {
        cin >> items[i].first >> items[i].second;
    }

    int ans = 0;

    queue<pii> q;
    q.push({1, 0});
    visited[1] = true;
    while (!q.empty()) {
        pii now = q.front();
        int now_pos = now.first;
        int now_count = now.second;
        if (now_pos == 100) {
            ans = now_count;
            break;
        }
        q.pop();
        for (int i = 1; i <= 6; ++i) {
            int next_pos = now_pos + i;
            if (next_pos > 100) {
                break;
            }
            auto item_pos = find_item(items, next_pos);
            while (item_pos != items.end()) {
                visited[next_pos] = true;
                next_pos = (*item_pos).second;
                item_pos = find_item(items, next_pos);
            }
            if (!visited[next_pos]) {
                visited[next_pos] = true;
                q.push({next_pos, now_count + 1});
            }
        }
    }

    cout << ans;

    return 0;
}

vector<pii>::iterator find_item(vector<pii>& items, int pos) {
    return find_if(items.begin(), items.end(), [pos](const pii& p) { return p.first == pos; });
}