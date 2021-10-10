#include <algorithm>
#include <cstdio>

using namespace std;

/**
 * @see [숫자 카드](https://www.acmicpc.net/problem/10815)
 */
int main() {
    int N;
    scanf("%d", &N);
    int cards[N];
    for (int i = 0; i < N; ++i) {
        scanf("%d", &cards[i]);
    }
    sort(cards, cards + N);
    int M;
    scanf("%d", &M);
    for (int i = 0; i < M; ++i) {
        int target;
        scanf("%d", &target);
        int start = 0;
        int end = N - 1;
        if (target > cards[end] || target < cards[start]) {
            printf("%d\n", 0);
            continue;
        }
        bool find_target = false;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (target > cards[mid]) {
                start = mid + 1;
            } else if (target < cards[mid]) {
                end = mid - 1;
            } else {
                find_target = true;
                break;
            }
        }
        printf("%d\n", find_target ? 1 : 0);
    }
    return 0;
}