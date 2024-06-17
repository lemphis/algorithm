#include <algorithm>
#include <iostream>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;
    int n, k;
    cin >> n >> k;
    vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }

    vector<int> counts(k + 1, 100000000);
    counts[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = coins[i]; j <= k; ++j) {
            counts[j] = min(counts[j], counts[j - coins[i]] + 1);
        }
    }

    cout << (counts[k] == 100000000 ? -1 : counts[k]);

    return 0;
}