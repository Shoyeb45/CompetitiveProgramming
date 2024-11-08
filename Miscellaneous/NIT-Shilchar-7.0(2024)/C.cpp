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
    for(auto &x : a) {
        cin >> x;
    }

    vector<ll> pref(n, 0), suff(n, 0);

    pref[0] = 0;
    for(int i = 1; i < n; i++) {
        if(abs(a[i] - a[i - 1]) > 1) {
            pref[i] = 0;
        }
        else {
            pref[i] += pref[i - 1] + 1;
        }
    }

    for (int i = n - 2; i >= 0; i--) {
        if (abs(a[i] - a[i + 1]) > 1) {
            suff[i] = 0;
        }
        else {
            suff[i] += suff[i + 1] + 1;
        }
    }

    ll ans = 0;

    for (int i = 0; i < n; i++) {
        ans = max(ans, pref[i] + suff[i] + 1);
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