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
    cin >> n;
    n -= 4;
    if(n < 34) {
        cout << "NO\n";
        return;
    }

    for(int a = 1; a < p.size(); a++) {
        ll x = p[a] * p[a];
        if(x > n)
            break;
        ll y = n - x;
        if(y <= 0)
            continue;
        ll ys = sqrt(y);
        // cout << "Y: " << y << '\n';
        if(binary_search(p.begin(), p.end(), ys) && ys * ys == y && ys != p[a]) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
    return;
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
