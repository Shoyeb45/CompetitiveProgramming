// UFPE Starters Final Try-Outs 2018

#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

void solve() {
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n), b(n), c(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }

    std::function<bool(ll)> check = [&](ll mid) {
        vector<pair<int, int>> vp;

        ll total = 0, totalCost = 0;

        for (int i = 0; i < n; i++) {
            if (a[i] > mid) {
                total += (a[i] - mid);
                totalCost += 1LL * (a[i] - mid) * b[i];
            }
            else if (a[i] < mid) {
                vp.push_back(make_pair(
                    c[i], a[i]
                ));
            }
        }

        sort(range(vp));

        for (auto x: vp) {
            if (total == 0) {
                break;
            }
            if (total > x.second) {
                total -= x.second;
                totalCost += (1LL * x.first * x.second);
            }
            else if (total <= x.second) {
                totalCost += (1LL * total * x.first);
                total = 0;
                break;
            }
        }

        return totalCost <= k;
    };

    ll low = 1, high = 1e18, ans = -1;
    while (low <= high) {
        ll mid = low + (high - low) / 2;

        if (check(mid)) {
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