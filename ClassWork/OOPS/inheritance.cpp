#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

// We make child class which inherits the variable and methods of parent class

// Access specifiers :
// 1. Public : class method and variables will be available to use in entire code
// 2. Protected : class method and variables will be available to use in parent and child class only
// 3. Private : class method and variables will be available to use in parent class only

class Parent {
public:
    int x;

protected:
    int y;

private:
    int z;
};

// Let's make child classes 

class Child1: public Parent {
    // x and y will be accessible, x - public , y - protected
    // z - not accessible
};
class Child1: protected Parent {
    // x and y will be accessible, x - protected , y - protected
    // z - not accessible
};
class Child1: private Parent {
    // x and y will be accessible, x - private , y - private
    // z - not accessible   
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    


    
    return 0;
}

// Types of Inheritence
// 1. single inheritence
// 2. Multi level inheritence
// 3. Multiple Inheritence
// 4. Hierarchial Inheritence
// 5. Hybrid Inheritence