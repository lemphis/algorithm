#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

using pii = pair<int, int>;

int main() {
    fastio;

    pii yumi;
    cin >> yumi.first >> yumi.second;
    vector<pii> persons(3);
    for (auto& person : persons) {
        cin >> person.first >> person.second;
    }

    sort(persons.begin(), persons.end());

    int min_dist = 1e9;
    do {
        double dist = 0;
        pii cur = yumi;
        for (auto& p : persons) {
            dist += hypot((cur.first - p.first), (cur.second - p.second));
            cur = p;
        }

        if (min_dist > dist) {
            min_dist = dist;
        }
    } while (next_permutation(persons.begin(), persons.end()));

    cout << min_dist;

    return 0;
}