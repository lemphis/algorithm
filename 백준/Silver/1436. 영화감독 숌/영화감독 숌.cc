#include <iostream>
#include <string>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

/**
 * @see [영화감독 숌](https://www.acmicpc.net/problem/1436)
 */
int main() {
    fastio;
    int N;
    cin >> N;
    int count = 0, ans;
    for (int i = 666;; ++i) {
        string s = to_string(i);
        if (s.find("666") != string::npos) {
            count++;
        }
        if (count == N) {
            ans = i;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}