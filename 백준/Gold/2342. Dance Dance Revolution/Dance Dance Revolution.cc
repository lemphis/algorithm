#include <algorithm>
#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int dp[100'000][5][5];

int move_cost(int from, int to);

const int MAX = 1e9;

int main() {
    fastio;

    int commands[100'001];
    int size = 0;
    while (true) {
        cin >> commands[size];
        if (commands[size] == 0) {
            break;
        }
        ++size;
    }

    for (auto& i : dp) {
        for (auto& j : i) {
            for (int& k : j) {
                k = MAX;
            }
        }
    }

    dp[0][commands[0]][0] = 2;
    dp[0][0][commands[0]] = 2;
    for (int i = 1; i < size; ++i) {
        int command = commands[i];
        for (int l = 0; l < 5; ++l) {
            for (int r = 0; r < 5; ++r) {
                dp[i][command][r] = min(
                    dp[i][command][r], dp[i - 1][l][r] + move_cost(l, command));

                dp[i][l][command] = min(
                    dp[i][l][command], dp[i - 1][l][r] + move_cost(r, command));
            }
        }
    }

    int min_count = MAX;
    for (int i = 0; i < 5; ++i) {
        min_count = min({min_count, dp[size - 1][commands[size - 1]][i],
                         dp[size - 1][i][commands[size - 1]]});
    }

    cout << min_count;

    return 0;
}

int move_cost(int from, int to) {
    if (from == to) {
        return 1;
    } else if (from == 0) {
        return 2;
    } else if (abs(from - to) == 2) {
        return 4;
    } else {
        return 3;
    }
}