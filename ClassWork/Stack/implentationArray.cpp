#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

class Stack {
    public: 
        vector<int> a;
        int sz;
    
    Stack() {
        sz = 0;
    }

    void push(int val) {
        a.push_back(val);
        sz++;
        return;
    }

    void pop() {
        a.pop_back();
        sz--;
    }

    int top() {
        return a.back();
    }

    int size() {
        return sz;
    }

    bool empty() {
        return sz == 0;
    }
};
int main() {
    
    Stack a;
    a.push(14);
    cout << a.top() << '\n';
    a.push(90);
    a.push(65);
    cout << a.top() << '\n';
    a.pop();
    if(!a.empty())
        cout << a.size() << '\n';
    
    return 0;
}
