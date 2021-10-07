#include <cstdio>
#include <cstring>

using namespace std;

/**
 * @see [문서 검색](https://www.acmicpc.net/problem/1543)
 */
int main() {
    char docs[2502], target[52];
    fgets(docs, 2502, stdin);
    fgets(target, 52, stdin);
    int docs_len = strlen(docs) - 1;
    int target_len = strlen(target) - 1;
    if (docs_len < target_len) {
        printf("%d\n", 0);
        return 0;
    }
    docs[docs_len] = target[target_len] = '\0';
    int docs_idx = 0;
    int target_idx = 0;
    int count = 0;
    while (docs_idx <= docs_len - target_len) {
        bool is_same = true;
        while (target_idx < target_len) {
            if (docs[docs_idx + target_idx] != target[target_idx]) {
                is_same = false;
                break;
            }
            target_idx++;
        }
        if (is_same) {
            count++;
            docs_idx += target_len;
        } else {
            docs_idx++;
        }
        target_idx = 0;
    }
    printf("%d\n", count);
    return 0;
}