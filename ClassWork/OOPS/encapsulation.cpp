#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

class Point {
    // Set variables private
private:
    int x;
    int y;

    // Set methods public 
public:
    // Setter
    void set(int x_p, int y_p) {
        x = x_p;
        y = y_p;
    }

    // Getter
    int getX() {
        return x;
    }

    int getY() {
        return y;
    } 
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Point p1;
    p1.set(4, 5);

    // This will give error
    // cout << p1.x ;

    // So we have to  use the methods to acccess the values
    cout << p1.getX() << " " << p1.getY() << '\n';
    return 0;
}
