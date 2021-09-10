#include <iostream>

#define endl '\n'

using std::cin;
using std::cout;
using std::ios;

int gcd(int a, int b);

/**
 * @see [링](https://www.acmicpc.net/problem/3036)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N;
    cin >> N;
    int rings[N];
    for (int i = 0; i < N; ++i) {
        cin >> rings[i];
    }
    for (int i = 1; i < N; ++i) {
        int num = gcd(rings[0], rings[i]);
        cout << (rings[0] / num) << '/' << (rings[i] / num) << endl;
    }
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}