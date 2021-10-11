#include <vector>

/**
 * @see [정수 N개의 합](https://www.acmicpc.net/problem/15596)
 */
long long sum(std::vector<int> &a) {
    long long result = 0;
    for (int i = 0; i < a.size(); ++i) {
        result += a[i];
    }
    return result;
}