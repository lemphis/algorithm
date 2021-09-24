#include <cstring>
#include <iostream>

using namespace std;

#define endl '\n'
#define MAX 100001

int students[MAX];
bool visit[MAX];
bool done[MAX];
int team_count;

void clear();
void dfs(int start);

/**
 * @see [텀 프로젝트](https://www.acmicpc.net/problem/9466)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        int total;
        team_count = 0;
        cin >> total;
        clear();
        for (int i = 1; i <= total; ++i) {
            cin >> students[i];
        }
        for (int i = 1; i <= total; ++i) {
            if (!visit[i]) {
                dfs(i);
            }
        }
        cout << total - team_count << endl;
    }
}

void clear() {
    memset(students, 0, sizeof(students));
    memset(visit, 0, sizeof(visit));
    memset(done, 0, sizeof(done));
}

void dfs(int start) {
    visit[start] = 1;
    if (!visit[students[start]]) {
        dfs(students[start]);
    } else {
        if (!done[students[start]]) {
            for (int i = students[start]; i != start; i = students[i]) {
                team_count++;
            }
            team_count++;
        }
    }
    done[start] = 1;
}