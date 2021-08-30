#include <cmath>
#include <iostream>

#define endl '\n'

typedef long long ll;

using std::cin;
using std::cout;
using std::ios;

bool arr[10000001];

/**
 * @see [거의 소수](https://www.acmicpc.net/problem/1456)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    ll a, b;
    cin >> a >> b;
    int sqrt_b = sqrt(b);
    for (int i = 2; i <= sqrt_b; ++i) arr[i] = 1;
    for (int i = 2; i <= sqrt_b; ++i) {
        for (int times = 2; i * times <= sqrt_b; ++times) {
            if (arr[i * times] == 0)
                continue;
            else
                arr[i * times] = 0;
        }
    }
    int cnt = 0;
    for (int i = 2; i <= sizeof(arr); ++i) {
        if (arr[i] == 0) continue;
        int times = 2;
        while (pow(i, times) <= b) {
            ll pow_num = pow(i, times);
            times++;
            if (pow_num >= a) cnt++;
        }
    }
    cout << cnt << endl;
}