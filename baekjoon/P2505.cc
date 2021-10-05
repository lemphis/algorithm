#include <algorithm>
#include <cstdio>

using namespace std;

void find_front(int cards[], int cards_size, int front[], int back[], int& times);
void find_back(int cards[], int cards_size, int front[], int back[], int& times);
void print(int times, int front[], int back[]);

/**
 * @see [두 번 뒤집기](https://www.acmicpc.net/problem/2505)
 */
int main() {
    int N;
    scanf("%d", &N);
    int cards[N + 1], temp[N + 1];
    for (int i = 1; i <= N; ++i) {
        int card;
        scanf("%d", &card);
        cards[i] = temp[i] = card;
    }
    int times = 0;
    int front[2], back[2];
    for (int i = 0; i < 2; ++i) {
        find_front(temp, N, front, back, times);
    }
    if (!is_sorted(temp + 1, temp + N + 1)) {
        times = 0;
        for (int i = 0; i < 2; ++i) {
            front[i] = back[i] = 0;
            find_back(cards, N, front, back, times);
        }
    }
    print(times, front, back);
    return 0;
}

void find_front(int cards[], int cards_size, int front[], int back[], int& times) {
    if (is_sorted(cards + 1, cards + cards_size + 1)) {
        return;
    }
    int temp = times;
    int idx = 1;
    find_if(cards + 1, cards + cards_size + 1, [front, temp, &idx](int i) -> bool {
        if (idx != i) {
            front[temp] = idx;
            return true;
        } else {
            idx++;
            return false;
        }
    });
    int second_idx = idx + 1;
    find_if(cards + 1 + idx, cards + cards_size + 1, [back, temp, idx, &second_idx](int i) -> bool {
        if (i == idx) {
            back[temp] = second_idx;
            return true;
        } else {
            second_idx++;
            return false;
        }
    });
    reverse(cards + front[temp], cards + back[temp] + 1);
    times++;
}

void find_back(int cards[], int cards_size, int front[], int back[], int& times) {
    if (is_sorted(cards + 1, cards + cards_size + 1)) {
        return;
    }
    int temp = times;
    for (int i = cards_size; i > 0; --i) {
        if (cards[i] != i) {
            back[temp] = i;
            break;
        }
    }
    for (int i = cards_size - (cards_size - back[temp]); i > 0; --i) {
        if (cards[i] == back[temp]) {
            front[temp] = i;
            break;
        }
    }
    reverse(cards + front[temp], cards + back[temp] + 1);
    times++;
}

void print(int times, int front[], int back[]) {
    if (times == 0) {
        printf("1 1\n");
        printf("1 1\n");
    } else if (times == 1) {
        printf("%d %d\n", front[0], back[0]);
        printf("1 1\n");
    } else {
        printf("%d %d\n", front[0], back[0]);
        printf("%d %d\n", front[1], back[1]);
    }
}