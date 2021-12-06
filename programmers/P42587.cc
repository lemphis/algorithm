#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

#define endl '\n'

/**
 * @see [프린터](https://programmers.co.kr/learn/courses/30/lessons/42587)
 */
int solution(vector<int> priorities, int location) {
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < priorities.size(); ++i) {
        pq.push({priorities[i], i});
    }

    int answer = 1;
    for (int i = 0; i < priorities.size(); ++i) {
        pair<int, int> item = pq.top();
        if (item.second == location) break;
        pq.pop();
        answer++;
    }

    return answer;
}

int main() {
    vector<int> priorities = {1, 1, 9, 1, 1, 1};
    int location = 0;
    cout << solution(priorities, location) << endl;
    return 0;
}