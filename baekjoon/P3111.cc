#include <cstring>
#include <deque>
#include <iostream>

#define endl '\n'

using std::cin;
using std::cout;
using std::deque;
using std::ios;
using std::string;

/**
 * @see [검열](https://www.acmicpc.net/problem/3111)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    char A[26], T[300001];
    cin >> A >> T;
    deque<char> left, right;
    string answer;
    int a_len = strlen(A);
    int t_len = strlen(T);
    if (a_len == 1) {
        for (int i = 0; i < t_len; ++i) {
            if (T[i] != A[0]) {
                left.push_back(T[i]);
            }
        }
    } else {
        int start = 0, end = t_len - 1;
        while (start <= end) {
            int match_count = 0;
            bool delete_once = false;
            while (!delete_once && start <= end) {
                left.push_back(T[start]);
                if (left.size() >= a_len) {
                    for (int i = 0; i < a_len; ++i) {
                        if (left[left.size() - a_len + i] == A[i]) {
                            match_count++;
                        }
                    }
                    if (match_count == a_len) {
                        for (int i = 0; i < a_len; ++i) {
                            left.pop_back();
                        }
                        delete_once = true;
                    }
                }
                match_count = 0;
                start++;
            }
            delete_once = false;
            while (!delete_once && start <= end) {
                right.push_front(T[end]);
                if (right.size() >= a_len) {
                    for (int i = 0; i < a_len; ++i) {
                        if (right[i] == A[i]) {
                            match_count++;
                        }
                    }
                    if (match_count == a_len) {
                        for (int i = 0; i < a_len; ++i) {
                            right.pop_front();
                        }
                        delete_once = true;
                    }
                }
                match_count = 0;
                end--;
            }
        }
    }
    for (int i = 0; i < left.size(); ++i)
        answer += left[i];
    for (int i = 0; i < right.size(); ++i)
        answer += right[i];
    while (answer.find(A) != string::npos)
        answer.erase(answer.find(A), a_len);

    cout << answer << endl;
}