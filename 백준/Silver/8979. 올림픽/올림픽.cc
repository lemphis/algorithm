#include <algorithm>
#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

struct Nation {
    int id;
    int rank;
    int gold;
    int silver;
    int bronze;
};

int main() {
    fastio;

    int N, K;
    cin >> N >> K;
    vector<Nation> nations(N);
    for (int i = 0; i < N; ++i) {
        cin >> nations[i].id >> nations[i].gold >> nations[i].silver >>
            nations[i].bronze;
    }

    sort(nations.begin(), nations.end(), [](Nation& a, Nation& b) -> bool {
        if (a.gold == b.gold) {
            if (a.silver == b.silver) {
                return a.bronze > b.bronze;
            } else {
                return a.silver > b.silver;
            }
        } else {
            return a.gold > b.gold;
        }
    });

    int rank = 1;
    for (int i = 0; i < N; ++i) {
        nations[i].rank = rank;
        while (i < N - 1 && nations[i + 1].gold == nations[i].gold &&
               nations[i + 1].silver == nations[i].silver &&
               nations[i + 1].bronze == nations[i].bronze) {
            nations[i + 1].rank = rank;
            ++i;
        }
        rank = i + 2;
    }

    int ans = 0;
    for (auto& nation : nations) {
        if (nation.id == K) {
            ans = nation.rank;
            break;
        }
    }

    cout << ans;

    return 0;
}