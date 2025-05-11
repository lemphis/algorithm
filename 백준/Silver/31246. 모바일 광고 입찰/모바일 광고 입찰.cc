#include <algorithm>
#include <iostream>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;

    int N, K;
    cin >> N >> K;
    vector<int> bids;
    for (int i = 0; i < N; ++i) {
        int A, B;
        cin >> A >> B;
        if (A < B) {
            bids.push_back(B - A);
        }
    }

    sort(bids.begin(), bids.end());

    int already = N - bids.size();
    if (already >= K) {
        cout << 0;
    } else {
        int idx = K - already - 1;
        cout << bids[idx];
    }

    return 0;
}