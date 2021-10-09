#include <algorithm>
#include <cstdio>

using namespace std;

/**
 * @see [적어도 대부분의 배수](https://www.acmicpc.net/problem/1145)
 */
int main() {
    int nums[5];
    int num = 0x7fffffff;
    for (int i = 0; i < 5; ++i) {
        scanf("%d", &nums[i]);
        num = min(num, nums[i]);
    }
    int count = 0;
    while (1) {
        for (int i = 0; i < 5; ++i) {
            if (num % nums[i] == 0) {
                count++;
            }
        }
        if (count >= 3) {
            break;
        } else {
            count = 0;
        }
        num++;
    }
    printf("%d\n", num);
    return 0;
}