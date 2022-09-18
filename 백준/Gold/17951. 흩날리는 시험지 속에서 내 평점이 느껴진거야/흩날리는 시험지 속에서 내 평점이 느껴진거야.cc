#include <iostream>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;
    int N, K;
    cin >> N >> K;
    vector<int> scores(N);
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        cin >> scores[i];
        sum += scores[i];
    }

    int lo = 0, hi = sum + 1;
    while (lo + 1 < hi) {
        int mid = (lo + hi) >> 1;
        int tmp = 0, group = 0;
        for (int i = 0; i < N; ++i) {
            tmp += scores[i];
            if (tmp >= mid) {
                tmp = 0;
                group++;
            }
        }
        if (group >= K) lo = mid;
        else hi = mid;
    }

    cout << lo << endl;

    return 0;
}