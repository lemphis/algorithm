#include <algorithm>
#include <iostream>

using namespace std;

#define endl '\n'
#define MAX 50

typedef struct Person {
    int x;
    int y;
} Person;

Person people[MAX];

/**
 * @see [덩치](https://www.acmicpc.net/problem/7568)
 */
int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> people[i].x >> people[i].y;
    };

    for (int i = 0; i < N; ++i) {
        int rank = 1;
        for (int j = 0; j < N; ++j) {
            if (people[i].x < people[j].x && people[i].y < people[j].y) {
                rank++;
            }
        };
        cout << rank << ' ';
    };

    return 0;
}