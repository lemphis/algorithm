#include <algorithm>
#include <iostream>

using namespace std;

#define endl '\n'

/**
 * @see [캠핑](https://www.acmicpc.net/problem/4796)
 */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int count = 0;

    while (1) {
        int L, P, V;
        cin >> L >> P >> V;
        if (!L && !P && !V) {
            break;
        }
        cout << "Case " << ++count << ": " << ((V / P) * L) + min(V % P, L) << endl;
    }

    return 0;
}