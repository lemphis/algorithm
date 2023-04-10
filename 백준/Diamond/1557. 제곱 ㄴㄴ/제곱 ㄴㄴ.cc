#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

const int MAX = 1'000'000;

long square_free_count(int n);

int mu[MAX];

int main() {
    fastio;
    mu[1] = 1;
    for (int i = 1; i < MAX; i++) {
        for (int j = 2 * i; j < MAX; j += i) {
            mu[j] -= mu[i];
        }
    }
    long K;
    cin >> K;
    long start = 0, end = K * 2;
    while (start < end - 1) {
        long mid = (start + end) / 2;
        if (square_free_count(mid) < K) {
            start = mid;
        } else {
            end = mid;
        }
    }
    cout << end << endl;

    return 0;
}

long square_free_count(int n) {
    long count = 0;
    for (long i = 1; i * i <= n; ++i) {
        count += mu[i] * n / (i * i);
    }
    return count;
}