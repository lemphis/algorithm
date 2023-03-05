#include <algorithm>
#include <iostream>
#include <numeric>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

const int DWARFS_COUNT{9};

int main() {
    fastio;
    int dwarfs[DWARFS_COUNT];
    for (int i = 0; i < DWARFS_COUNT; ++i) {
        cin >> dwarfs[i];
    }
    int sum = accumulate(dwarfs, dwarfs + DWARFS_COUNT, 0);
    for (int i = 0; i < DWARFS_COUNT; ++i) {
        bool find_dwarfs{false};
        for (int j = i + 1; j < DWARFS_COUNT; ++j) {
            if (sum - (dwarfs[i] + dwarfs[j]) == 100) {
                dwarfs[i] = dwarfs[j] = -1;
                find_dwarfs = true;
                break;
            }
        }
        if (find_dwarfs) {
            break;
        }
    }

    sort(dwarfs, dwarfs + DWARFS_COUNT);

    // skip two dwarfs
    for (int i = 2; i < DWARFS_COUNT; ++i) {
        cout << dwarfs[i] << endl;
    }

    return 0;
}