#include <cmath>
#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

/**
 * @see [Fly me to the Alpha Centauri](https://www.acmicpc.net/problem/1011)
 */
int main() {
    int T;
    cin >> T;

    while (T--) {
        int x, y;
        cin >> x >> y;
        int distance, cnt, a, t;
        distance = y - x;

        if (distance < 4)
            cout << distance << endl;
        else {
            a = ceil(sqrt(distance));
            t = a * a;

            if (t - a + 1 <= distance) {
                cnt = a * 2 - 1;
            } else {
                cnt = a * 2 - 2;
            }
            cout << cnt << endl;
        }
    }

    return 0;
}