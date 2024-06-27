#include <cmath>
#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;
    int N;
    cin >> N;
    long distance[N - 1];
    for (int i = 0; i < N - 1; ++i) {
        cin >> distance[i];
    }
    long prices[N];
    for (int i = 0; i < N; ++i) {
        cin >> prices[i];
    }
    long min_price = prices[0];
    for (int i = 1; i < N; ++i) {
        min_price = min(min_price, prices[i]);
        prices[i] = min_price;
    }

    long sum = 0;
    for (int i = 0; i < N - 1; ++i) {
        sum += distance[i] * prices[i];
    }

    cout << sum;

    return 0;
}