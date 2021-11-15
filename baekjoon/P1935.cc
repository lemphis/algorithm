#include <cstring>
#include <iostream>
#include <stack>

using namespace std;

#define endl '\n'

/**
 * @see [후위 표기식2](https://www.acmicpc.net/problem/1935)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N;
    cin >> N;

    double operand[N];
    char postfix[60];
    cin >> postfix;
    int len = strlen(postfix);

    for (int i = 0; i < N; ++i) {
        cin >> operand[i];
    }

    stack<double> operands;
    for (int i = 0; i < len; ++i) {
        if (postfix[i] >= 'A' && postfix[i] <= 'Z') {
            operands.push(operand[postfix[i] - 'A']);
        } else {
            double right = operands.top();
            operands.pop();
            double left = operands.top();
            operands.pop();
            double result;
            switch (postfix[i]) {
                case '+':
                    result = left + right;
                    break;
                case '-':
                    result = left - right;
                    break;
                case '*':
                    result = left * right;
                    break;
                case '/':
                    result = left / right;
                    break;
            }
            operands.push(result);
        }
    }

    cout.setf(ios::fixed);
    cout.precision(2);
    cout << operands.top() << endl;

    return 0;
}