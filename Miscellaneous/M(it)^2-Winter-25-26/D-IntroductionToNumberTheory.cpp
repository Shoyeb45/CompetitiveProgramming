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

const unsigned long long INF = 1000000000000000005ULL; // 1e18 + 5
unsigned long long safe_lcm(long long a, long long b) {
    if (a == 0 || b == 0) return 0;
    unsigned long long g = std::gcd(a, b);
    // compute a/g * b but check overflow with INF cap
    __int128 tmp = (__int128)(a / g) * (__int128)b;
    if (tmp > (__int128)INF) return INF;
    return (unsigned long long)tmp;
}

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    sort(range(a));

    vector<ll> p_lcm(n + 1), s_gcd(n + 1);
    p_lcm[1] = a[1];
    for (int i = 2; i <= n; i++) {
        // lcm(a, b) * gcd(a, b) = a * b
        ll tmp = p_lcm[i - 1];
        ll g = __gcd(p_lcm[i - 1], a[i]);
        tmp = tmp * a[i] / g;
        // p_lcm[i] = safe_lcm(p_lcm[i - 1], a[i]);
        p_lcm[i] = tmp;
    }

    s_gcd[n] = a[n];
    for (int i = n - 1; i >= 1; i--) {
        s_gcd[i] = __gcd(s_gcd[i + 1], a[i]);
    }

    for (int i = 1; i <= n - 1; i++) {
        if (p_lcm[i] == 0) 
            continue;

        if (p_lcm[i] <= s_gcd[i + 1] && s_gcd[i + 1] % p_lcm[i] == 0) {
            cout << p_lcm[i] << "\n";
            return;
        }
    }
    cout << -1 << "\n";
}   



int main() {
    NFS
    #ifndef ONLINE_JUDGE
        freopen("/home/shoyeb45/Codes/CompetitiveProgramming/stdin-stdout-stderr/in.txt", "r", stdin);
        freopen("/home/shoyeb45/Codes/CompetitiveProgramming/stdin-stdout-stderr/out.txt", "w", stdout);
        freopen("/home/shoyeb45/Codes/CompetitiveProgramming/stdin-stdout-stderr/err.txt", "w", stderr);
    #endif
    int tt;
    tt = 1;
    cin >> tt;

    for (int i = 1; i <= tt; i++) {
        solve();
    }

    return 0;
}