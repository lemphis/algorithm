#include <algorithm>
#include <iostream>
#include <map>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;
    int N, M;
    cin >> N >> M;
    int nums[N];
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }

    sort(nums, nums + N);

    map<int, int> map;
    for (int i = 0; i < N; ++i) {
        map.insert({nums[i], i});
    }

    while (M--) {
        int num;
        cin >> num;
        auto iter = map.find(num);
        if (iter == map.end()) {
            cout << -1;
        } else {
            cout << (*iter).second;
        }
        cout << endl;
    }

    return 0;
}