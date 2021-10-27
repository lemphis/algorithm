#include <iostream>

using namespace std;

using ll = long long;

ll gcd(ll a, ll b);
ll extended_euclid(ll n, ll a);

/**
 * @see [역원(Inverse) 구하기](https://www.acmicpc.net/problem/14565)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    ll N, A;
    cin >> N >> A;

    cout << N - A << ' ';
    if (gcd(N, A) != 1) {
        cout << -1 << endl;
    } else {
        ll inverse = extended_euclid(N, A);
        while (inverse < 0) {
            inverse += N;
        }

        cout << inverse << endl;
    }

    return 0;
}

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

ll extended_euclid(ll n, ll a) {
    ll r1 = n, r2 = a;
    ll t1 = 0, t2 = 1;
    ll r, q, t;

    while (r2) {
        q = r1 / r2;

        r = r1 % r2;
        r1 = r2;
        r2 = r;

        t = t1 - t2 * q;
        t1 = t2;
        t2 = t;
    }

    return t1;
}