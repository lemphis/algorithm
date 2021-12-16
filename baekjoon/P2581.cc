#include <iostream>

using namespace std;

#define endl '\n'

/**
 * @see [소수](https://www.acmicpc.net/problem/2581)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int M, N;
    cin >> M >> N;

    int sum = 0;
    int min = 0;
    bool is_prime[N + 1];
    for (int i = 0; i <= N; ++i) {
        is_prime[i] = 1;
    }

    for (int i = 2; i <= N; ++i) {
        int times = 2;
        if (is_prime[i]) {
            if (i >= M) {
                if (min == 0) {
                    min = i;
                }
                sum += i;
            }
            while (i * times <= N) {
                is_prime[i * times++] = 0;
            }
        }
    }

    if (sum == 0) {
        cout << -1 << endl;
    } else {
        cout << sum << endl;
        cout << min << endl;
    }

    return 0;
}