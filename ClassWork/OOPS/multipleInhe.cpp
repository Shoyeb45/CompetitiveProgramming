#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

// C -> A, B (C inherites both A and B)

class Parent1 {
    public:
        Parent1() {
            cout << "I am Parent1 class\n";
        }
};
class Parent2 {
    public:
        Parent2() {
            cout << "I am Parent2 class\n";
        }
};

class Child: public Parent2, public Parent1 {
    public:
        Child() {
            cout << "I am child class\n";
        }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Child C;

    return 0;
}
