#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

ll n;
void solve() {
    cin >> n;
    ll k = ((1LL * n * n) + 1) / 2;

    ll low = 1, high = 1LL * n * n;
    ll ans = -1;
    // debug("h", high);
    std::function<ll(ll)> cnt = [&](ll mid) {
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += min ((ll)n, mid / i);
        }
        return ans;
    };


    while (low <= high) {
        ll mid = low + (high - low) / 2;
        // cout << mid << "\n";
        if (cnt(mid) >= k) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
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
    // cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}