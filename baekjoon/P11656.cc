#include <algorithm>
#include <iostream>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

/**
 * @see [접미사 배열](https://www.acmicpc.net/problem/11656)
 */
int main() {
    fastio;
    string S;
    cin >> S;

    int len = S.length();
    vector<string> suffixes;
    for (int i = 0; i < len; ++i) {
        suffixes.push_back(S.substr(i, len - i));
    }

    sort(suffixes.begin(), suffixes.end());

    for (string item : suffixes) {
        cout << item << endl;
    }

    return 0;
}