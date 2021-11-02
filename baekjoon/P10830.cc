#include <iostream>
#include <vector>

using namespace std;

using Matrix = vector<vector<int>>;

#define endl '\n'
#define DIVISOR 1'000

Matrix operator*(Matrix& a, Matrix& b);

/**
 * @see [행렬 제곱](https://www.acmicpc.net/problem/10830)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N;
    long long B;
    cin >> N >> B;
    Matrix A(N, vector<int>(N)), E(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> A[i][j];
            if (i == j) {
                E[i][j] = 1;
            }
        }
    }

    while (B > 0) {
        if (B & 1) {
            E = E * A;
        }
        A = A * A;
        B /= 2;
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << E[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}

Matrix operator*(Matrix& a, Matrix& b) {
    size_t size = a.size();
    Matrix result(size, vector<int>(size));
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size; ++j) {
            for (size_t k = 0; k < size; ++k) {
                result[i][j] += a[i][k] * b[k][j];
            }
            result[i][j] %= DIVISOR;
        }
    }

    return result;
}