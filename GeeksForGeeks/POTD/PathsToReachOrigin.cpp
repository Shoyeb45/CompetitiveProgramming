#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const long long mod = 1000000007;


ll facto(ll n) {
    if(n == 0 || n == 1)
        return 1;
    
    return ((n % mod) * (facto(n - 1) % mod)) % mod;
}


ll moduloPow(ll n, ll b, ll p) {
    if(b == 1)
        return n % p;
    if(b == 0)
        return 1;

    ll temp = moduloPow(n, b/2, p) % p;
    temp = (temp * temp) % p;

    if( b % 2 == 1)
        return (temp * (n % p)) % p;
    else 
        return temp;
}

ll modInverse(ll n, ll p) {
    return moduloPow(n, p - 2, p);
}

ll combination(ll n, ll r, ll p) {
    if(n < r)
        return 0;
    if(n == r)
        return 1;

    return (facto(n) % p * modInverse(facto(n - r), p) % p * modInverse(facto(r), p) % p) % p;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y;
    cin >> x >> y;

    cout << combination((ll)(x + y), (ll)(x), mod) << "\n";
   

    return 0;
}
