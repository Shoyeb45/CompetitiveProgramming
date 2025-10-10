#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "algo/debug.h"
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

void solve() {
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x]++;
    }   

    vector<int> freq;
    for (auto x: mp) {
        freq.push_back(x.second);
    }
    sort(range(freq));
    // debug(freq);
    vector<ll> suff(freq.size() + 1);
    for (int i = freq.size() - 1; i >= 0; i--) {
        suff[i] = suff[i + 1] + freq[i];
    }
    ll pref = 0;
    // debug(suff);
    
    ll ans = INT_MAX;
    for (int i = 0; i < freq.size(); i++) {
        if (i + 1 < freq.size() && freq[i] == freq[i + 1]) {
            int j = i;
            while (j < freq.size() && freq[j] == freq[i]) {
                j++;
            }
            int f = j - i;
            i = j - 1;
            // debug(f, pref, suff[j], freq[i], j);
            // debug(pref + (suff[j] - freq[i] * (freq.size() - j)));
            ans = min(ans, pref + (suff[j] - freq[i] * (freq.size() - j)));
            pref += freq[i] * f;
        } else {
            // debug(pref + suff[i + 1] - freq[i] * (freq.size() - i - 1));
            ans = min(ans, pref + suff[i + 1] - freq[i] * (freq.size() - i - 1));
            pref += freq[i];
        }
    }
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

    while (tt--) {
        solve();
    }

    return 0;
}