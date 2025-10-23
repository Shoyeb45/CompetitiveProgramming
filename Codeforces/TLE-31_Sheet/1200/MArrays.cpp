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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    map<int, int> mp;
    for (int &x: a) {
        cin >> x;
        mp[x % m]++;
    }   
    int ans = n;
    for (int i = 1; i <= m; i++) {
        if (mp.find(i) == mp.end()) {
            continue;
        }
        if (m % 2 == 0 && i == m / 2) {
            ans -= max(0, mp[i] - 1);
            continue;
        }
        int freq1 = mp[i], freq2 = mp[m - i];
        if (freq1 == freq2) {
            ans -= max(0, freq1 + freq2 - 1);
            mp.erase(i), mp.erase(m - i);
        } else {
            int mn = min(freq1, freq2);
            int total = 2 * mn + 1;
            ans -= max(0, total - 1);
            mp[i] -= mn, mp[m - i] -= mn;  
            if (mp[i] == 0) {
                mp.erase(i);
            }
            if (mp[m - i] == 0) {
                mp.erase(m - i);
            }
        }
    }
    ans -= max(0, mp[0] - 1);

    cout << ans << '\n';

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