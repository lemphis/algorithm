#include <iostream>

#define endl '\n'
#define MAX 20000

using std::cin;
using std::cout;
using std::ios;
using std::string;

class Deque {
   private:
    int items[MAX];
    int begin = MAX / 2;
    int end = MAX / 2 + 1;

   public:
    void push_front(int n);
    void push_back(int n);
    int pop_front();
    int pop_back();
    int size();
    int empty();
    int front();
    int back();
};

void Deque::push_front(int n) {
    this->items[begin] = n;
    this->begin--;
}

void Deque::push_back(int n) {
    this->items[end] = n;
    this->end++;
}

int Deque::pop_front() {
    if (this->end - this->begin == 1) {
        return -1;
    }
    return this->items[++begin];
}

int Deque::pop_back() {
    if (this->end - this->begin == 1) {
        return -1;
    }
    return this->items[--end];
}

int Deque::size() {
    return (this->end - this->begin) - 1;
}

int Deque::empty() {
    if (this->end - this->begin == 1) {
        return 1;
    }
    return 0;
}

int Deque::front() {
    if (this->end - this->begin == 1) {
        return -1;
    }
    return this->items[begin + 1];
}

int Deque::back() {
    if (this->end - this->begin == 1) {
        return -1;
    }
    return this->items[end - 1];
}

/**
 * @see [덱](https://www.acmicpc.net/problem/10866)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N;
    cin >> N;
    Deque deque;
    while (N--) {
        string command;
        cin >> command;
        if (command == "push_front" || command == "push_back") {
            int num;
            cin >> num;
            if (command == "push_front") {
                deque.push_front(num);
            } else {
                deque.push_back(num);
            }
        } else if (command == "pop_front" || command == "pop_back") {
            if (command == "pop_front") {
                cout << deque.pop_front() << endl;
            } else {
                cout << deque.pop_back() << endl;
            }
        } else if (command == "size") {
            cout << deque.size() << endl;
        } else if (command == "empty") {
            cout << deque.empty() << endl;
        } else if (command == "front") {
            cout << deque.front() << endl;
        } else if (command == "back") {
            cout << deque.back() << endl;
        }
    }
}