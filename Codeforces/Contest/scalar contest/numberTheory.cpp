#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007; 

void generateDivisors(const vector<pair<ll, ll>>& primeFactors, vector<ll>& divisors, ll currentDivisor, int index = 0) {
    if (index == primeFactors.size()) {
        divisors.push_back(currentDivisor);
        return;
    }

    ll prime = primeFactors[index].first;
    ll power = primeFactors[index].second;

    for (int i = 0; i <= power; ++i) {
        generateDivisors(primeFactors, divisors, currentDivisor, index + 1);
        currentDivisor *= prime;
    }
}

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
            return temp % m;
        }
}

int main() {
    ll n;
    cin >> n;
    ll ans = 0;
    vector<pair<ll, ll>> primeFactors(n);
    for (int i = 0; i < n; ++i) {
        cin >> primeFactors[i].first >> primeFactors[i].second;
    }

    vector<ll> divisors;
    generateDivisors(primeFactors, divisors, 1);
    
    for(int i = 0; i < divisors.size(); i++) {
        ans += (power(divisors[i], 69, mod) % mod);
    }
    cout << ans << "\n";
}
