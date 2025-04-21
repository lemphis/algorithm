#include <algorithm>
#include <iostream>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;

    int N;
    cin >> N;
    vector<pair<pair<int, int>, string>> pokemons;
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        string name;
        cin >> name;
        int K, M;
        cin >> K >> M;
        int q = M / K;
        int r = M % K + q * 2;
        while (r >= K) {
            int temp_q = r / K;
            q += temp_q;
            r = r % K + temp_q * 2;
        }
        sum += q;
        pokemons.push_back({{q, i}, name});
    }

    sort(pokemons.begin(), pokemons.end(), [](auto& a, auto& b) -> bool {
        if (a.first.first == b.first.first) {
            return a.first.second < b.first.second;
        }
        return a.first.first > b.first.first;
    });

    cout << sum << endl << pokemons[0].second;

    return 0;
}