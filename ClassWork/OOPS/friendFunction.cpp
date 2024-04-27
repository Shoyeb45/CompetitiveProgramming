#include<bits/stdc++.h>
using namespace std;

// Friend Function : non-memeber function which can access private memeber of the class

class Point {
    int x;
    int y;

    public:
        Point(int a, int b) {
            x = a;
            y = b;
        }
    
    friend void print(Point &obj); // Function definition
};

void print(Point &obj) {
    cout << "(" << obj.x << ", " << obj.y << ")\n" ;  // Can access private memeber because function is friend function
}
int main() {
    
    Point p1(3, 2);
    print(p1);

    return 0;
}
