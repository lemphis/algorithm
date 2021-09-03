#include <iostream>

#define endl '\n'

using std::cin;
using std::cout;
using std::ios;

int gcd(int a, int b);

/**
 * @see [최대공약수와 최소공배수](https://www.acmicpc.net/problem/2609)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int a, b;
    cin >> a >> b;
    if (a < b) {
        int temp = a;
        a = b;
        b = temp;
    }
    int GCD = gcd(a, b);
    cout << gcd(a, b) << endl << a * b / GCD << endl;
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}