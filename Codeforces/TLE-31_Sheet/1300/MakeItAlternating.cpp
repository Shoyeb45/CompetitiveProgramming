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
const ll mod = 998244353;
const int N = 2e5 + 1;

ll factorial[N];

void compute_factorial() {
    fill(factorial, factorial + N, 0);
    factorial[0] = factorial[1] = 1;
    for (int i = 2; i < N; i++) {
        factorial[i] = (ll)i * factorial[i - 1] % mod;
    }
}
void solve() {
    string s;
    cin >> s;
    int freq = 1;
    char ch = s[0];
    ll mn_op = 0, ways = 1;

    for (int i = 1; i < s.size(); i++) {
        if (s[i] == ch) {
            freq++;
        } else {
            mn_op += freq - 1;
            ways = ways * freq % mod;
            freq = 1;
            ch = s[i];
        }
    }

    mn_op += freq - 1;
    ways = ways * freq % mod;

    ways = ways * factorial[mn_op] % mod;

    cout << mn_op << " " << ways << "\n";
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
    compute_factorial();
    while (tt--) {
        solve();
    }

    return 0;
}