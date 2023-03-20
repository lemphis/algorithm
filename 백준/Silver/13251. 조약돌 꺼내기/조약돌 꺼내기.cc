#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;
    int N;
    cin >> N;
    int color_count[N];
    int total = 0;
    for (int i = 0; i < N; ++i) {
        cin >> color_count[i];
        total += color_count[i];
    }
    int K;
    cin >> K;

    double ans = 0;
    for (int i = 0; i < N; ++i) {
        if (color_count[i] >= K) {
            double temp = 1;
            for (int j = 0; j < K; ++j) {
                temp *= (double)(color_count[i] - j) / (total - j);
            }
            ans += temp;
        }
    }

    cout << fixed;
    cout.precision(10);
    cout << ans;

    return 0;
}