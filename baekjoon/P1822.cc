#include <algorithm>
#include <cstdio>
#include <iterator>
#include <vector>

using namespace std;

/**
 * @see [숫자 카드](https://www.acmicpc.net/problem/10815)
 */
int main() {
    int a_count, b_count;
    scanf("%d %d", &a_count, &b_count);
    int a_set[a_count], b_set[b_count];
    for (int i = 0; i < a_count; ++i) {
        scanf("%d", &a_set[i]);
    }
    for (int i = 0; i < b_count; ++i) {
        scanf("%d", &b_set[i]);
    }
    sort(a_set, a_set + a_count);
    sort(b_set, b_set + b_count);
    vector<int> diff;
    set_difference(a_set, a_set + a_count, b_set, b_set + b_count, back_inserter(diff));
    printf("%zu\n", diff.size());
    for (int i = 0; i < diff.size(); ++i) {
        printf("%d ", diff[i]);
    }
    return 0;
}