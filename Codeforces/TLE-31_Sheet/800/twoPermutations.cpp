#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;


int main() {
    int t;
    cin >> t;

    while (t--)
    {
        int n, a, b;
        cin >> n >> a >> b;
        
        if(n == a && n == b)    cout << "YES\n";
        else   { 
            if( a + b <= n - 2) cout << "YES\n";
            else    cout << "NO\n";
        }
        
    }
    
}