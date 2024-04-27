#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

// A, B -> C (A and B both inherits from C)
class Parent {
    public:
        Parent() {
            cout << "I am Parent class\n";
        }
};

class Child1: public Parent {
    public:
        Child1() {
            cout << "I am child1 class\n";
        }
};

class Child2: public Parent {
    public:
        Child2() {
            cout << "I am child2 class\n";
        }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Child2 c2;
    Child1 c1;

    return 0;
}
