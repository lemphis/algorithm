#include <iostream>
#include <list>

#define endl '\n'

using std::cin;
using std::cout;
using std::ios;
using std::list;

/**
 * @see [요세푸스 문제](https://www.acmicpc.net/problem/1158)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N, K;
    cin >> N >> K;
    list<int> people;
    list<int>::iterator iter = people.end();
    for (int i = 1; i <= N; ++i) {
        people.insert(iter, i);
    }
    iter = people.begin();
    cout << '<';
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
            cout << *iter;
        } else {
            cout << *iter << ", ";
        }
        iter = people.erase(iter);
    }
    cout << '>';
}