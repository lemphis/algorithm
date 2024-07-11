#include <cmath>
#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;
    long N;
    cin >> N;
    long temp = N;
    long unit = 1;
    long ans = 0;
    while (temp / 10 > 0) {
        ans += unit * 9 * (long)pow(10, unit - 1) % 1234567;
        temp /= 10;
        ++unit;
    }

    ans = (ans + (N - ((long)pow(10, unit - 1) - 1)) % 1234567 * unit % 1234567) % 1234567;
    cout << ans;

    return 0;
}