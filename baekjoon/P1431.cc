#include <algorithm>
#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

/**
 * @see [시리얼 번호](https://www.acmicpc.net/problem/1431)
 */
int main() {
    fastio;
    int N;
    cin >> N;
    string serials[N];
    for (int i = 0; i < N; ++i) {
        cin >> serials[i];
    }

    sort(serials, serials + N, [](string& a, string& b) -> bool {
        if (a.length() == b.length()) {
            int a_sum = 0, b_sum = 0;
            for (int i = a.length() - 1; i >= 0; --i) {
                if (a[i] - '0' < 10) {
                    a_sum += a[i] - '0';
                }
                if (b[i] - '0' < 10) {
                    b_sum += b[i] - '0';
                }
            }
            if (a_sum == b_sum) {
                return a < b;
            }

            return a_sum < b_sum;
        }

        return a.length() < b.length();
    });

    for (int i = 0; i < N; ++i) {
        cout << serials[i] << endl;
    }

    return 0;
}