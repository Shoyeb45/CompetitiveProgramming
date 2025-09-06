#include <bits/stdc++.h>
using namespace std;
using ll = long long;

pair<ll, ll> merge(pair<ll, ll> &p1, pair<ll, ll> &p2) {
    pair<ll, ll> ans = make_pair(min(p1.first, p2.first), max(p1.second, p2.second));
    return ans; 
}

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    int strange_idx = -1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] != -1 && a[i] != 1) {
            strange_idx = i;
        }
    }
    

    vector<ll> prefix(n + 1);
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + a[i - 1];
    }

    auto work = [&](int i, int j) -> pair<ll, ll> {
        ll mx = INT_MIN, mn = INT_MAX;
        ll mx_pref = prefix[i - 1], mn_pref = prefix[i - 1];
        for (int k = i; k <= j; k++) {
            mx = max(mx, prefix[k] - mn_pref);
            mn = min(mn, prefix[k] - mx_pref);
            mx_pref = max(mx_pref, prefix[k]);
            mn_pref = min(mn_pref, prefix[k]);
        }
        return make_pair(mn, mx);
    };


    set<ll> ans;
    ans.insert(0);
    if (strange_idx == -1) {
        auto d = work(1, n);
        for (ll i = d.first; i <= d.second; i++) {
            ans.insert(i);
        }
    } else {
        auto left = work(1, strange_idx);
        auto right = work(strange_idx + 2, n);
        auto d = merge(left, right);
        // get all the sum with +1 or -1
        for (ll x = d.first; x <= d.second; x++) {
            ans.insert(x);
        }
        ll mn1 = 0, mx1 = 0, mn2 = 0, mx2 = 0;
        ll sum = 0;
        for (int i = strange_idx - 1; i >= 0; i--) {
            sum += a[i];
            mn1 = min(mn1, sum), mx1 = max(mx1, sum);
        }
        sum = 0;
        for (int i = strange_idx + 1; i < n; i++) {
            sum += a[i];
            mn2 = min(mn2, sum), mx2 = max(mx2, sum);
        }
        ll strange_ele = a[strange_idx];
        for (ll x = strange_ele + mn1 + mn2; x <= strange_ele + mx1 + mx2; x++) {
            ans.insert(x);
        }
    }

    cout << ans.size() << "\n";
    for (auto x: ans) {
        cout << x << " ";
    }
    cout << "\n";

}


int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}
