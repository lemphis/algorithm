#include <algorithm>
#include <cstdio>

using namespace std;

typedef struct {
    int age;
    char name[101];
} Member;

bool compare(Member a, Member b);

/**
 * @see [나이순 정렬](https://www.acmicpc.net/problem/10814)
 */
int main() {
    int N;
    scanf("%d", &N);
    Member members[N];
    for (int i = 0; i < N; ++i) {
        Member member;
        scanf("%d %s", &member.age, member.name);
        members[i] = member;
    }
    stable_sort(members, members + N, compare);
    for (int i = 0; i < N; ++i) {
        printf("%d %s\n", members[i].age, members[i].name);
    }
    return 0;
}

bool compare(Member a, Member b) {
     return a.age < b.age; 
}