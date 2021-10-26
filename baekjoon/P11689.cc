#include <iostream>

using namespace std;

typedef long long ll;

ll phi(ll n);

/**
 * @see [GCD(n, k) = 1](https://www.acmicpc.net/problem/11689)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    ll n;
    cin >> n;

    cout << phi(n) << endl;
    return 0;
}

ll phi(ll n) {
    ll ans = n;
    ll prime = 2;
    while (prime * prime <= n) {
        if (n % prime == 0) {
            while (n % prime == 0) {
                n /= prime;
            }
            ans -= (ans / prime);
        }
        prime++;
    }
    if (n > 1) {
        ans -= (ans / n);
    }

    return ans;
}