#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'
#define MAX 4'000'001

/**
 * @see [소수의 연속합](https://www.acmicpc.net/problem/1644)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N;
    cin >> N;

    vector<int> primes;
    bool is_prime[MAX] = {false};
    for (int i = 2; i < MAX; ++i) {
        if (!is_prime[i]) {
            primes.push_back(i);
            int times = 2;
            while (i * times < MAX) {
                is_prime[i * times++] = true;
            }
        }
    }

    int i = 0, j = 0;
    int sum = primes[0];
    int size = primes.size();
    int count = 0;
    while (i <= j && j < size) {
        if (sum > N) {
            sum -= primes[i++];
        } else if (sum < N) {
            sum += primes[++j];
        } else {
            count++;
            sum -= primes[i++];
            sum += primes[++j];
        }
    }

    cout << count << endl;

    return 0;
}