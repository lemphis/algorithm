#include <cstring>
#include <iostream>
#include <stack>

using namespace std;

#define endl '\n'
#define MAX 101

int priority(char oper);

/**
 * @see [후위 표기식](https://www.acmicpc.net/problem/1918)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    char infix[MAX];
    cin >> infix;

    stack<char> operators;
    int len = strlen(infix);
    for (int i = 0; i < len; ++i) {
        if (infix[i] >= 'A' && infix[i] <= 'Z') {
            cout << infix[i];
        } else {
            if (operators.empty()) {
                operators.push(infix[i]);
                continue;
            }

            if (infix[i] == '(') {
                operators.push(infix[i]);
            } else if (infix[i] == ')') {
                while (operators.top() != '(') {
                    cout << operators.top();
                    operators.pop();
                }
                operators.pop();
            } else {
                if (priority(operators.top()) < priority(infix[i])) {
                    operators.push(infix[i]);
                } else {
                    while (!operators.empty() && priority(operators.top()) >= priority(infix[i])) {
                        cout << operators.top();
                        operators.pop();
                    }
                    operators.push(infix[i]);
                }
            }
        }
    }

    while (!operators.empty()) {
        cout << operators.top();
        operators.pop();
    }

    return 0;
}

int priority(char oper) {
    switch (oper) {
        case '+':
        case '-':
            return 1;
            break;
        case '*':
        case '/':
            return 2;
            break;
        case '(':
            return 0;
            break;
    }

    return 0;
}