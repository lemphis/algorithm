#include <cmath>
#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

typedef long long ll;

using namespace std;

int main() {
    fastio;
    ll n;
    cin >> n;
    ll ans = sqrt(n);
    if (ans * ans < n) {
        ans++;
    }

    cout << ans;

    return 0;
}