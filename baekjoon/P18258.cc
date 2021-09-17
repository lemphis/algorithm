#include <iostream>

#define endl '\n'
#define MAX 2000000

using std::cin;
using std::cout;
using std::ios;
using std::string;

class Queue {
   private:
    int items[MAX];
    int begin = 0;
    int end = 0;

   public:
    void push(int n);
    int pop();
    int size();
    int empty();
    int front();
    int back();
};

void Queue::push(int n) {
    this->items[end] = n;
    this->end++;
}

int Queue::pop() {
    if (this->begin == this->end) {
        return -1;
    }
    return this->items[begin++];
}

int Queue::size() {
    return this->end - this->begin;
}

int Queue::empty() {
    if (this->begin == this->end) {
        return 1;
    }
    return 0;
}

int Queue::front() {
    if (this->begin == this->end) {
        return -1;
    }
    return this->items[begin];
}

int Queue::back() {
    if (this->begin == this->end) {
        return -1;
    }
    return this->items[end - 1];
}

/**
 * @see [큐 2](https://www.acmicpc.net/problem/18258)
 */
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N;
    cin >> N;
    Queue queue;
    while (N--) {
        string command;
        cin >> command;
        if (command == "push") {
            int num;
            cin >> num;
            queue.push(num);
        } else if (command == "pop") {
            cout << queue.pop() << endl;
        } else if (command == "size") {
            cout << queue.size() << endl;
        } else if (command == "empty") {
            cout << queue.empty() << endl;
        } else if (command == "front") {
            cout << queue.front() << endl;
        } else if (command == "back") {
            cout << queue.back() << endl;
        }
    }
}