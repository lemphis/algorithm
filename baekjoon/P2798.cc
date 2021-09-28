#include <cstdio>

using namespace std;

/**
 * @see [블랙잭](https://www.acmicpc.net/problem/2798)
 */
int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    int cards[N];
    for (int i = 0; i < N; ++i) {
        scanf("%d", &cards[i]);
    }
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            for (int k = j + 1; k < N; ++k) {
                int three_cards_sum = cards[i] + cards[j] + cards[k];
                if (three_cards_sum > sum && three_cards_sum <= M) {
                    sum = three_cards_sum;
                }
            }
        }
    }
    printf("%d", sum);
    return 0;
}