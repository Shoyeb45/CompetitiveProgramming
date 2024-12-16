#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;


ll logbA(ll a, ll base) {
    return log2(a) / log2(base);
}

ll k, l_1, r_1, l_2, r_2;

void solve() {
    cin >> k >> l_1 >> r_1 >> l_2 >> r_2;

    ll n = logbA ((r_2 + l_1 - 1) / l_1, k) + 1;
    // cout << n << '\n';
    ll ans = 0;

    for (int i = 0; i <= n; i++) {

        ll slope = (ll)pow(k, i);
        // debug("slope", slope);
        if (slope * l_1 > r_2) {
            break;
        }

        ll low = l_1, high = r_1, ans_2 = -1;

        while (low <= high) {
            ll mid = low + (high - low) / 2;
            // debug("mid", mid);
            if (1LL * slope * mid <= r_2) {
                ans_2 = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        low = l_1, high = r_1;
        ll ans_3 = -1;
        while (low <= high) {
            ll mid = low + (high - low) / 2;
            // debug("mid", mid);
            if (1LL * slope * mid >= l_2) {
                ans_3 = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        // debug("low", ans_3, "high", ans_2);
        if (ans_3 >= l_1 && ans_3 <= r_1) {
            ans += (ans_2 - ans_3 + 1);
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