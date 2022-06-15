#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

/**
 * @see [걸그룹 마스터 준석이](https://www.acmicpc.net/problem/16165)
 */
int main() {
    fastio;
    int N, M;
    cin >> N >> M;
    map<string, string> member_to_group;
    map<string, vector<string> > group_to_member;
    for (int i = 0; i < N; ++i) {
        string group;
        cin >> group;
        int member_count;
        cin >> member_count;
        vector<string> members(member_count);
        for (int j = 0; j < member_count; ++j) {
            string member;
            cin >> member;
            member_to_group[member] = group;
            members[j] = member;
        }
        sort(members.begin(), members.end());
        group_to_member[group] = members;
    }

    for (int i = 0; i < M; ++i) {
        string member_or_group;
        int type;
        cin >> member_or_group >> type;
        if (type == 0) {
            int size = group_to_member[member_or_group].size();
            for (int i = 0; i < size; ++i) {
                cout << group_to_member[member_or_group][i] << endl;
            }
        } else {
            cout << member_to_group[member_or_group] << endl;
        }
    }

    return 0;
}