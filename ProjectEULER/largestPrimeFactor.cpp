#include<bits/stdc++.h>

using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;
#define MAX 1e5+1

auto init = []() { 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

vector<bool> prime(MAX, 1);
vector<ll> p;

void sieve() {
    prime[0] = prime[1] = 0;
    for(ll i = 2; i * i < MAX; i++) {
        if(prime[i]) {
            for(ll j = i * i; j < MAX; j += i) {
                prime[j] = 0;
            }
        }
    }
    for(ll i = 2; i < MAX; i++) {
        if(prime[i])
            p.push_back(i);
    }
    
}
ll n;

void solve() {
    n = 600851475143;
    for(int i = p.size() - 1; i >= 0; i--) {
        if(n % p[i] == 0) {
            cout << p[i];
            break;
        }
    }
}

int main() {
    int tt;
    tt = 1;
    cin >> tt;
    sieve();
    while (tt--) {
        solve();
    }
    
    return 0;
}
