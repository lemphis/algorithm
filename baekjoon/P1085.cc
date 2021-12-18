#include <iostream>
#include <algorithm>

using namespace std;

#define endl '\n'

/**
 * @see [직사각형에서 탈출](https://www.acmicpc.net/problem/1085)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int x, y, w, h;
    cin >> x >> y >> w >> h;
    int res[4];
    res[0] = y;
    res[1] = h - y;
    res[2] = x;
    res[3] = w - x;

    cout << *(min_element(res, res + 4)) << endl;

    return 0;
}