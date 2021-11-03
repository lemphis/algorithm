#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

int _find(int x, int parents[]);
void _union(int x, int y, int parents[]);

/**
 * @see [거짓말](https://www.acmicpc.net/problem/1043)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    int parents[N + 1];
    for (int i = 0; i <= N; ++i) {
        parents[i] = i;
    }

    int true_count;
    cin >> true_count;
    for (int i = 0; i < true_count; ++i) {
        int true_person_num;
        cin >> true_person_num;
        _union(0, true_person_num, parents);
    }

    vector<vector<int>> parties;
    for (int i = 0; i < M; ++i) {
        int party_people_count;
        cin >> party_people_count;
        vector<int> party;
        for (int idx = 0; idx < party_people_count; ++idx) {
            int person_num;
            cin >> person_num;
            party.push_back(person_num);
            if (idx > 0) {
                _union(party[0], party[idx], parents);
            }
        }
        parties.push_back(party);
    }

    int max_count = 0;
    for (int i = 0; i < M; ++i) {
        if (_find(parties[i][0], parents) != _find(0, parents)) {
            max_count++;
        }
    }

    cout << max_count << endl;

    return 0;
}

int _find(int x, int parents[]) {
    return x == parents[x] ? x : parents[x] = _find(parents[x], parents);
}

void _union(int x, int y, int parents[]) {
    x > y ? parents[_find(x, parents)] = _find(y, parents) : parents[_find(y, parents)] = _find(x, parents);
}