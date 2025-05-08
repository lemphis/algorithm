#include <iostream>
#include <set>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;

    int N, M;
    cin >> N >> M;
    int nums[1'000];
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }
    set<int> target;
    for (int i = 0; i < M; ++i) {
        int num;
        cin >> num;
        target.insert(num);
    }

    int count = 0;
    for (int i = 0; i < M; ++i) {
        if (target.find(nums[i]) == target.end()) {
            ++count;
        }
    }

    cout << count;

    return 0;
}