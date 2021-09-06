#include <algorithm>
#include <iostream>
#include <vector>

#define endl '\n'

using std::cin;
using std::cout;
using std::ios;
using std::sort;
using std::vector;

/**
 * @see [감소하는 수](https://www.acmicpc.net/problem/1038)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    vector<long long> v;
    for (int i = 1; i <= 1023; ++i) {
        long long num = 0;
        int tmp_i = i;
        for (int idx = 9; idx >= 0; --idx) {
            if (tmp_i == 0)
                break;
            else if (tmp_i % 2 == 1)
                num = num * 10 + idx;
            tmp_i /= 2;
        }
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    int N;
    cin >> N;
    cout << (N > 1022 ? -1 : v[N]) << endl;
}