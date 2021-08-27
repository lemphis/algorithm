#include <iostream>

#define endl '\n'

using std::cin;
using std::cout;
using std::ios;

/**
 * @see [벌집](https://www.acmicpc.net/problem/2292)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    int res = 1, times = 1;
    while (res < n) {
        res += 6 * times++;
    }
    cout << times << endl;
}