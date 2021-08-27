#include <iostream>

#define endl '\n'

using std::cin;
using std::cout;
using std::ios;

/**
 * @see [수학은 체육과목 입니다](https://www.acmicpc.net/problem/15894)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    long n;
    cin >> n;
    if (n == 1)
        cout << 4 << endl;
    else
        cout << n * 4 << endl;
}