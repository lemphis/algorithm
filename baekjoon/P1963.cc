#include <cstring>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

#define endl '\n'
#define MAX 10000

int bfs(int src, int target, vector<int> primes, bool check_prime[], bool visit[]);

/**
 * @see [소수 경로](https://www.acmicpc.net/problem/1963)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int T;
    cin >> T;

    bool check_prime[MAX] = {0};
    vector<int> primes;
    for (int i = 2; i < MAX; ++i) {
        if (!check_prime[i]) {
            if (i >= 1000) {
                primes.push_back(i);
            }
            int times = 2;
            while (i * times < MAX) {
                check_prime[i * times++] = 1;
            }
        }
    }

    int size = primes.size();
    bool visit[MAX];
    while (T--) {
        int src, target;
        cin >> src >> target;
        if (src == target) {
            cout << 0 << endl;
            continue;
        }
        memset(visit, 0, sizeof(visit));
        int result = bfs(src, target, primes, check_prime, visit);
        if (result) {
            cout << result << endl;
        } else {
            cout << "Impossible" << endl;
        }
    }

    return 0;
}

int bfs(int src, int target, vector<int> primes, bool check_prime[], bool visit[]) {
    queue<pair<int, int>> q;
    q.push(make_pair(src, 0));
    visit[src] = true;

    while (!q.empty()) {
        int now = q.front().first;
        int time = q.front().second;
        string num_str = to_string(now);
        q.pop();
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 10; ++j) {
                string temp = num_str;
                temp[i] = j + '0';
                if ((i == 0 && j == 0) || temp == num_str) {
                    continue;
                }
                int num = stoi(temp);
                if (!visit[num] && !check_prime[num]) {
                    if (num == target) {
                        return time + 1;
                    }
                    visit[num] = true;
                    q.push(make_pair(num, time + 1));
                }
            }
        }
    }

    return 0;
}