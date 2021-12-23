#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;
using pii = pair<int, int>;

/**
 * @see [빈도 정렬](https://www.acmicpc.net/problem/2910)
 */
int main() {
    fastio;
    int N, C;
    cin >> N >> C;
    int items[N];
    unordered_map<int, int> count, order;
    int order_idx = 0;
    for (int i = 0; i < N; ++i) {
        cin >> items[i];
        count[items[i]]++;
        if (order[items[i]] == 0) {
            order[items[i]] = ++order_idx;
        }
    }

    vector<pii> pairs;
    for (auto& item : count) {
        pairs.push_back(item);
    }

    sort(pairs.begin(), pairs.end(), [&order](pii& a, pii& b) -> bool {
        return a.second == b.second ? order[a.first] < order[b.first] : a.second > b.second;
    });

    int size = pairs.size();
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < pairs[i].second; ++j) {
            cout << pairs[i].first << ' ';
        }
    }

    return 0;
}