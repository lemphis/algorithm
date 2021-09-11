#include <algorithm>
#include <iostream>

#define endl '\n'

using std::cin;
using std::cout;
using std::ios;
using std::string;
using std::swap;
using std::to_string;

/**
 * @see [장미](https://www.acmicpc.net/problem/3343)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    long long N;
    int A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    if (A < C) {
        swap(A, C);
        swap(B, D);
    }
    int a_max = N / A;
    if (N % A != 0) a_max++;
    int c_max = N / C;
    if (N % C != 0) c_max++;
    string min_price = "99999999999999999999";
    // TODO: big num 처리, for 반복 횟수 감소 처리
    for (int i = a_max; i >= 0; --i) {
        for (int j = 0; j <= c_max; ++j) {
            if (A * i + C * j >= N) {
                string price = to_string(i * B + j * D);
                if (min_price > price) {
                    min_price = price;
                }
                break;
            }
        }
    }
    cout << min_price << endl;
}