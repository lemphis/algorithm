#include <iostream>
#include <map>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

/**
 * @see [듣보잡](https://www.acmicpc.net/problem/1764)
 */
int main() {
    fastio;
    int N, M;
    cin >> N >> M;
    map<string, int> map;
    for (int i = 0; i < N + M; ++i) {
        string name;
        cin >> name;
        map[name]++;
    }

    vector<string> people;
    for (const auto& [key, value] : map) {
        if (value == 2) {
            people.push_back(key);
        }
    }

    cout << people.size() << endl;
    for (int i = 0; i < people.size(); ++i) {
        cout << people[i] << endl;
    }

    return 0;
}