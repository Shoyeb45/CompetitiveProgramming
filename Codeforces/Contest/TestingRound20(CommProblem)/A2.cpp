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



string convert_to_base_25(ll x) {
    string enc = string(9, 'a');
    if (x < 0) {
        enc[0] = 'b'; // means negative num
        x *= -1;
    }

    int idx = 8;

    while (x > 0) {
        int rem = x % 25;
        enc[idx--] = 'a' + rem;
        x /= 25;
    }
    return enc;
}

ll base_25_to_decimal(string x) {
    ll p = 1;
    ll ans = 0;
    reverse(range(x));
    for (int i = 0; i < 8; i++) {
        char ch = x[i];
        int x = ch - 'a';
        ans += p * x;
        p *= 25;
    }
    if (x.back() == 'b') {
        ans *= -1;
    }
    return ans;
}

void solve() {
    string s;
    cin >> s;
    if (s == "first") {
        int n;
        cin >> n;
        string s = "";
        while (n--) {
            ll x;
            cin >> x;
            string temp = convert_to_base_25(x);
            s += temp + 'z'; 
            debug(x, temp, base_25_to_decimal(temp));
        }
        cout << s << "\n";
    } else {
        vector<ll> ans;
        string t;
        cin >> t;
        string temp = "";
        for (char ch: t) {
            if (ch == 'z') {
                ans.push_back(base_25_to_decimal(temp));
                temp = "";
            } else {
                temp += ch;
            }
        }
        cout << ans.size() << "\n";
        for (ll x: ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
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
    // cin >> tt;

    for (int i = 1; i <= tt; i++) {
        solve();
    }

    return 0;
}