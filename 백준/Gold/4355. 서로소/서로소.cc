#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int phi(int n);

int main() {
    fastio;
    while (1) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }
        cout << phi(n) << endl;
    }

    return 0;
}

int phi(int n) {
    if (n == 1) {
        return 0;
    }
    int pi = n;
    int prime = 2;
    while (prime * prime <= n) {
        if (n % prime == 0) {
            while (n % prime == 0) {
                n /= prime;
            }
            pi -= pi / prime;
        }
        ++prime;
    }
    if (n > 1) {
        pi -= pi / n;
    }

    return pi;
}