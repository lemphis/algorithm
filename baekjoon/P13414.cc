#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;
using psi = pair<string, int>;

/**
 * @see [수강신청](https://www.acmicpc.net/problem/13414)
 */
int main() {
    fastio;
    int K, L;
    cin >> K >> L;
    unordered_map<string, int> map;
    for (int i = 0; i < L; ++i) {
        string temp;
        cin >> temp;
        map[temp] = i;
    }

    vector<psi> order(map.begin(), map.end());
    sort(order.begin(), order.end(), [](psi& a, psi& b) -> bool {
        return a.second < b.second;
    });

    for (int i = 0; i < K && i < order.size(); ++i) {
        cout << order[i].first << endl;
    }

    return 0;
}