#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

struct Pos {
    int r;
    int c;
};

int main() {
    fastio;
    int N, M;
    cin >> N >> M;
    vector<Pos> chickens;
    vector<Pos> houses;
    for (int r = 1; r <= N; ++r) {
        for (int c = 1; c <= N; ++c) {
            int num;
            cin >> num;
            if (num == 1) {
                houses.push_back(Pos{r, c});
            }
            if (num == 2) {
                chickens.push_back(Pos{r, c});
            }
        }
    }
    int chicken_len = chickens.size();
    vector<bool> combination(chicken_len, false);
    fill(combination.end() - M, combination.end(), true);
    int ans = 0xffffffff >> 1;
    do {
        int min_sum = 0;
        for (int i = 0; i < houses.size(); ++i) {
            int min_distance = 0xffffffff >> 1;
            for (int j = 0; j < chicken_len; ++j) {
                if (combination[j]) {
                    int distance = abs(chickens[j].r - houses[i].r) +
                                   abs(chickens[j].c - houses[i].c);
                    min_distance = min(min_distance, distance);
                }
            }
            min_sum += min_distance;
        }
        ans = min(ans, min_sum);
    } while (next_permutation(combination.begin(), combination.end()));

    cout << ans;

    return 0;
}
