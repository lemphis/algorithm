#include <iostream>

#define endl '\n'
#define ll long long

using std::cin;
using std::cout;
using std::ios;

ll gcd(ll a, ll b);

/**
 * @see [최소공배수](https://www.acmicpc.net/problem/13241)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    ll A, B;
    cin >> A >> B;
    cout << A * B / gcd(A, B) << endl;
}

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}