#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

const int MAX = 1'000'001;

/**
 * @see [골드바흐의 추측](https://www.acmicpc.net/problem/6588)
 */
int main() {
    fastio;
    bool no_prime[MAX] = {0};
    for (int i = 2; i * i < MAX; ++i) {
        if (!no_prime[i]) {
            int times = 2;
            while (i * times < MAX) {
                no_prime[i * times++] = 1;
            }
        }
    }

    while (1) {
        int n;
        cin >> n;
        if (n == 0) break;

        int left = 3, right = n - 3;
        while (left <= right) {
            if (!no_prime[left] && !no_prime[right])
                if (left + right == n)
                    break;
            left += 2;
            right -= 2;
        }

        if (left == 0)
            cout << "Goldbach's conjecture is wrong" << endl;
        else
            cout << n << " = " << left << " + " << right << endl;
    }

    return 0;
}