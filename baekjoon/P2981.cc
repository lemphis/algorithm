#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

int gcd(int a, int b);

/**
 * @see [검문](https://www.acmicpc.net/problem/2981)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N;
    cin >> N;
    int nums[N];
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }
    sort(nums, nums + N);

    int _gcd = nums[1] - nums[0];
    for (int i = 0; i < N - 1; ++i) {
        _gcd = gcd(nums[i + 1] - nums[i], _gcd);
    }

    vector<int> divisors;
    for (int i = 2; i * i <= _gcd; ++i) {
        if (_gcd % i == 0) {
            divisors.push_back(i);
            if (i != _gcd / i) {
                divisors.push_back(_gcd / i);
            }
        }
    }
    divisors.push_back(_gcd);
    sort(divisors.begin(), divisors.end());
    for (auto i = 0; i < divisors.size(); ++i) {
        cout << divisors[i] << ' ';
    }

    return 0;
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}