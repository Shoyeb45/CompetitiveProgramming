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

    int freq[26];
    fill(freq, freq + 26, 0);

    for (char ch: s) {
        freq[ch - 'a']++;
    }
    set<pair<int, int>> st;
    for (int i = 0; i < 26; i++) {
        st.insert({freq[i], (char) i + 'a'});
    }

    int ans = INT_MAX;

    for (auto p: st) {
        int l = (n / 2) - 1, r = (n / 2) + n % 2;
        int temp = 0;
        bool ok = true;
        
        for (int i = 0, j = n - 1; i < j; ) {
            if (s[i] == s[j]) {
                i++, j--;
                continue;
            }
            if (s[i] != p.second && s[j] != p.second) {
                ok = false;
                break;
            }
            if (s[i] == p.second) {
                i++;
            } 
            if (s[j] == p.second) {
                j--;
            }
            temp++;
        }

        if (ok) {
            ans = min(ans, temp);
        }
    }

    cout << (ans == INT_MAX ? -1: ans) << "\n";
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

    while (tt--) {
        solve();
    }

    return 0;
}