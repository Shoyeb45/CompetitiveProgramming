#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n, k;
vector<int> a, b;
void solve() {
    cin >> n >> k;
    a.resize(n), b.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (auto &x: b) {
        cin >> x;
    }

    int ans = INT_MAX;

    for (int i = 0; i < n; i++) {
        ans = min (ans, b[i] / a[i]);
    }

    for (int i = 0; i < n; i++) {
        b[i] = max(0, b[i] - a[i] * ans); 
    }

    while (k) {
        for (int i = 0; i < n; i++) {
            if (b[i] < a[i]) {
                int needed = a[i] - b[i];
                if(k >= needed) {
                    b[i] += needed;
                    b[i] -= a[i];
                    k = max (0, k - needed);
                }
                else {
                    cout << ans << "\n";
                    return;
                }
            }
            else {
                b[i] -= a[i];
            }
        }
        ans++;
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