#include <algorithm>
#include <iostream>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

bool alp[26];

void dfs(int N, int K, string items[], int idx, int depth, int& count);
int can_read_count(int N, string items[]);
bool is_required(char target);

int main() {
    fastio;
    int N, K;
    cin >> N >> K;
    string items[N];
    for (char c : {'a', 'n', 't', 'c', 'i'}) {
        alp[c - 'a'] = 1;
    }
    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        items[i] = s.substr(4, s.length() - 8);
    }

    K -= 5;
    int count = 0;
    dfs(N, K, items, 0, 0, count);

    cout << count;

    return 0;
}

void dfs(int N, int K, string items[], int idx, int depth, int& count) {
    if (K == depth) {
        count = max(count, can_read_count(N, items));
        return;
    }
    for (int i = idx; i < 26; ++i) {
        if (!alp[i]) {
            alp[i] = 1;
            dfs(N, K, items, i + 1, depth + 1, count);
            alp[i] = 0;
        }
    }
}

int can_read_count(int N, string items[]) {
    int count = 0;
    for (int i = 0; i < N; ++i) {
        bool can_read = true;
        for (int j = 0; j < items[i].length(); ++j) {
            if (!alp[items[i][j] - 'a']) {
                can_read = false;
                break;
            }
        }
        if (can_read) {
            ++count;
        }
    }
    return count;
}

bool is_required(char target) {
    return target == 'a' || target == 'n' || target == 't' || target == 'c' || target == 'i';
}