#include <iostream>

#define endl '\n'

using std::cin;
using std::cout;
using std::ios;

int gcd(int a, int b);
int lcm(int a, int b);

/**
 * @see [카잉 달력](https://www.acmicpc.net/problem/6064)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int T, M, N, x, y;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        cin >> M >> N >> x >> y;
        int max = lcm(M, N);
        while (1) {
            if (x > max || (x - 1) % N + 1 == y) {
                break;
            }
            x += M;
        }
        cout << (x > max ? -1 : x) << endl;
    }
    return 0;
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}