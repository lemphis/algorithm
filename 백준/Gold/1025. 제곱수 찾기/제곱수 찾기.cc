#include <cmath>
#include <iostream>
#include <string>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    int arr[9][9];
    for (int i = 0; i < n; ++i) {
        string row;
        cin >> row;
        for (int j = 0; j < m; ++j) {
            arr[i][j] = row[j] - '0';
        }
    }

    int ans = -1;
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            for (int dr = -n; dr < n; ++dr) {
                for (int dc = -m; dc < m; ++dc) {
                    if (dr == 0 && dc == 0) {
                        continue;
                    }
                    string sum_str;
                    int now_r = r;
                    int now_c = c;
                    while (now_r >= 0 && now_r < n && now_c >= 0 && now_c < m) {
                        sum_str += (arr[now_r][now_c] + '0');
                        int sum = stoi(sum_str);
                        if ((int)sqrt(sum) * (int)sqrt(sum) == sum && ans < sum) {
                            ans = sum;
                        }
                        now_r += dr;
                        now_c += dc;
                    }
                }
            }
        }
    }

    cout << ans;

    return 0;
}