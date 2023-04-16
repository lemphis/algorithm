#include <ctime>
#include <iomanip>
#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;

int main() {
    fastio;
    time_t now = time(0);
    tm* local_date = localtime(&now);
    cout << put_time(local_date, "%Y-%m-%d");

    return 0;
}