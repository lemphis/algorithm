#include <algorithm>
#include <iostream>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<int> a(N);
        for (int i = 0; i < N; ++i) {
            cin >> a[i];
        }
        vector<int> b(M);
        for (int i = 0; i < M; ++i) {
            cin >> b[i];
        }

        sort(a.begin(), a.end(), greater<int>());
        sort(b.begin(), b.end());

        int count = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (a[i] <= b[j]) {
                    break;
                }
                ++count;
            }
        }

        cout << count << endl;
    }

    return 0;
}
