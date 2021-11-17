#include <algorithm>
#include <iostream>

#define endl '\n'

using namespace std;
using ll = long long;

/**
 * @see [장미](https://www.acmicpc.net/problem/3343)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    ll N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;

    if (B * C > A * D) {
        swap(A, C);
        swap(B, D);
    }

    ll price = A * D;
    ll min_price = 0xffffffffffffffff >> 1;
    ll c_count = A;
    while (--c_count >= 0) {
        ll a_count = (N - (c_count * C)) / A;
        if (a_count < 0) continue;
        if ((N - (c_count * C)) % A > 0) ++a_count;
        price = a_count * B + c_count * D;
        min_price = min(min_price, price);
    }

    cout << min_price << endl;

    return 0;
}