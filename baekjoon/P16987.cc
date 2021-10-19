#include <cstdio>

using namespace std;

typedef struct {
    int durability;
    int weight;
} Egg;

void break_egg(int N, int depth, Egg eggs[], int& count);

/**
 * @see [계란으로 계란치기](https://www.acmicpc.net/problem/16987)
 */
int main() {
    int N;
    scanf("%d", &N);
    Egg eggs[N];
    for (int i = 0; i < N; ++i) {
        scanf("%d %d", &eggs[i].durability, &eggs[i].weight);
    }
    int count = 0;
    break_egg(N, 0, eggs, count);
    printf("%d\n", count);
    return 0;
}

void break_egg(int N, int depth, Egg eggs[], int& count) {
    if (depth == N) {
        int temp_count = 0;
        for (int i = 0; i < N; ++i) {
            if (eggs[i].durability <= 0) {
                temp_count++;
            }
        }
        if (count < temp_count) {
            count = temp_count;
        }
        return;
    }

    if (eggs[depth].durability <= 0) {
        break_egg(N, depth + 1, eggs, count);
    } else {
        bool breaks = false;
        for (int i = 0; i < N; ++i) {
            if (depth == i || eggs[i].durability <= 0) continue;
            eggs[depth].durability -= eggs[i].weight;
            eggs[i].durability -= eggs[depth].weight;
            breaks = true;
            break_egg(N, depth + 1, eggs, count);
            eggs[depth].durability += eggs[i].weight;
            eggs[i].durability += eggs[depth].weight;
        }
        if (!breaks) {
            break_egg(N, N, eggs, count);
        }
    }
}