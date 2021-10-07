#include <algorithm>
#include <cstdio>
#include <utility>

using namespace std;

/**
 * @see [회의실 배정](https://www.acmicpc.net/problem/1931)
 */
int main() {
    int N;
    scanf("%d", &N);
    pair<int, int> conferences[N];
    for (int i = 0; i < N; ++i) {
        scanf("%d %d", &conferences[i].first, &conferences[i].second);
    }
    sort(conferences, conferences + N, [](auto a, auto b) -> bool { return a.second == b.second ? a.first < b.first : a.second < b.second; });
    int count = 1;
    int end = conferences[0].second;
    for (int i = 1; i < N; ++i) {
        if (conferences[i].first >= end) {
            end = conferences[i].second;
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}