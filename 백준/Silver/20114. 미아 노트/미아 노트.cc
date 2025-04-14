#include <iostream>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;

    int N, H, W;
    cin >> N >> H >> W;
    vector<char> origin(N, '?');
    for (int r = 0; r < H; ++r) {
        string s;
        cin >> s;
        for (int c = 0; c < N * W; ++c) {
            if (s[c] != '?') {
                origin[c / W] = s[c];
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << origin[i];
    }

    return 0;
}