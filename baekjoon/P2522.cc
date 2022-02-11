#include <algorithm>
#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

/**
 * @see [별 찍기 - 12](https://www.acmicpc.net/problem/2522)
 */
int main() {
    fastio;
    int n;
    cin >> n;

    for (int r = 1; r <= n * 2 - 1; ++r) {
        for (int c = 0; c < abs(r - n); ++c) {
            cout << ' ';
        }
        for (int c = 0; c < n - abs(r - n); ++c) {
            cout << '*';
        }
        cout << endl;
    }

    return 0;
}