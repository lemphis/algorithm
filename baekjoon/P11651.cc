#include <algorithm>
#include <iostream>
#include <utility>

using namespace std;

#define endl '\n'

/**
 * @see [좌표 정렬하기 2](https://www.acmicpc.net/problem/11651)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N;
    cin >> N;
    pair<int, int> points[N];
    for (int i = 0; i < N; ++i) {
        cin >> points[i].second >> points[i].first;
    }

    sort(points, points + N);

    for (int i = 0; i < N; ++i) {
        cout << points[i].second << ' ' << points[i].first << endl;
    }

    return 0;
}