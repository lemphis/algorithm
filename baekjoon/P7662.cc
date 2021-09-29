#include <cstdio>
#include <functional>
#include <set>

using namespace std;

/**
 * @see [이중 우선순위 큐](https://www.acmicpc.net/problem/7662)
 */
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        multiset<int, greater<int>> mset;
        int cmd_cnt;
        scanf("%d", &cmd_cnt);
        while (cmd_cnt--) {
            getchar();
            char cmd;
            int item;
            scanf("%c %d", &cmd, &item);
            if (cmd == 'I') {
                mset.insert(item);
            } else {
                if (!mset.empty()) {
                    mset.erase(item == 1 ? mset.begin() : --mset.end());
                }
            }
        }
        if (mset.empty()) {
            puts("EMPTY");
        } else {
            printf("%d %d\n", *mset.begin(), *(--mset.end()));
        }
    }

    return 0;
}