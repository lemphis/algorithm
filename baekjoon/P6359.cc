#include <cmath>
#include <iostream>

#define endl '\n'

using std::cin;
using std::cout;
using std::ios;

/**
 * @see [만취한 상범](https://www.acmicpc.net/problem/6359)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    bool rooms[101];
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            rooms[i] = 1;
        }
        for (int i = 2; i <= n; ++i) {
            for (int j = 2; j <= n; ++j) {
                if (j % i == 0) {
                    rooms[j] = !rooms[j];
                }
            }
        }
        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            if (rooms[i]) cnt++;
        }
        cout << cnt << endl;
    }
}
