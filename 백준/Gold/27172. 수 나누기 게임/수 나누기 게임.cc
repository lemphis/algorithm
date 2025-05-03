#include <cstring>
#include <iostream>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

const int MAX = 1'000'001;

int main() {
    fastio;

    long N;
    cin >> N;
    int pos[MAX];
    memset(pos, -1, sizeof(pos));
    int cards[100'000] = {0};
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        cards[i] = x;
        pos[x] = i;
    }

    int scores[100'000] = {0};
    for (int i = 0; i < N; ++i) {
        int times = 2;
        while (cards[i] * times < MAX) {
            if (pos[cards[i] * times] > -1) {
                ++scores[i];
                --scores[pos[cards[i] * times]];
            }
            ++times;
        }
    }

    string output;
    output.reserve(N * 4);
    for (int i = 0; i < N; ++i) {
        output += to_string(scores[i]);
        output += ' ';
    }
    cout << output;

    return 0;
}