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

void solve(int tc) {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (ll &x: a) {
        cin >> x;
    }
    // sort(range(a));
    ll low = *min_element(range(a)), high = *max_element(range(a)) + 1;
    ll ans = 0;

    auto check = [&](ll mid) -> bool {
        vector<bool> vis(n, false);
        for (int i = 0; i < n; i++) {
            if (a[i] <= mid && !vis[i]) {
                int j = i + 1, k = i;
                vis[i] = true;
                while (j < n && llabs(a[j] - a[k]) <= mid && !vis[j]) {
                    vis[j] = true;
                    j++;
                    k++;
                }
                j = i - 1;
                k = i;
                while (j >= 0 && llabs(a[j] - a[k]) <= mid && !vis[j]) {
                    vis[j] = true;
                    j--, k--;
                }
            }
        }
        int chk = 0;
        for (bool x: vis) {
            chk += x;
        }
        // debug(chk == n);
        return chk == n;
    };

    while (low < high) {
        ll mid = low + (high - low) / 2;
        // debug(mid);
        if (check(mid)) {
            ans = mid;
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    cout << "Case #" << tc << ": " << ans << "\n";
}

int main() {
    NFS
    #ifndef ONLINE_JUDGE
        freopen("input_b.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\error.out", "w", stderr);
    #endif
    int tt;
    tt = 1;
    cin >> tt;

    for (int i = 1; i <= tt; i++) {
        solve(i);
    }

    return 0;
}