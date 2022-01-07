#include <algorithm>
#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

bool check(int target, int N, int pos[], int C);

/**
 * @see [공유기 설치](https://www.acmicpc.net/problem/2110)
 */
int main() {
    fastio;
    int N, C;
    cin >> N >> C;
    int pos[N];
    for (int i = 0; i < N; ++i) {
        cin >> pos[i];
    }

    sort(pos, pos + N);

    int lo = 0, hi = pos[N - 1];
    while (lo + 1 < hi) {
        int mid = (lo + hi) >> 1;
        if (check(mid, N, pos, C))
            lo = mid;
        else
            hi = mid;
    }

    cout << lo << endl;

    return 0;
}

bool check(int target, int N, int pos[], int C) {
    int pivot = pos[0];
    int count = 1;
    for (int i = 1; i < N; ++i) {
        if (pos[i] - pivot >= target) {
            count++;
            pivot = pos[i];
        }
    }

    return count >= C;
}