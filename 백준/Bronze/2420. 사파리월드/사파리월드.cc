#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;
    long N, M;
    cin >> N >> M;
    cout << abs(N - M);
    return 0;
}