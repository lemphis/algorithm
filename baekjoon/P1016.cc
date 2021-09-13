#include <cmath>
#include <iostream>
#include <set>

#define endl '\n'
#define MAX 1000001
#define ll long long

using std::cin;
using std::cout;
using std::ios;
using std::set;

/**
 * @see [제곱 ㄴㄴ 수](https://www.acmicpc.net/problem/1016)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    bool primes[MAX] = {0};
    for (ll i = 2; i < MAX; ++i) {
        ll times = 2;
        while (i * times < MAX) {
            primes[i * times++] = 1;
        }
    }
    set<ll> square_primes;
    for (ll i = 2; i < MAX; ++i) {
        if (primes[i] == 0) {
            square_primes.insert(i * i);
        }
    }
    int size = square_primes.size();
    ll min, max;
    cin >> min >> max;
    set<ll> result;
    for (auto iter = square_primes.begin(); iter != square_primes.end(); ++iter) {
        ll times = min / *iter;
        if (min % *iter != 0) times++;
        while (*iter * times <= max) {
            result.insert(*iter * times);
            times++;
        }
    }
    ll result_size = result.size();
    cout << max - (min - 1) - result_size << endl;
}