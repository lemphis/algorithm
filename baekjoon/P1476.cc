#include <iostream>

#define endl '\n'

using std::cin;
using std::cout;
using std::ios;

/**
 * @see [날짜 계산](https://www.acmicpc.net/problem/1476)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int e, s, m, ans = 1;
    cin >> e >> s >> m;
    while (1) {
        if (e == (ans - 1) % 15 + 1 && s == (ans - 1) % 28 + 1 && m == (ans - 1) % 19 + 1) {
            cout << ans << endl;
            break;
        }
        ans++;
    }
}