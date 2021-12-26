#include <cmath>
#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

/**
 * @see [터렛](https://www.acmicpc.net/problem/1002)
 */
int main() {
    fastio;
    int T;
    int x1, y1, r1, x2, y2, r2;
    double dist;
    int res;

    cin >> T;

    while (T--) {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        dist = sqrt((double)(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1))));

        if ((r1 == r2) & (dist == 0))
            res = -1;
        else if ((r1 - r2 == dist) || (r2 - r1 == dist) || (r1 + r2 == dist))
            res = 1;
        else if ((dist == 0 && r1 == r2) || (r1 + dist < r2) || (r2 + dist < r1) || (r1 + r2 < dist))
            res = 0;
        else
            res = 2;

        cout << res << endl;
    }

    return 0;
}