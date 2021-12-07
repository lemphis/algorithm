#include <iostream>
#include <vector>

using namespace std;

/**
 * @see [주식가격](https://programmers.co.kr/learn/courses/30/lessons/42584)
 */
vector<int> solution(vector<int> prices) {
    int size = prices.size();
    vector<int> answer(size, -1);
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (prices[i] > prices[j]) {
                answer[i] = j - i;
                break;
            }
        }
        if (answer[i] == -1) {
            answer[i] = size - i - 1;
        }
    }

    answer[size - 1] = 0;

    return answer;
}