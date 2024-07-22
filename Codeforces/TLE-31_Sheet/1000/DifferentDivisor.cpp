#include<bits/stdc++.h>
using namespace std;

#define loop(i, n) for(int i = 0; i < n; i++)
#define range(x) (x).begin(), (x).end()
typedef long long ll;
const ll mod = 1000000007;
#define MAX 1e6

auto init = []() { 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

vector<bool> isPrime(MAX, 1);
vector<int> prime;

void sieve() {
    isPrime[1] = isPrime[0] = 0;
    for(ll i = 2; i < MAX; i++) {
        if(isPrime[i]) {
            prime.push_back(i);
            for(ll j = 2 * i; j < MAX; j += i) {
                isPrime[j] = 0;
            }
        }
    }   
}

void solve() {
    int d;
    cin >> d;
    ll p = 0;
    for(int i = d + 1; ; i++) {
        if(isPrime[i]) {
            p = i;
            break;
        }
    }

    ll q = 0;
    for(int i = d + p; ; i++) {
        if(isPrime[i]) {
            q = i;
            break;
        }
    }
    ll ans = min(1LL * p * p * p, 1LL * p * q);
    cout << ans << '\n';
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
