#include <cstdio>
#include <cstring>
#include <deque>

using namespace std;

/**
 * @see [PPAP](https://www.acmicpc.net/problem/16120)
 */
int main() {
    char str[1'000'001];
    scanf("%s", str);
    char target[] = "PPAP";
    int len = strlen(str);
    deque<char> dq;
    int target_idx = 0;
    for (int i = 0; i < len; ++i) {
        dq.push_back(str[i]);
        int size = dq.size();
        if (size >= 4) {
            bool is_same = true;
            for (int j = 0; j < 4; ++j) {
                if (dq[size - (4 - j)] != target[j]) {
                    is_same = false;
                    break;
                }
            }
            if (is_same) {
                for (int j = 0; j < 4; ++j) {
                    dq.pop_back();
                }
                dq.push_back('P');
            }
        }
    }
    if (dq.size() == 1 && dq.front() == 'P') {
        puts(target);
    } else {
        puts("NP");
    }
    return 0;
}