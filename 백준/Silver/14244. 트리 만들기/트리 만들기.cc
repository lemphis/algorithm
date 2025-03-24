#include <iostream>
#include <sstream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;
    int n, m;
    cin >> n >> m;

    ostringstream output;

    int k = n - (m - 2);
    for (int i = 0; i < k - 1; ++i) {
        output << i << ' ' << i + 1 << endl;
    }

    for (int i = k; i < n; ++i) {
        output << 1 << ' ' << i << endl;
    }

    cout << output.str();

    return 0;
}