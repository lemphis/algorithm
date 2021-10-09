#include <cstdio>

using namespace std;

/**
 * @see [약수 구하기](https://www.acmicpc.net/problem/2501)
 */
int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    int count = 0;
    int divisor;
    for (int i = 1; i <= N; ++i) {
        if (N % i == 0) {
            count++;
        }
        if (count == K) {
            divisor = i;
            break;
        }
    }
    printf("%d\n", count < K ? 0 : divisor);
    return 0;
}