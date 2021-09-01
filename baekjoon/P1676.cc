#include <iostream>

#define endl '\n'

using std::cin;
using std::cout;
using std::ios;

/**
 * @see [팩토리얼 0의 개수](https://www.acmicpc.net/problem/1676)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n, cnt = 0, tmp;
    cin >> n;
    for (int i = 5; i <= n; i *= 5) cnt += n / i;
    cout << cnt << endl;
}