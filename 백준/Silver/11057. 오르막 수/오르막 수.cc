#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;
    int N;
    cin >> N;
    int counts[10];
    for (int i = 0; i < 10; ++i) {
        counts[i] = 1;
    }

    for (int i = 2; i <= N; ++i) {
        int total = 0;
        for (int j = 0; j < 10; ++j) {
            total += counts[j];
        }
        for (int j = 0; j < 10; ++j) {
            int temp = counts[j];
            counts[j] = total % 10'007;
            total -= temp;
        }
    }

    int sum = 0;
    for (int i = 0; i < 10; ++i) {
        sum += counts[i];
    }

    cout << sum % 10'007;

    return 0;
}