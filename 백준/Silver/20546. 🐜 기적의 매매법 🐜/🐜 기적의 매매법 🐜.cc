#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;
    int cash;
    cin >> cash;
    int junhyun_cash = cash;
    int sungmin_cash = cash;
    int junhyun_stock_count = 0;
    int sungmin_stock_count = 0;
    int before_price = 0;
    int up_count = 0;
    int down_count = 0;
    for (int i = 0; i < 14; ++i) {
        int price;
        cin >> price;
        if (junhyun_cash / price > 0) {
            junhyun_stock_count += junhyun_cash / price;
            junhyun_cash %= price;
        }
        if (before_price > 0) {
            if (price > before_price) {
                down_count = 0;
                ++up_count;
            }
            if (price < before_price) {
                up_count = 0;
                ++down_count;
            }
        }
        if (up_count == 3) {
            sungmin_cash += sungmin_stock_count * price;
            sungmin_stock_count = 0;
        }
        if (down_count == 3) {
            sungmin_stock_count += sungmin_cash / price;
            sungmin_cash %= price;
        }
        before_price = price;
    }

    int junhyun_total = junhyun_cash + junhyun_stock_count * before_price;
    int sungmin_total = sungmin_cash + sungmin_stock_count * before_price;

    if (junhyun_total == sungmin_total) {
        cout << "SAMESAME";
    } else if (junhyun_total > sungmin_total) {
        cout << "BNP";
    } else {
        cout << "TIMING";
    }

    return 0;
}