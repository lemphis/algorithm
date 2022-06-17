#include <iostream>
#include <queue>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

/**
 * @see [N번째 큰 수](https://www.acmicpc.net/problem/2075)
 */
int main() {
    fastio;
    int N;
    cin >> N;

    vector<vector<int> > nums(N, vector<int>(N));
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            cin >> nums[c][r];
        }
    }

    int answer = 1 << 31;
    for (int i = 0; i < N; ++i) {
        int tmp = 1 << 31;
        int idx = 0;
        for (int j = 0; j < N; ++j) {
            if (tmp < nums[j].back()) {
                tmp = nums[j].back();
                idx = j;
            }
        }
        answer = tmp;
        nums[idx].pop_back();
    }

    cout << answer << endl;

    return 0;
}