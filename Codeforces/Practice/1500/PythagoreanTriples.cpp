#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include <algo/debug.h>
#else
#define debug(...) 42
#endif
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using max_heap = priority_queue<T>;
const ll mod = 1000000007;

vector<ll> cs;
void solve() {
    ll n;
    cin >> n;
    
    int ans = upper_bound(range(cs), n) - cs.begin();
    cout << ans << "\n";
}

int main() {
    NFS
    #ifndef ONLINE_JUDGE
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\input.in", "r", stdin);
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\output.out", "w", stdout);
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\error.out", "w", stderr);
    #endif
    int tt;
    tt = 1;
    cin >> tt;
    int n = 1e9;
    for (ll x = 2; ; x++) {
        ll a2 = 1LL * x * x;
        
        if ((a2 - 1) % 2 == 0) {
            ll b = (a2 - 1) / 2;
            if (1 + b > n) {
                break;
            }
            cs.push_back(1 + b);
        }
    }

    while (tt--) {
        solve();
    }

    return 0;
}