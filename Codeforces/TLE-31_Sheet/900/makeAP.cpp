#include<bits/stdc++.h>
#define loop(i, n) for(int i = 0; i < n; i++)  
using namespace std;
typedef long long ll;


int main() {
    int t;
    cin >> t;

    while (t--)
    {
        ll a, b, c;
        cin >> a >> b >> c;

        if(2 * b == a + c)  cout << "YES\n";
        else {
            if(((a + c) % (2*b) == 0) || (((2 * b - a) % c == 0) && (2 * b - a) > 0)|| (((2 * b - c) % a == 0) && (2 * b - c) > 0))  cout << "YES\n";
            else    cout << "NO\n"; 
        }
    }
}