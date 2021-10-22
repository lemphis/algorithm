#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define endl '\n'
#define MAX 1'004'001

/**
 * @see [소수&팰린드롬](https://www.acmicpc.net/problem/1747)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N;
    cin >> N;

    bool check_prime[MAX] = {0};
    vector<int> primes;
    for (int i = 2; i < MAX; ++i) {
        if (!check_prime[i]) {
            primes.push_back(i);
            int times = 2;
            while (i * times < MAX) {
                check_prime[i * times++] = 1;
            }
        }
    }

    int first_idx = find_if(primes.begin(), primes.end(), [N](int prime) -> bool { return N <= prime; }) - primes.begin();
    for (auto i = primes.begin() + first_idx; i < primes.end(); ++i) {
        string num_str = to_string(*i);
        int len = num_str.length();
        bool is_palindrome = true;
        for (int idx = 0; idx < len / 2; ++idx) {
            if (num_str[idx] != num_str[(len - 1) - idx]) {
                is_palindrome = false;
                break;
            }
        }
        if (is_palindrome) {
            cout << *i << endl;
            return 0;
        }
    }

    return 0;
}