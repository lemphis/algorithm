#include <queue>
#include <vector>

using namespace std;

/**
 * @see [더 맵게](https://programmers.co.kr/learn/courses/30/lessons/42626)
 */
int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());

    int answer = 0;
    while (pq.top() < K) {
        if (pq.size() == 1) {
            answer = -1;
            break;
        }
        int first = pq.top();
        pq.pop();
        pq.push(first + pq.top() * 2);
        pq.pop();
        answer++;
    }

    return answer;
}