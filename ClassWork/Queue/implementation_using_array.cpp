#include<bits/stdc++.h>
using namespace std;
#define MAX 1e6
auto init = []() { 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Queue {
    int arr[(int)(MAX)];
    int head = -1;
    int tail = -1;

    public:
    Queue() {
        
    }

    // Pushing element into the queue
    void enque(int val) {
        if(tail == MAX - 1) {
            throw std:: overflow_error("Queue is full.");
        }
        arr[++tail] = val;
    }

    // Deleting front element
    int deque() {
        if(head == tail) {
            throw std:: underflow_error("Queue is empty.");
        }
        int temp = arr[head + 1];
        head++;
        return temp;
    }

    // Getting front element
    int front() {
        if(head == tail) {
            throw std:: underflow_error("Queue is empty.");
        }
        return arr[head + 1];
    }

    // Queue is empty?
    bool empty() {
        return head == tail;
    }

    // Get size of the queue
    int size() {
        return tail - head;
    }
};

int main() {
   
    Queue *q = new Queue();
    q->enque(9);
    q->enque(10);
    q->enque(8);
    cout << "Front: " << q->deque() << "\t\t\t{9, 10, 8}" << '\n';
    cout << "size: " << q->size() << "\t\t\t{10, 8}" << '\n';
    q->enque(-1);
    cout << "size: " << q->size() << "\t\t\t{10, 8, -1}" << '\n';
    cout << "Front: " << q->deque() << "\t\t\t{10, 8, -1}" << '\n';
    cout << "Front: " << q->deque() << "\t\t\t{8, -1}" << '\n';
    cout << "size: " << q->size() << "\t\t\t{-1}" << '\n';

    cout << (q->empty()? "Queue is empty": "Queue is not empty") << "\t\t\t{-1}\n";
    cout << "Front: " << q->deque() << "\t\t\t{-1}" <<'\n';
    cout << (q->empty()? "Queue is empty": "Queue is not empty") << "\t\t\t{ }\n";

    return 0;
}
