#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

long count_moo(long n);

int main() {
    fastio;

    long N;
    cin >> N;
    long lo = 0, hi = 2'142'857'143;
    while (lo + 1 < hi) {
        long mid = (lo + hi) >> 1;
        long moo = count_moo(mid);
        if (mid - moo >= N) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    cout << hi;

    return 0;
}

long count_moo(long n) {
    return n / 3 + n / 5 - n / 15;
}