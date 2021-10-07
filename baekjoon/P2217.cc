#include <algorithm>
#include <cstdio>

using namespace std;

/**
 * @see [로프](https://www.acmicpc.net/problem/2217)
 */
int main() {
    int N;
    scanf("%d", &N);
    int ropes[N];
    for (int i = 0; i < N; ++i) {
        scanf("%d", &ropes[i]);
    }
    sort(ropes, ropes + N, [](int a, int b) -> bool { return a > b; });
    int min_rope = ropes[0];
    int max_weight = 0;
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        min_rope = min(min_rope, ropes[i]);
        max_weight = max(min_rope * (i + 1), max_weight);
    }
    printf("%d\n", max_weight);
    return 0;
}