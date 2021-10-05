#include <cstdio>

using namespace std;

class Heap {
   private:
    int arr[100001];
    int size = 0;

   public:
    void push(int item);
    int pop();
};

void Heap::push(int item) {
    this->size++;
    this->arr[this->size] = item;
    for (int i = size; i > 1; i /= 2) {
        if (this->arr[i] > this->arr[i / 2]) {
            int temp = arr[i];
            arr[i] = arr[i / 2];
            arr[i / 2] = temp;
        } else {
            break;
        }
    }
}

int Heap::pop() {
    if (this->size == 0) {
        return 0;
    }
    int pop_val = arr[1];
    arr[1] = arr[size];
    int left = 2;
    while (left <= size) {
        int right = left + 1;
        if (right <= size) {
            if (this->arr[left] < this->arr[right]) {
                left = right;
            }
        }
        if (this->arr[left] < this->arr[left / 2]) {
            break;
        }
        int temp = this->arr[left];
        this->arr[left] = this->arr[left / 2];
        this->arr[left / 2] = temp;
        left *= 2;
    }
    this->size--;
    return pop_val;
}

/**
 * @see [최대 힙](https://www.acmicpc.net/problem/11279)
 */
int main() {
    int N;
    scanf("%d", &N);
    Heap heap;
    while (N--) {
        int cmd;
        scanf("%d", &cmd);
        if (cmd == 0) {
            printf("%d\n", heap.pop());
        } else {
            heap.push(cmd);
        }
    }
}