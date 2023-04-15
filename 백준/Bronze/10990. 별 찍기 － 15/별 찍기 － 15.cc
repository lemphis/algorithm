#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;
    int N;
    cin >> N;
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N * 2 - 1; ++c) {
            if (N - 1 - r == c || N - 1 + r == c) {
                cout << '*';
                if (N - 1 + r == c) {
                    break;
                }
            } else {
                cout << ' ';
            }
        }
        cout << endl;
    }

    return 0;
}