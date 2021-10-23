#include <algorithm>
#include <iostream>

using namespace std;

#define endl '\n'

/**
 * @see [뒤집힌 덧셈](https://www.acmicpc.net/problem/1357)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    string X, Y;
    cin >> X >> Y;
    reverse(X.begin(), X.end());
    reverse(Y.begin(), Y.end());
    string result = to_string(stoi(X) + stoi(Y));
    reverse(result.begin(), result.end());
    cout << stoi(result) << endl;
    return 0;
}