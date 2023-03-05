#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;
    string X, Y;
    cin >> X >> Y;

    int chars_diff = 0xffffffff >> 1;
    int temp = 0;
    int loop_count = Y.length() - X.length() + 1;
    for (int i = 0; i < loop_count; ++i) {
        for (int idx = 0; idx < X.length(); ++idx) {
            if (X[idx] != Y[idx + i]) {
                temp++;
            }
        }
        if (temp < chars_diff) {
            chars_diff = temp;
        }
        temp = 0;
    }

    cout << chars_diff;

    return 0;
}