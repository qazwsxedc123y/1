#include <iostream>
#include <vector>
using namespace std;

class MyCircularQueue {
private:
    int top;
    int rear; // 最后一个的下一个
    int cp;
    vector<int> nums;
public:
    MyCircularQueue(int k) {
        cp = k;
        nums = vector<int>(cp);
        top = rear = 0;
    }

    bool enQueue(int value) {
        // 3 -- 0 1 2
        if (isFull()) return false;
        nums[rear++] = value;
        rear %= cp;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;
        top++;
        top %= cp;
        return true;
    }

    int Front() {
        if (isEmpty()) return -1;
        return nums[top];
    }

    int Rear() {
        if (isEmpty()) return -1;
        return nums[(rear - 1 + cp) % cp];
    }

    bool isEmpty() {
        return top == rear;
    }

    bool isFull() {
        return top == ((rear - 1 + cp) % cp);
    }
};


class MyCircularQueue {
private:
    int top;
    int rear; // 最后一个的下一个
    int cp;
    int sz;
    vector<int> nums;
public:
    MyCircularQueue(int k) {
        cp = k;
        nums = vector<int>(cp);
        top = rear = sz = 0;
    }

    bool enQueue(int value) {
        // 3 -- 0 1 2
        if (isFull()) return false;
        nums[rear++] = value;
        rear %= cp;
        sz++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;
        top++;
        top %= cp;
        sz--;
        return true;
    }

    int Front() {
        if (isEmpty()) return -1;
        return nums[top];
    }

    int Rear() {
        if (isEmpty()) return -1;
        return nums[(rear - 1 + cp) % cp];
    }

    bool isEmpty() {
        return sz == 0;
    }

    bool isFull() {
        return sz == cp;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

int main()
{
    MyCircularQueue s(3);
    s.enQueue(1);
    s.enQueue(2);
    s.enQueue(3);
    return 0;
}

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */