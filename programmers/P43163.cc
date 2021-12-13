#include <queue>
#include <string>
#include <utility>

using namespace std;

/**
 * @see [단어 변환](https://programmers.co.kr/learn/courses/30/lessons/43163)
 */
int solution(string begin, string target, vector<string> words) {
    queue<pair<string, int>> q;
    q.push({begin, 0});
    int size = words.size();
    bool* visited = new bool[size]{0};

    int answer = 0;
    while (!q.empty()) {
        auto [item, times] = q.front();
        if (item == target) {
            answer = times;
            break;
        }
        q.pop();
        for (int i = 0; i < begin.length(); ++i) {
            string temp = item;
            for (int alp_idx = 0; alp_idx < 26; ++alp_idx) {
                temp[i] = alp_idx + 'a';
                for (int idx = 0; idx < size; ++idx) {
                    if (!visited[idx] && temp == words[idx]) {
                        visited[idx] = 1;
                        q.push({temp, times + 1});
                    }
                }
            }
        }
    }

    delete[] visited;

    return answer;
}