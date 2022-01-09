#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

bool check(int target, int N, int M, int bluray[]);

/**
 * @see [기타 레슨](https://www.acmicpc.net/problem/2343)
 */
int main() {
    fastio;
    int N, M;
    cin >> N >> M;
    int bluray[N];
    for (int i = 0; i < N; ++i) {
        cin >> bluray[i];
    }

    int lo = 0, hi = 1e9 + 1;
    while (lo + 1 < hi) {
        int mid = (lo + hi) >> 1;
        if (check(mid, N, M, bluray))
            lo = mid;
        else
            hi = mid;
    }

    cout << hi << endl;

    return 0;
}

bool check(int target, int N, int M, int bluray[]) {
    int count = 0, temp = 0;
    for (int i = 0; i < N; ++i) {
        if (bluray[i] > target) return true;
        if (temp + bluray[i] <= target) {
            temp += bluray[i];
        } else {
            temp = bluray[i];
            count++;
        }
    }

    if (temp > 0) count++;

    return count > M;
}