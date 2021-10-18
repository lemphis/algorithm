#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

void dfs(int L, int C, int depth, int idx, char alp[], char arr[], bool visit[]);
bool is_promise(int L, char arr[]);
bool is_vowel(char alp);

/**
 * @see [암호 만들기](https://www.acmicpc.net/problem/1759)
 */
int main() {
    int L, C;
    scanf("%d %d", &L, &C);
    char alp[C];
    for (int i = 0; i < C; ++i) {
        scanf(" %c", &alp[i]);
    }
    sort(alp, alp + C);
    char arr[L];
    bool visit[C];
    memset(visit, 0, sizeof(visit));
    dfs(L, C, 0, 0, alp, arr, visit);
    return 0;
}

void dfs(int L, int C, int depth, int idx, char alp[], char arr[], bool visit[]) {
    if (depth == L && is_promise(L, arr)) {
        for (int i = 0; i < L; ++i) {
            printf("%c", arr[i]);
        }
        puts("");
        return;
    }

    for (int i = idx; i < C; ++i) {
        if (!visit[i]) {
            visit[i] = true;
            arr[depth] = alp[i];
            dfs(L, C, depth + 1, i, alp, arr, visit);
            visit[i] = false;
        }
    }
}

bool is_promise(int L, char arr[]) {
    int consonant_cnt = 0;
    int vowel_cnt = 0;
    for (int i = 0; i < L; ++i) {
        if (is_vowel(arr[i])) {
            vowel_cnt++;
        } else {
            consonant_cnt++;
        }
    }
    if (consonant_cnt >= 2 && vowel_cnt >= 1) {
        return true;
    }
    return false;
}

bool is_vowel(char alp) {
    char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
    for (int i = 0; i < 5; ++i) {
        if (alp == vowels[i]) {
            return true;
        }
    }
    return false;
}