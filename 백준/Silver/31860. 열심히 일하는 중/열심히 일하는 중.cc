#include <iostream>
#include <queue>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;
    int N, M, K;
    cin >> N >> M >> K;
    priority_queue<int> pq;
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        pq.push(num);
    }
    int count = 0;
    int now_feels = 0;
    string output;
    output.reserve(1 << 24);
    while (!pq.empty()) {
        int top = pq.top();
        pq.pop();
        now_feels = now_feels / 2 + top;
        output += std::to_string(now_feels) + "\n";
        top -= M;
        if (top > K) {
            pq.push(top);
        }
        ++count;
    }

    cout << count << endl;
    cout << output;

    return 0;
}
