#include <iostream>
#include <queue>
#include <set>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

/**
 * @see [보석 도둑](https://www.acmicpc.net/problem/1202)
 */
int main() {
    fastio;
    int N, K;
    cin >> N >> K;
    priority_queue<pii> queue;
    for (int i = 0; i < N; ++i) {
        ll weight, value;
        cin >> weight >> value;
        queue.push(make_pair(value, weight));
    }

    multiset<ll> bags;
    for (int i = 0; i < K; ++i) {
        ll weight;
        cin >> weight;
        bags.insert(weight);
    }

    ll sum = 0;
    while (N--) {
        auto [value, weight] = queue.top();
        queue.pop();
        multiset<ll>::iterator pos = bags.lower_bound(weight);
        if (pos != bags.end()) {
            bags.erase(pos);
            sum += value;
        }
    }

    cout << sum << endl;

    return 0;
}