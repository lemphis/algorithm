#include <iostream>
#include <set>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

/**
 * @see [서로 다른 부분 문자열의 개수](https://www.acmicpc.net/problem/11478)
 */
int main() {
    fastio;
    string S;
    cin >> S;
    set<string> set;
    int size = S.size();
    for (int i = 0; i < size; ++i) {
        for (int j = 1; j < size - i + 1; ++j) {
            set.insert(S.substr(i, j));
        }
    }

    cout << set.size() << endl;

    return 0;
}