#include <cmath>
#include <iostream>

#define endl '\n'

using std::cin;
using std::cout;
using std::ios;

/**
 * @see [달팽이는 올라가고 싶다](https://www.acmicpc.net/problem/2869)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int a, b, v;
    cin >> a >> b >> v;
    long cnt = (long)ceil((double)(v - a) / (double)(a - b));
    cout << cnt + 1 << endl;
}