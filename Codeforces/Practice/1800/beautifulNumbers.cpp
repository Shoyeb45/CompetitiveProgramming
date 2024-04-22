#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007; 

ll factorial(ll n, ll m) {
    if(n == 0 || n == 1)    return 1;
    ll temp = (n * 1LL * factorial(n - 1, m) % m) % m;

    return temp % m;    
}

ll power(ll a, ll b, ll m) {
    if(b == 0)  return 0;
    if(b == 1)  return a % m;

    ll temp = power(a, b/2, m) % m;
    temp = (temp * temp) % m;

    if(b % 2 == 1)  return (temp * a) % m;
    else return temp % m;
}

int main() {
    ll a, b , n;
    cin >> a >> b >> n;
    cout << power(a, b, mod);
    
}
