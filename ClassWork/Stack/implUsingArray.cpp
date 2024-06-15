#include<bits/stdc++.h>

using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;
#define MAX 1e5+1

auto init = []() { 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Stack {
    public:
    int top = -1;
    int a[MAX];

    Stack() {
     
    }

    void push(int val) {
        if(top < MAX - 1) {
            top++;
            a[top] = val;
        } else {
            std::__throw_overflow_error("Stack is full");
        }
    }

    int pop() {
        if(top > -1) {
            int val = a[top];
            top--;
            return ele;
        } else {
            std:: __throw_underflow_error("Stack is empty");
        }
    }
    
    bool empty() {
        return top == - 1;
    }

    int topEle() {
        return a[top];
    }
};


int main() {
    
    Stack s;
    s.push(12);
    s.push(14);
    cout << s.top() << '\n';
    return 0;
}
