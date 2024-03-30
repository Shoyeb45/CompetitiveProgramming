#include<bits/stdc++.h>
using namespace std;

int main () {
    int t;
    cin >> t;

    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        if(c % 2 == 0) {
            if(a == b)  cout << "Second\n";
            else if(a > b)   cout << "First\n";
            else    cout << "Second\n";
        } else {
            if(a == b)  cout << "First\n";
            else if(a > b)   cout << "First\n";
            else    cout << "Second\n";

        }
    }
    
}