#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;
using pii = pair<int, int>;

/**
 * @see [멀티버스 Ⅱ](https://www.acmicpc.net/problem/18869)
 */
int main() {
    fastio;
    int M, N;
    cin >> M >> N;
    map<vector<int>, int> mp;
    for (int i = 0; i < M; ++i) {
        vector<int> key(N);
        pii universe[N];
        for (int idx = 0; idx < N; ++idx) {
            cin >> universe[idx].first;
            universe[idx].second = idx;
        }
        sort(universe, universe + N);
        int k = 0;
        for (int j = 0; j < N; ++j) {
            if (j && universe[j - 1].first != universe[j].first) {
                k++;
            }
            key[universe[j].second] = k;
        }
        mp[key]++;
    }

    int count = 0;
    for (auto& it : mp) {
        count += it.second * (it.second - 1) / 2;
    }

    cout << count << endl;

    return 0;
}