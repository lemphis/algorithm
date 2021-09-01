#include <algorithm>
#include <cstring>
#include <iostream>

#define endl '\n'

using std::cin;
using std::cout;
using std::greater;
using std::ios;
using std::sort;

/**
 * @see [30](https://www.acmicpc.net/problem/10610)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    char n[100000];
    cin >> n;
    int sum_digit = 0;
    int len = strlen(n);
    for (int i = 0; i < strlen(n); ++i) {
        sum_digit += n[i] - '0';
    }
    sort(n, n + len, greater<int>());
    if (sum_digit % 3 != 0 || n[len - 1] != '0')
        cout << -1 << endl;
    else
        cout << n << endl;
}
