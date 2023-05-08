#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

/**
 * @see [멀티탭 스케줄링](https://www.acmicpc.net/problem/1700)
 */
int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    int items[K];
    for (int i = 0; i < K; ++i) {
        scanf("%d", &items[i]);
    }
    int sphere[N];
    int count = 0;
    int idx = 0;
    int sphere_idx = 0;
    while (idx < K && sphere_idx < N) {
        bool exists = false;
        for (int i = 0; i < sphere_idx; ++i) {
            if (items[idx] == sphere[i]) {
                exists = true;
                break;
            }
        }
        if (!exists) {
            sphere[sphere_idx] = items[idx];
            sphere_idx++;
        }
        idx++;
    }
    while (idx < K) {
        bool exists = false;
        for (int i = 0; i < N; ++i) {
            if (items[idx] == sphere[i]) {
                exists = true;
                break;
            }
        }
        if (!exists) {
            int temp[N];
            memset(temp, 0, sizeof(temp));
            int max_idx = 0;
            for (int i = 0; i < N; ++i) {
                for (int j = idx + 1; j < K; ++j) {
                    if (items[j] == sphere[i]) {
                        temp[i] = j;
                        if (temp[max_idx] < temp[i]) {
                            max_idx = i;
                        }
                        break;
                    }
                }
            }
            for (int i = 0; i < N; ++i) {
                if (!temp[i]) {
                    max_idx = i;
                    break;
                }
            }
            sphere[max_idx] = items[idx];
            count++;
        }
        idx++;
    }
    printf("%d\n", count);
    return 0;
}