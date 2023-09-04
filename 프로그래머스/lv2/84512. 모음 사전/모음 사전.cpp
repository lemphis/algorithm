#include <string>
#include <vector>

using namespace std;

const char vowel[5] = {'A', 'E', 'I', 'O', 'U'};

void dfs(int& count, string& word, string& now, int idx, int& ans);

int solution(string word) {
    int answer = 0;
    string now = "";
    int count = 0;
    dfs(count, word, now, 0, answer);
    return answer;
}

void dfs(int& count, string& word, string& now, int idx, int& ans) {
    if (word == now) {
        ans = count;
        return;
    }
    if (ans > 0) return;
    if (idx == 5) return;
    for (int i = 0; i < 5; ++i) {
        now += vowel[i];
        dfs(++count, word, now, idx + 1, ans);
        now.pop_back();
    }
}