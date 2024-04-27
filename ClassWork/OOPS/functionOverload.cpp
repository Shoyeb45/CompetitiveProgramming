#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

// Compile time overloading - polymorphism
class Great {
    public:
        void MAX(int x, int y) {
            if(x > y) {
                cout << x << endl;
            } else {
                cout << y << endl;
            }
            cout << "Function with two arguments is called\n";
        }

        void MAX(int x, int y, int z) {
            if(x > y && x > z) {
                cout << x << endl;
            } else if(y > x && y > z){
                cout << y << endl;
            } else {
                cout << z << endl;
            }
            cout << "Function with three arguments is called\n";
        }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Great c;
    c.MAX(2, 5);
    c.MAX(12, 10, 9);
    
    return 0;
}
