#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

// A -> B -> C
class A {
    public:
        A() {
            cout << "A class\n";
        }
};

class B: public A {
    public:
        B() {
            cout << "B class\n";
        }
};

class C: public B {
    public:
        C() {
            cout << "C class\n";
        }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    C a;
    
    return 0;
}
