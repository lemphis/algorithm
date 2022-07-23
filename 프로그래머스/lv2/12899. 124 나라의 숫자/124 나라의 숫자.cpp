#include <string>
#include <vector>

using namespace std;

string convert(int n) {
    string s;
    switch (n % 3) {
        case 0:
            s = "4";
            break;
        case 1:
            s = "1";
            break;
        case 2:
            s = "2";
            break;
    }
    return s;
}

string solution(int n) {
    string ans = "";
    while (n > 0) {
        ans.insert(0, convert(n));
        if (n % 3 == 0) n--;
        n /= 3;
    }
    return ans;
}