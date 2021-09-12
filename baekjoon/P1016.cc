#include <cmath>
#include <iostream>
#include <set>

#define endl '\n'
#define MAX 1000001

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
    for (long long i = 2; i <= MAX; ++i) {
        long long times = 2;
        while (i * times <= MAX) {
            primes[i * times++] = 1;
        }
    }
    long long min, max;
    cin >> min >> max;
    long long sqrt_max = sqrt(max);
    set<long long> result;
    for (long long i = 2; i <= sqrt_max; ++i) {
        if (primes[i] == 0) {
            long long times = min / i * i;
            if (times == 0) times = 1;
            while (i * i * times <= max) {
                result.insert(i * i * times);
                times++;
            }
        }
    }
    cout << (max - (min - 1) - result.size()) << endl;
}