#include <iostream>
#include <algorithm>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;
    int n;
    cin >> n;
    int ai[n];
    for (int i = 0; i < n; ++i)
        cin >> ai[i];
    
    sort(ai, ai + n);

    int k = ai[0];
    for (int i = 1; i < n; ++i) {
        if (k * (i + 1) > ai[i]) {
            k = ai[i] / (i + 1);
        }
    }

    cout << k << endl;

    return 0;
}