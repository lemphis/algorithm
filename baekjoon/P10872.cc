#include <iostream>

using namespace std;

#define endl '\n'

/**
 * @see [팩토리얼](https://www.acmicpc.net/problem/10872)
 */
int main() {
    int n;
    cin >> n;
    int sum = 1;
    for (int i = 1; i <= n; ++i) sum *= i;

    cout << (n == 0 ? 1 : sum);

    return 0;
}