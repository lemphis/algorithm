#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

using namespace std;
using pis = pair<int, string>;

/**
 * @see [베스트셀러](https://www.acmicpc.net/problem/1302)
 */
int main() {
    fastio;
    int N;
    cin >> N;
    map<string, int> books;
    for (int i = 0; i < N; ++i) {
        string book;
        cin >> book;
        books[book]++;
    }

    vector<pis> sortedBooks;
    int max_count = 0;
    for (const auto& [book, count] : books) {
        sortedBooks.push_back({count, book});
    }

    sort(sortedBooks.begin(), sortedBooks.end(), [](pis& a, pis& b) -> bool { 
        return a.first == b.first ? a.second < b.second : a.first > b.first;
    });

    cout << sortedBooks[0].second;

    return 0;
}