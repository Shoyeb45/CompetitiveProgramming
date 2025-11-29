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


int sum_of_digits(ll n) {
    ll x = n;
    int ans = 0;

    while (x) {
        int d = x % 10;
        x /= 10;
        ans = (ans + d) % 2;
    }
    return ans;
}
void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto& x: a) {
        cin >> x;
        x = sum_of_digits(x);
    }
    int ans1 = 0, ans2 = 0;

    int l_bit = 1;
    int i = 0;
    //  1 0 1 0...
    for (; i < n; i++) {
        if (a[i] == 1) break;
    }
    ans1 = (i < n);
    
    for (; i < n; i++) {
        if (a[i] == 1 - l_bit) {
            ans1++;
            l_bit = 1 - l_bit;
        } 
    } 
    i = 0;
    l_bit = 0;
    // 0 1 0 1
    for (; i < n; i++) {
        if (a[i] == 0) break;
    }

    ans2 = (i < n);
    
    for (; i < n; i++) {
        if (a[i] == 1 - l_bit) {
            ans2++;
            l_bit = 1 - l_bit;
        } 
    } 
    cout << max(ans1, ans2) << "\n";
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
    // cin >> tt;

    for (int i = 1; i <= tt; i++) {
        solve();
    }

    return 0;
}