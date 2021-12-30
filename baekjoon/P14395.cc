#include <iostream>
#include <queue>
#include <set>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;
using ll = long long;
using pls = pair<ll, string>;

string bfs(ll s, ll t);

/**
 * @see [4연산](https://www.acmicpc.net/problem/14395)
 */
int main() {
    fastio;
    ll s, t;
    cin >> s >> t;

    cout << bfs(s, t) << endl;

    return 0;
}

string bfs(ll s, ll t) {
    if (s == t) return "0";

    queue<pls> q;
    q.push({s, ""});

    set<ll> nums;
    nums.insert(s);

    string ans;
    while (!q.empty()) {
        auto [num, opers] = q.front();
        if (num == t) {
            ans = opers;
            break;
        }

        q.pop();

        if (num * num <= t && nums.find(num * num) == nums.end()) {
            q.push({num * num, opers + '*'});
            nums.insert(num * num);
        }
        if (num + num <= t && nums.find(num + num) == nums.end()) {
            q.push({num + num, opers + '+'});
            nums.insert(num + num);
        }
        if (num / num <= t && nums.find(num / num) == nums.end()) {
            q.push({num / num, opers + '/'});
            nums.insert(num / num);
        }
    }

    return ans.length() > 0 ? ans : "-1";
}