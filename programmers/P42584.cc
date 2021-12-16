#include <stack>
#include <vector>

using namespace std;

/**
 * @see [주식가격](https://programmers.co.kr/learn/courses/30/lessons/42584)
 */
vector<int> solution(vector<int> prices) {
    int size = prices.size();
    stack<int> st;
    vector<int> answer(size);
    for (int i = 0; i < size; ++i) {
        while (!st.empty() && prices[st.top()] > prices[i]) {
            answer[st.top()] = i - st.top();
            st.pop();
        }
        st.push(i);
    }

    while (!st.empty()) {
        answer[st.top()] = size - 1 - st.top();
        st.pop();
    }

    return answer;
}