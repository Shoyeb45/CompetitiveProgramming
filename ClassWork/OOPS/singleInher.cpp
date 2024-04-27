#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

class Parent {
    public:
        Parent() {
            cout << "I am Parent class\n";
        }
};

class Child: public Parent {
    public:
        Child() {
            cout << "I am child class\n";
        }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Child c;    // first parent class will be inititalized

    return 0;
}
