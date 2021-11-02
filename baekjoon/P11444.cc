#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
using Matrix = vector<vector<ll>>;

#define endl '\n'
#define DIVISOR 1'000'000'007

Matrix operator*(Matrix& a, Matrix& b);

/**
 * @see [피보나치 수 6](https://www.acmicpc.net/problem/11444)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    ll n;
    cin >> n;
    Matrix ans = {{1, 0}, {0, 1}};
    Matrix temp = {{1, 1}, {1, 0}};

    while (n > 0) {
        if (n & 1) {
            ans = ans * temp;
        }
        temp = temp * temp;
        n /= 2;
    }

    cout << ans[0][1] << endl;
    return 0;
}

Matrix operator*(Matrix& a, Matrix& b) {
    Matrix result(2, vector<ll>(2));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                result[i][j] += a[i][k] * b[k][j];
            }
            result[i][j] %= DIVISOR;
        }
    }

    return result;
}