#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

bool check(int target, int N, int M, int price[]);

/**
 * @see [용돈 관리](https://www.acmicpc.net/problem/6236)
 */
int main() {
    fastio;
    int N, M;
    cin >> N >> M;
    int price[N];
    for (int i = 0; i < N; ++i) {
        cin >> price[i];
    }

    int lo = 0, hi = 1e9;
    while (lo + 1 < hi) {
        int mid = (lo + hi) >> 1;
        if (check(mid, N, M, price))
            lo = mid;
        else
            hi = mid;
    }

    cout << hi << endl;

    return 0;
}

bool check(int target, int N, int M, int price[]) {
    int count = 1, sum = 0;
    for (int i = 0; i < N; ++i) {
        if (price[i] > target) return true;
        if (sum + price[i] <= target) {
            sum += price[i];
        } else {
            sum = price[i];
            count++;
        }
    }

    return count > M;
}