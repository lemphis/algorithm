#include <iostream>
#include <unordered_map>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

/**
 * @see [나는야 포켓몬 마스터 이다솜](https://www.acmicpc.net/problem/1620)
 */
int main() {
    fastio;
    int N, M;
    cin >> N >> M;
    unordered_map<string, int> map;
    string keys[N];
    for (int i = 0; i < N; ++i) {
        cin >> keys[i];
        map[keys[i]] = i + 1;
    }

    while (M--) {
        string query;
        cin >> query;
        if ('0' < query[0] && query[0] <= '9') {
            cout << keys[stoi(query) - 1] << endl;
        } else {
            cout << map[query] << endl;
        }
    }

    return 0;
}