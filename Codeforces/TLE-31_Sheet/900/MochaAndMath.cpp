#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;

        vector<ll> a(n);
        loop(i, n)  cin >> a[i];
        
        
        ll ans = a[0];
        for(int i = 1; i < n; i++) {
            ans = (ans & a[i]);
        }
        
        cout << ans << endl;
    }
}
