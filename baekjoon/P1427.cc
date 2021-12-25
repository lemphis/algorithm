#include <algorithm>
#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

/**
 * @see [소트인사이드](https://www.acmicpc.net/problem/1427)
 */
int main() {
    fastio;
    string N;
    cin >> N;

    sort(N.begin(), N.end(), [](char& a, char& b) -> bool {
        return a > b;
    });

    cout << N << endl;

    return 0;
}