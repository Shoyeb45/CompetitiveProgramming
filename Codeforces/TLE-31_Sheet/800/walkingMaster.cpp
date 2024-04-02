#include<bits/stdc++.h>
using namespace std;

int main () {
    int t;
    cin >> t;

    while(t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d; 
        
        if((b > d) || (a + (d - c)) < b)    cout << -1 << '\n' ;
        else {
            if(a == c && b == d)    cout << 0 << "\n";
            else {
                a = a + (d - c);
                cout << (a - b) + (d - c) << "\n";
            }
        }
    }
}