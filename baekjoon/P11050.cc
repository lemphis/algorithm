#include <iostream>

#define endl '\n'

using std::cin;
using std::cout;
using std::ios;

int factorial(int num);

/**
 * @see [이항 계수 1](https://www.acmicpc.net/problem/11050)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    cout << factorial(n) / (factorial(n - k) * factorial(k)) << endl;
}

int factorial(int num) {
    if (num == 0 || num == 1) return 1;
    return num * factorial(num - 1);
}