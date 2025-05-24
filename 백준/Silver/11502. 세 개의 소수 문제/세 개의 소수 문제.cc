#include <cstring>
#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;

    int T;
    cin >> T;
    bool is_prime[1'001];
    memset(is_prime, 1, sizeof(is_prime));
    for (int i = 2; i < 32; ++i) {
        if (is_prime[i]) {
            int times = 2;
            while (i * times < 1'001) {
                is_prime[i * times] = false;
                ++times;
            }
        }
    }
    while (T--) {
        int K;
        cin >> K;
        int a = 0, b = 0, c = 0;
        for (int i = 2; i < 1'001; ++i) {
            if (is_prime[i]) {
                for (int j = i; j < 1'001; ++j) {
                    if (is_prime[j]) {
                        for (int k = j; k < 1'001; ++k) {
                            if (is_prime[k] && i + j + k == K) {
                                a = i, b = j, c = k;
                                goto done;
                            }
                        }
                    }
                }
            }
        }
    done:
        if (a == 0 && b == 0 && c == 0) {
            cout << 0 << endl;
        } else {
            cout << a << ' ' << b << ' ' << c << endl;
        }
    }

    return 0;
}