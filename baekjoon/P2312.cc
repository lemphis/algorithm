#include <cstdio>

using namespace std;

#define MAX 100001

/**
 * @see [수 복원하기](https://www.acmicpc.net/problem/2312)
 */
int main() {
    int tc;
    scanf("%d", &tc);

    bool check_prime[MAX] = {0};
    for (int i = 2; i < MAX; ++i) {
        if (!check_prime[i]) {
            for (int j = i * 2; j < MAX; j += i) {
                check_prime[j] = 1;
            }
        }
    }

    while (tc--) {
        int N;
        scanf("%d", &N);
        int arr[MAX] = {0};
        int prime_num = 2;
        while (N != 1) {
            while (N % prime_num == 0) {
                N /= prime_num;
                arr[prime_num]++;
            }
            prime_num++;
        }
        for (int i = 2; i <= prime_num; ++i) {
            if (arr[i]) {
                printf("%d %d\n", i, arr[i]);
            }
        }
    }

    return 0;
}