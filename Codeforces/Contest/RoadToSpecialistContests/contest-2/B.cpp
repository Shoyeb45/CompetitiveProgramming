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
    string s;
    cin >> n >> s;

    vector<int> a;
    
    for (int i = 0; i < n; i++) {
        int j = i;
        while (j < n && s[j] == s[i]) j++;
        a.push_back(j - i);
        i = j - 1;
    }

    
    ll ans = n;
    for (int i = 0; i < a.size(); i++) {
        // if (i - 1 >= 0) ans += a[i - 1];
        if (i + 1 < a.size()) ans += a[i];
        if (i + 1 < a.size() && i - 1 >= 0) ans += a[i - 1];
    }
    cout << ans << "\n";
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