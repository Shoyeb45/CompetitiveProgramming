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
    
    int freq[10];
    fill(freq, freq + 10, 0);
    int idx = 0;
    while (n--) {
        freq[s[idx] - '0']++;
        idx = (idx + 1) % s.size();
    }
    int mx = INT_MIN, mn = INT_MAX;
    for (char ch : s) {
        int i = ch - '0';
        mx = max(freq[i], mx), mn = min(mn, freq[i]);
    }
    cout << mx << " " << mn << "\n";
}

int main() {
    NFS
    #ifndef ONLINE_JUDGE
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\input.in", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\error.out", "w", stderr);
    #endif
    int tt;
    tt = 1;
    cin >> tt;

    for (int i = 1; i <= tt; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}