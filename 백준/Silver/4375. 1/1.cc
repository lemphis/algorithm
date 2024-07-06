#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;
    int N;
    while (cin >> N) {
        int count = 1;
        int ans = 1;
        while (ans % N != 0) {
            ans = (ans * 10 + 1) % N;
            ++count;
        }
        cout << count << endl;
    }

    return 0;
}