#include <cmath>
#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;
    int N, M;
    cin >> N >> M;
    int nums[N][M];
    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); ++j) {
            nums[i][j] = s[j] - '0';
        }
    }

    int ans = 1;
    for (int r = 0; r < N - 1; ++r) {
        for (int c = 0; c < M - 1; ++c) {
            int limit = min(N - r, M - c);
            for (int i = 1; i < limit; ++i) {
                if (nums[r][c] == nums[r + i][c] && nums[r][c] == nums[r][c + i] && nums[r][c] == nums[r + i][c + i]) {
                    ans = max(ans, (i + 1) * (i + 1));
                }
            }
        }
    }

    cout << ans;

    return 0;
}
