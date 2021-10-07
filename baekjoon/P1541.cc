#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

/**
 * @see [잃어버린 괄호](https://www.acmicpc.net/problem/1541)
 */
int main() {
    char expression[51];
    scanf("%s", expression);
    char num[6];
    int exp_len = strlen(expression);
    int min_value = 0;
    bool is_minus = false;
    int unit_count = 0;
    for (int i = 0; i <= exp_len; ++i) {
        if (expression[i] == '+' || expression[i] == '-' || i == exp_len) {
            if (is_minus) {
                min_value -= atoi(num);
            } else {
                min_value += atoi(num);
            }
            memset(num, 0, sizeof(num));
            unit_count = 0;
        } else {
            num[unit_count++] = expression[i];
        }
        if (expression[i] == '-') {
            is_minus = true;
        }
    }
    printf("%d\n", min_value);
    return 0;
}