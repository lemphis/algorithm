#include <algorithm>
#include <iostream>
#include <vector>

#define endl '\n'

using std::cin;
using std::cout;
using std::ios;
using std::vector;

/**
 * @see [에라토스테네스의 체](https://www.acmicpc.net/problem/2960)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n, k;
    vector<int> v;
    cin >> n >> k;
    for (int i = 2; i <= n; ++i) {
        int times = 1;
        while (i * times <= n) {
            if (find(v.begin(), v.end(), i * times) == v.end()) {
                v.push_back(i * times);
            }
            times++;
        }
    }
    cout << v[k - 1] << endl;
}