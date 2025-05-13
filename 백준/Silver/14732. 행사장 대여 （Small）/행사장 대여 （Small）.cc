#include <cstring>
#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;

    int N;
    cin >> N;
    bool map[500][500];
    memset(map, 0, sizeof(map));
    while (N--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int r = y1; r < y2; ++r) {
            for (int c = x1; c < x2; ++c) {
                map[r][c] = true;
            }
        }
    }

    int count = 0;
    for (int r = 0; r < 500; ++r) {
        for (int c = 0; c < 500; ++c) {
            if (map[r][c]) {
                ++count;
            }
        }
    }

    cout << count;

    return 0;
}