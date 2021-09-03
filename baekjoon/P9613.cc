#include <iostream>

#define endl '\n'

using std::cin;
using std::cout;
using std::ios;

long gcd(int a, int b);

/**
 * @see [GCD 합](https://www.acmicpc.net/problem/9613)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t, n;
    long ans = 0;
    int arr[100];
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                ans += gcd(arr[i], arr[j]);
            }
        }
        cout << ans << endl;
        ans = 0;
    }
}

long gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}