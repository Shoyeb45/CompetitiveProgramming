#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

// Runtime polymorphism
class Parent {
    public:
        virtual void print() {  // Virtual keyword ensure to pass the function from parent to child
            cout << "Parent class - print\n";
        }
        void show() {
            cout << "Parent class - show\n";
        }
};

class Child: public Parent {
    public:
        void print() {
            cout << "child class - print\n";
        }
        void show() {
            cout << "child class - show\n";
        }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Parent *p;
    Child c;
    p = &c;
    p->print();
    p->show();
    return 0;
}
