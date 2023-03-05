#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;
    int price;
    cin >> price;
    price = 1000 - price;

    int coin_count = 0;
    int coins[6] = {500, 100, 50, 10, 5, 1};
    for (int i = 0; i < 6; ++i) {
        coin_count += price / coins[i];
        price %= coins[i];
    }

    cout << coin_count;

    return 0;
}