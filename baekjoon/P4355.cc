#include <cmath>
#include <iostream>

using namespace std;

int phi(int n);

/**
 * @see [서로소](https://www.acmicpc.net/problem/4355)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

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
    int pi = 1;
    int prime = 2;
    while (prime * prime <= n) {
        if (n % prime == 0) {
            int times = 0;
            while (n % prime == 0) {
                n /= prime;
                times++;
            }
            pi *= (pow(prime, times) - pow(prime, times - 1));
        }
        prime++;
    }
    if (n > 1) {
        pi *= (pow(n, 1) - pow(n, 0));
    }

    return pi;
}