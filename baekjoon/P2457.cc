#include <algorithm>
#include <cstdio>
#include <utility>

using namespace std;

/**
 * @see [공주님의 정원](https://www.acmicpc.net/problem/2457)
 */
int main() {
    int N;
    scanf("%d", &N);
    pair<int, int> flowers[N];
    for (int i = 0; i < N; ++i) {
        int begin_m, begin_d, end_m, end_d;
        scanf("%d %d %d %d", &begin_m, &begin_d, &end_m, &end_d);
        flowers[i] = {begin_m * 100 + begin_d, end_m * 100 + end_d};
    }
    sort(flowers, flowers + N);
    int end_date = 301;
    int count = 0;
    int max_date_idx = 0, max_date = 0;
    while (end_date <= 1130) {
        for (int i = max_date_idx; i < N; ++i) {
            if (flowers[i].first > end_date) {
                break;
            }
            if (flowers[i].second > max_date) {
                max_date_idx = i;
                max_date = flowers[i].second;
            }
        }
        if (end_date == max_date) {
            break;
        }
        end_date = max_date;
        count++;
    }
    printf("%d\n", end_date < 1201 ? 0 : count);
    return 0;
}