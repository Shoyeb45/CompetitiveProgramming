#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll m  = 1e9+7;

ll power(ll b, ll p, ll m){
        if(p == 0)
        return 1;
        if(p == 1)
        return b % m;
        ll temp = power(b, p/2, m) % m;

        temp = (temp * temp) % m;
        if(p % 2 == 1){
            return (temp * b) % m;
        }else{
            return temp ;
        }
    }



int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int a, b, c;
        cin >> a >> b >> c;
        
  
        ll p = power(b, c, m - 1);
        
        ll ans = power(a, p, m);
        printf("%lld\n", ans);
        
    }
}