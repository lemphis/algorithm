#include <climits>
#include <iostream>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;

    int sum = 0;
    int ans = 0;
    int diff = INT_MAX;

    for (int i = 0; i < 10; i++) {
        int x;
        cin >> x;
        sum += x;

        int cur_diff = abs(sum - 100);
        if (cur_diff < diff || (cur_diff == diff && sum > ans)) {
            diff = cur_diff;
            ans = sum;
        }

        if (sum >= 100) {
            break;
        }
    }

    cout << ans;

    return 0;
}