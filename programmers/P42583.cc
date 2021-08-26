#include <cstring>
#include <deque>
#include <iostream>
#include <utility>
#include <vector>

using std::cout;
using std::deque;
using std::make_pair;
using std::pair;
using std::vector;

/**
 * @see [다리를 지나는 트럭](https://programmers.co.kr/learn/courses/30/lessons/42583)
 */
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int wait_idx = 0;
    deque<int> wait;
    deque<pair<int, int> > crossing;

    for (int i = 0; i < truck_weights.size(); ++i) {
        wait.push_back(truck_weights[i]);
    }

    while (wait_idx < truck_weights.size() || crossing.size()) {
        answer++;
        int crossing_size = crossing.size();
        if (crossing_size) {
            for (int i = 0; i < crossing_size; ++i) {
                crossing[i].second--;
            }
            if (crossing[0].second <= 0) {
                crossing.pop_front();
            }
        }
        int sum = 0;
        for (int i = 0; i < crossing.size(); ++i) {
            sum += crossing[i].first;
        }
        if (wait_idx < truck_weights.size() && sum + wait[wait_idx] <= weight) {
            crossing.push_back(make_pair(wait[wait_idx], bridge_length));
            wait_idx++;
        }
    }

    return answer;
}