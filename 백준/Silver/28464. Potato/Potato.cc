#include <algorithm>
#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;

    int N;
    cin >> N;
    int a[200'000];
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    sort(a, a + N);
    int low = 0;
    for (int i = 0; i < N / 2; ++i) {
        low += a[i];
    }

    cout << low << ' ' << sum - low;

    return 0;
}