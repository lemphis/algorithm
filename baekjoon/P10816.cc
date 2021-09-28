#include <algorithm>
#include <cstdio>
#include <map>

using namespace std;

/**
 * @see [숫자 카드 2](https://www.acmicpc.net/problem/10816)
 */
int main() {
    int N, M;
    scanf("%d", &N);
    int cards[N];
    for (int i = 0; i < N; ++i) {
        scanf("%d", &cards[i]);
    }
    sort(cards, cards + N);
    scanf("%d", &M);
    int targets[M];
    for (int i = 0; i < M; ++i) {
        scanf("%d", &targets[i]);
    }
    map<int, int> map;
    for (int i = 0; i < M; ++i) {
        if (map[targets[i]]) {
            printf("%d ", map[targets[i]]);
            continue;
        }
        int start = 0;
        int end = N - 1;
        bool exists = false;
        int mid;
        while (start <= end) {
            mid = (start + end) / 2;
            if (targets[i] > cards[mid]) {
                start = mid + 1;
            } else if (targets[i] < cards[mid]) {
                end = mid - 1;
            } else {
                exists = true;
                break;
            }
        }
        if (exists) {
            int count = 1;
            int temp = mid - 1;
            while (temp >= 0 && cards[temp] == targets[i]) {
                count++;
                temp--;
            }
            temp = mid + 1;
            while (temp < N && cards[temp] == targets[i]) {
                count++;
                temp++;
            }
            map[targets[i]] = count;
            printf("%d ", count);
        } else {
            printf("%d ", 0);
        }
    }

    return 0;
}