#include <algorithm>
#include <iostream>
#include <map>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;
    int N, d, k, c;
    cin >> N >> d >> k >> c;
    int sushi[N + k];
    map<int, int> map;
    for (int i = 0; i < N; ++i) {
        cin >> sushi[i];
        if (i < k) {
            ++map[sushi[i]];
        }
    }
    for (int i = 0; i < k; ++i) {
        sushi[N + i] = sushi[i];
    }

    int max_count = map.size();
    int left = 0;
    int right = k - 1;
    while (right < N + k) {
        int count = map.size();
        if (map.find(c) == map.end()) {
            ++count;
        }
        max_count = max(max_count, count);
        --map[sushi[left]];
        if (map[sushi[left]] == 0) {
            map.erase(sushi[left]);
        }
        ++left;
        ++right;
        ++map[sushi[right]];
    }

    cout << max_count;

    return 0;
}