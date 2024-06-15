#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;
    int n;
    cin >> n;
    if (n > 1023) {
        cout << -1 << endl;
        return 0;
    }

    long nums[1023] = {0};
    for (int i = 0; i < 10; ++i) {
        nums[i] = i;
    }
    int idx = 10;
    int before = 1;
    while (idx < 1023) {
        long tmp = nums[before];
        for (int i = 0; i < 10; ++i) {
            if (tmp % 10 > i) {
                nums[idx] = tmp * 10 + i;
                ++idx;
            }
        }
        ++before;
    }

    cout << nums[n - 1];

    return 0;
}