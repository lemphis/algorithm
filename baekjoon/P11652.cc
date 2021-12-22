#include <algorithm>
#include <cstring>
#include <iostream>
#include <utility>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

/**
 * @see [카드](https://www.acmicpc.net/problem/11652)
 */
int main() {
    fastio;
    int N;
    cin >> N;
    long long cards[N];
    for (int i = 0; i < N; ++i) {
        cin >> cards[i];
    }

    sort(cards, cards + N);

    int idx = 0;
    pair<long long, int> count[N];
    memset(count, 0, sizeof(count));

    count[0] = {cards[0], 1};
    pair<long long, int> max_pair = count[0];
    for (int i = 1; i < N; ++i) {
        if (cards[i - 1] != cards[i]) {
            count[++idx] = {cards[i], 0};
        }
        count[idx].second++;

        if (max_pair.second < count[idx].second) {
            max_pair = count[idx];
        }
    }

    cout << max_pair.first << endl;

    return 0;
}