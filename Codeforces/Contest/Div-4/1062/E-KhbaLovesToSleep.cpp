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
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n);
    for (int &x: a) {
        cin >> x;
    }   
    a.push_back(1e9);
    a.push_back(-1e9);
    
    sort(range(a));
    n += 2;

    auto check = [&](ll mid) -> bool {
        ll cnt = 0;
        a[0] = -mid, a[n - 1] = x + mid;
        for (int i = 1; i < n; i++) {
            cnt += max(0LL, (a[i] - mid) - (a[i - 1] + mid) + 1);
        }
        a[0] = -1e9, a[n - 1] = 1e9;
        return cnt >= k;
    };

    ll low = 0, high = 1e10;
    ll ans = -1;
    while (low < high) {
        ll mid = (low + high) >> 1;
        debug(low, high);
        if (check(mid)) {
            debug(mid);
            low = mid + 1;
            ans = mid;
        } else {
            high = mid;
        }
    }

    int p = 0;
    a[0] = -ans, a[n - 1] = ans + x;

    set<int> st;
    for (int i = 1; i < n; i++) {
        int low = a[i - 1] + ans, high = a[i] - ans;
        for (int t = low; t <= high; t++) {
            if (st.find(t) == st.end()) {
                cout << t << " ";
                st.insert(t);
                p++;
            } 
            if (p >= k) {
                cout << "\n";
                return;
            }
        }
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
    cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}