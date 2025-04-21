#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;

    int N, M;
    cin >> N >> M;
    vector<vector<int>> cards(N, vector<int>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> cards[i][j];
        }
        sort(cards[i].begin(), cards[i].end(), greater<int>());
    }

    vector<int> scores(N);
    int max_score = 0;
    for (int i = 0; i < M; ++i) {
        vector<int> winners;
        winners.push_back(0);
        int win_card = cards[0][i];
        for (int j = 1; j < N; ++j) {
            if (win_card < cards[j][i]) {
                winners.clear();
                winners.push_back(j);
                win_card = cards[j][i];
            } else if (win_card == cards[j][i]) {
                winners.push_back(j);
            }
        }
        for (int winner : winners) {
            ++scores[winner];
            max_score = max(max_score, scores[winner]);
        }
    }

    for (int i = 0; i < N; ++i) {
        if (scores[i] == max_score) {
            cout << i + 1 << ' ';
        }
    }

    return 0;
}