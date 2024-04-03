#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        int ans = 0;
        for(int i = 0; i < n; i++) { 
            cin >> a[i];
            ans ^= a[i];
        }
        
        int ans2 = 0;
        for (int i = 0; i < n; i++)
        {
            a[i] = (ans ^ a[i]);
                ans2 ^= (a[i]);
        }
        
        if(!ans2)   cout << ans << "\n";
        else    cout << -1 << "\n";        
        
    }
    
}