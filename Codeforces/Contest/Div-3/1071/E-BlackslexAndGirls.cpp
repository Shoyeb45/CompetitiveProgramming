#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
#define range(x) (x).begin(), (x).end()
#define rrange(x) (x).rbegin(), (x).rend()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

void solve() {
    int n;
    ll x, y;
    string s;
    cin >> n >> x >> y >> s;

    vector<ll> p(n);
    for (auto& x: p) cin >> x;

    if (accumulate(range(p), 0LL) > x + y) {
        cout << "No\n";
        return;
    }
    // Now we know that sum(p) <= x + y

    vector<ll> a(n), b(n);

    for (int i = 0; i < n; i++) {
        if (s[i] == '0') a[i] = p[i];
        else b[i] = p[i];
    }

    ll sum_a = accumulate(range(a), 0LL);
    ll sum_b = accumulate(range(b), 0LL);


    for (int i = 0; i < n; i++) {
        ll mx = p[i] - (p[i] / 2 + 1);

        if (s[i] == '0') {
            if (sum_a > x) {
                ll need = sum_a - x;

                sum_a -= a[i], sum_b -= b[i];
                a[i] -= min(mx, need), b[i] += min(mx, need);
                sum_a += a[i], sum_b += b[i];
            }
            continue;
        }

        if (sum_b > y) {
            ll need = sum_b - y;

            sum_a -= a[i], sum_b -= b[i];
            a[i] += min(mx, need), b[i] -= min(mx, need);
            sum_a += a[i], sum_b += b[i];
        }
    }

    debug(a);
    debug(b);
    if (sum_a > x || sum_b > y) {
        cout << "No\n";
        return;
    }


    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            if (sum_a < x) {
                a[i] += x - sum_a;
                sum_a = x; 
            }

            if (sum_b < y) {
                ll mx = a[i] - b[i] - 1;
                ll need = y - sum_b;
                sum_b += min(need, mx);
                b[i] += min(need, mx);
            }
            continue;
        } 

        if (sum_b < y) {
            b[i] += y - sum_b;
            sum_b = y;
        }
        if (sum_a < x) {
            ll mx = b[i] - a[i] - 1;
            ll need = x - sum_a;
            sum_a += min(need, mx);
            a[i] += min(need, mx);
        }
    }

    
    if (sum_a != x || sum_b != y) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
}   



int main() {
    NFS
    #ifndef ONLINE_JUDGE
        freopen("/Users/keerthi/Codes/CompetitiveProgramming/stdin-stdout-stderr/in.txt", "r", stdin);
        freopen("/Users/keerthi/Codes/CompetitiveProgramming/stdin-stdout-stderr/out.txt", "w", stdout);
        freopen("/Users/keerthi/Codes/CompetitiveProgramming/stdin-stdout-stderr/err.txt", "w", stderr);
    #endif
    int tt;
    tt = 1;
    cin >> tt;

    for (int i = 1; i <= tt; i++) {
        solve();
    }

    return 0;
}