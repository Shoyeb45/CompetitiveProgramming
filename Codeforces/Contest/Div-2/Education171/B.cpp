#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n;
vector<ll> a;
void solve() {
    cin >> n;
    a.resize(n);
    for(auto &x: a) {
        cin >> x;
    }

    ll ans = 0;
    if(n % 2 == 0) {
        for(int i = 1; i < n; i += 2) {
            ans = max(ans, a[i] - a[i - 1]);
        }
    }
    else {
        ans = 1e18;
        for(int i = 0; i < n; i++) {
            for(auto x: {-1 , 1}) {
                ll res = 0;
                vector<ll> b = a;
                b.push_back(a[i] + x);
                sort(range(b));
                for(int i = 1; i < n + 1; i += 2) {
                    res = max(res, b[i] - b[i - 1]);
                }
                ans = min(ans, res);
            }
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