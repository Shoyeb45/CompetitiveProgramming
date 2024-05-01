#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

bool isPrime(ll x, ll i) {
    if(x < 2)
        return 0;

    if(i * i > x) {
        return 1;
    }
    if(x % i == 0)  return 0;

    return isPrime(x, i+1);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        ll n; cin >> n;
        if(isPrime(n, 2))
            cout << "Prime Number\n";
        else
            cout << "Not a prime number\n";
    }
    
    return 0;
}
