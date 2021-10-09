#include <cstdio>

using namespace std;

/**
 * @see [청기 백기](https://www.acmicpc.net/problem/15736)
 */
int main() {
    long long N;
    scanf("%lld", &N);
    long long square = 1;
    int count = 0;
    while (square * square <= N) {
        square++;
        count++;
    }
    printf("%d\n", count);
    return 0;
}