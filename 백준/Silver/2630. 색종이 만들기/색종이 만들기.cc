#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define MAX 128

using namespace std;

bool paper[MAX][MAX];

void dfs(int start_r, int start_c, int& white, int& blue, int N);
inline bool check(int start_r, int start_c, int N);

int main() {
    fastio;
    int N;
    cin >> N;
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            cin >> paper[r][c];
        }
    }

    int white = 0, blue = 0;
    dfs(0, 0, white, blue, N);

    cout << white << endl
         << blue << endl;

    return 0;
}

void dfs(int start_r, int start_c, int& white, int& blue, int N) {
    if (check(start_r, start_c, N)) {
        paper[start_r][start_c] ? blue++ : white++;
        return;
    }

    dfs(start_r, start_c, white, blue, N / 2);
    dfs(start_r, start_c + N / 2, white, blue, N / 2);
    dfs(start_r + N / 2, start_c, white, blue, N / 2);
    dfs(start_r + N / 2, start_c + N / 2, white, blue, N / 2);
}

inline bool check(int start_r, int start_c, int N) {
    bool base = paper[start_r][start_c];
    for (int r = start_r; r < start_r + N; ++r) {
        for (int c = start_c; c < start_c + N; ++c) {
            if (paper[r][c] != base) {
                return false;
            }
        }
    }

    return true;
}