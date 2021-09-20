#include <iostream>

using namespace std;

#define endl '\n'
#define MAX 1000000
#define ll long long

ll square_free_count(int n);

int mu[MAX];

/**
 * @see [제곱 ㄴㄴ](https://www.acmicpc.net/problem/1557)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    mu[1] = 1;
    for (int i = 1; i < MAX; i++) {
        for (int j = 2 * i; j < MAX; j += i) {
            mu[j] -= mu[i];
        }
    }
    ll K;
    cin >> K;
    ll start = 0, end = K * 2;
    while (start < end - 1) {
        ll mid = (start + end) / 2;
        if (square_free_count(mid) < K) {
            start = mid;
        } else {
            end = mid;
        }
    }
    cout << end << endl;
}

ll square_free_count(int n) {
    ll count = 0;
    for (ll i = 1; i * i <= n; ++i) {
        count += mu[i] * n / (i * i);
    }
    return count;
}