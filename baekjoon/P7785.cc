#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

/**
 * @see [회사에 있는 사람](https://www.acmicpc.net/problem/7785)
 */
int main() {
    fastio;
    int n;
    cin >> n;
    unordered_map<string, bool> map;
    for (int i = 0; i < n; ++i) {
        string name, log;
        cin >> name >> log;
        map[name] = log == "enter" ? true : false;
    }

    vector<string> people;
    for (auto& [name, log] : map) {
        if (log) {
            people.push_back(name);
        }
    }

    sort(people.begin(), people.end(), greater<>());
    for (string name : people) {
        cout << name << endl;
    }

    return 0;
}