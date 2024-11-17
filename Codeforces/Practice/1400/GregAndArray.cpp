#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n, m, k;
void solve() {
    cin >> n >> m >> k;
    vector<ll> a(n);
    for (auto &x : a) {
        cin >> x;
    }

    vector<vector<ll>> queries(m, vector<ll> (3, 0));
    for (auto &x: queries) {
        for (auto &y: x) {
            cin >> y;
        }
    }

    vector<ll> count(m + 1, 0);
    for (int i = 0, x, y; i < k; i++) {
        cin >> x >> y;
        count[--x]++;
        count[y]--;
    }

    for (int i = 1; i < m; i++) {
        count[i] += count[i - 1];
    }
    vector<ll> prefix(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int l = queries[i][0], r = queries[i][1];
        ll val = 1LL * queries[i][2] * count[i];
        prefix[--l] += val;
        prefix[r] -= val;
    }   

    for (int i = 1; i < n; i++) {
        prefix[i] += prefix[i - 1];
    }

    for (int i = 0; i < n; i++) {
        cout << (ll)(a[i] + prefix[i]) << " \n"[i == n - 1];
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
    // cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}