#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

/**
 * @see [등수 매기기](https://www.acmicpc.net/problem/2012)
 */
int main() {
    int N;
    scanf("%d", &N);
    int scores[N];
    for (int i = 0; i < N; ++i) {
        scanf("%d", &scores[i]);
    }
    sort(scores, scores + N);
    long long count = 0;
    for (int i = 0; i < N; ++i) {
        count += (long long)abs((i + 1) - scores[i]);
    }
    printf("%lld\n", count);
    return 0;
}