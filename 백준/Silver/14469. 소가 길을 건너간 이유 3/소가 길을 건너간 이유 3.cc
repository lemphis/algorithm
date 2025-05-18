#include <algorithm>
#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;

    int N;
    cin >> N;
    pair<int, int> cows[100];
    for (int i = 0; i < N; ++i) {
        cin >> cows[i].first >> cows[i].second;
    }

    sort(cows, cows + N);

    int second = 0;
    for (int i = 0; i < N; ++i) {
        if (cows[i].first > second) {
            second = cows[i].first + cows[i].second;
        } else {
            second += cows[i].second;
        }
    }

    cout << second;

    return 0;
}