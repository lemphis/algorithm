#include <iostream>
#include <queue>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define MAX 5'000'000

using namespace std;

int nums[MAX];

/**
 * @see [최솟값 찾기](https://www.acmicpc.net/problem/11003)
 */
int main() {
    fastio;
    int N, L;
    cin >> N >> L;
    for (int i = 0; i < N; ++i) cin >> nums[i];

    deque<pair<int, int> > dq;
    for (int i = 0; i < N; ++i) {
        if (!dq.empty() && dq.front().second <= i - L) dq.pop_front();
        while (!dq.empty() && nums[i] < dq.back().first) dq.pop_back();

        dq.push_back(make_pair(nums[i], i));
        cout << dq.front().first << ' ';
    }

    return 0;
}