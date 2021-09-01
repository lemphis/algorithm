#include <iostream>

#define endl '\n'

using std::cin;
using std::cout;
using std::ios;

/**
 * @see [골드바흐의 추측](https://www.acmicpc.net/problem/9020)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t, n, half;
    bool primes[10001] = {0};
    cin >> t;
    while (t--) {
        cin >> n;
        half = n / 2;
        for (int i = 2; i <= n; ++i) {
            if (!primes[i]) {
                int times = 2;
                while (i * times <= n) {
                    if (!primes[i * times]) {
                        primes[i * times] = 1;
                    }
                    times++;
                }
            }
        }
        while (half) {
            if (!primes[half] && !primes[n - half]) {
                cout << half << ' ' << n - half << endl;
                break;
            }
            half--;
        }
    }
}
