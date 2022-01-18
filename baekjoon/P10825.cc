#include <algorithm>
#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

typedef struct Score {
    string name;
    int subject;
    int english;
    int math;
} Score;

/**
 * @see [국영수](https://www.acmicpc.net/problem/10825)
 */
int main() {
    fastio;
    int N;
    cin >> N;
    Score score[N];
    for (int i = 0; i < N; ++i) {
        cin >> score[i].name >> score[i].subject >> score[i].english >>
            score[i].math;
    }

    sort(score, score + N, [](Score& a, Score& b) -> bool {
        if (a.subject == b.subject) {
            if (a.english == b.english) {
                if (a.math == b.math) {
                    return a.name < b.name;
                }
                return a.math > b.math;
            }
            return a.english < b.english;
        }
        return a.subject > b.subject;
    });

    for (int i = 0; i < N; ++i) {
        cout << score[i].name << endl;
    }

    return 0;
}
