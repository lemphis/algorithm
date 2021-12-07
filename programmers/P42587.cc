#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

/**
 * @see [프린터](https://programmers.co.kr/learn/courses/30/lessons/42587)
 */
int solution(vector<int> priorities, int location) {
    queue<pair<int, int>> q;
    priority_queue<int> pq;
    for (int i = 0; i < priorities.size(); ++i) {
        q.push({priorities[i], i});
        pq.push(priorities[i]);
    }

    int answer = 0;
    while (!q.empty()) {
        pair<int, int> item = q.front();
        q.pop();
        if (pq.top() == item.first) {
            pq.pop();
            answer++;
            if (item.second == location) {
                break;
            }
        } else {
            q.push(item);
        }
    }

    return answer;
}