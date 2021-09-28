#include <cstdio>
#include <list>

using namespace std;

/**
 * @see [요세푸스 문제 0](https://www.acmicpc.net/problem/11866)
 */
int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    list<int> people;
    list<int>::iterator iter = people.end();
    for (int i = 1; i <= N; ++i) {
        people.insert(iter, i);
    }
    iter = people.begin();
    printf("%c", '<');
    while (!people.empty()) {
        for (int i = 0; i < K - 1; ++i) {
            if (iter == people.end()) {
                iter = people.begin();
            }
            iter++;
        }
        if (iter == people.end()) {
            iter = people.begin();
        }
        if (people.size() == 1) {
            printf("%d", *iter);
        } else {
            printf("%d, ", *iter);
        }
        iter = people.erase(iter);
    }
    printf("%c", '>');
}