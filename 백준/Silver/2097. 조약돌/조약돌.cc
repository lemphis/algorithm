#include <cmath>
#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;
    int N;
    cin >> N;
    if (N == 1 || N == 2)
        cout << 4;
    else {
        int root = round(sqrt(N));
        if (root * root >= N)
            cout << (root - 1) * 4;
        else
            cout << ((root - 1) * 2) + ((root) * 2);
    }

    return 0;
}