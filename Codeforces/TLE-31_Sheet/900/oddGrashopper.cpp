
#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int mod(int x) {
    return x >= 0 ? x : -1 * x;
}

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        ll x, n;
        cin >> x >> n;
        ll ans = 0;
        if(n % 4 == 1)  ans = -n;
        else if(n % 4 == 2) ans = 1;
        else if(n % 4 == 3) ans = n + 1;
        else    ans = 0;

        if(x == 0)  cout << ans << "\n";
        else if(mod(x) % 2 == 1) cout << x - ans << '\n';
        else if(mod(x) % 2 == 0)    cout << x + ans << '\n';
    }
}
