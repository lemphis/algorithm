#include <cstdio>

using namespace std;

#define MAX 10001

/**
 * @see [수 정렬하기 3](https://www.acmicpc.net/problem/10989)
 */
int main() {
    int N;
    scanf("%d", &N);
    int nums[MAX] = {0};
    for (int i = 0; i < N; ++i) {
        int num;
        scanf("%d", &num);
        nums[num]++;
    }
    for (int i = 1; i < MAX; ++i) {
        if (nums[i]) {
            for (int idx = 0; idx < nums[i]; ++idx) {
                printf("%d\n", i);
            }
        }
    }
    return 0;
}