#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

void dfs(vector<vector<string>>& tickets, bool visited[], vector<string>& temp, vector<string>& answer, int insert_idx) {
    if (insert_idx == temp.size()) {
        answer = temp;
        return;
    }

    for (int i = 0; i < tickets.size(); ++i) {
        if (!visited[i] && tickets[i][0] == temp[insert_idx - 1]) {
            visited[i] = 1;
            temp[insert_idx] = tickets[i][1];
            dfs(tickets, visited, temp, answer, insert_idx + 1);
            if (answer[0].length() > 0) {
                return;
            }
            visited[i] = 0;
        }
    }
}

/**
 * @see [여행경로](https://programmers.co.kr/learn/courses/30/lessons/43164)
 */
vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());
    int size = tickets.size();

    bool visited[size];
    memset(visited, 0, sizeof(visited));

    vector<string> answer(size + 1), temp(size + 1);
    temp[0] = "ICN";
    dfs(tickets, visited, temp, answer, 1);

    return answer;
}