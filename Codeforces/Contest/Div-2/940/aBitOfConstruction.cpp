#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        ll n, k;
        cin >> n >> k;

        int x = (int)(log2(k)) + 1;
    
        ll a1 = 1;
        a1 = (a1 << (x - 1)) - 1; 

        ll a2 = k - a1;
    
        if(n == 1)  cout << k << '\n';
        else {
            cout << a1 << " " << a2 << " ";
            for(int i = 3; i <= n; i++) 
                cout << 0 << " ";
            cout << endl;
        }
}
}
