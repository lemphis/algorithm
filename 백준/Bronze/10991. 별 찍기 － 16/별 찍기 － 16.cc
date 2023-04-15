#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;
    int N;
    cin >> N;
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N - 1 - r; ++c) {
            cout << ' ';
        }
        for (int c = 0; c < (r + 1) * 2 - 1; ++c) {
            cout << (c & 1 ? ' ' : '*');
        }
        cout << endl;
    }

    return 0;
}