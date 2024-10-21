#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n, m;
void solve() {
    cin >> n >> m;
    vector<ll> a(n), b(m);
    for(auto &x: a) {
        cin >> x;
    }
    for(auto &x: b) {
        cin >> x;
    }

    ll a1 = 0, b1 = 0;

    for(int i = 0; i < n - 1; i++) {
        a1 += abs(a[i] - a[i + 1]);
    }
    for(int i = 0; i < m - 1; i++) {
        b1 += abs(b[i] - b[i + 1]);
    }

    cout << a1 + b1 << "\n";
}

int main() {
    NFS
    #ifndef ONLINE_JUDGE
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\input.in", "r", stdin);
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\output.out", "w", stdout);
    #endif

    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solve();
    }


    return 0;
}