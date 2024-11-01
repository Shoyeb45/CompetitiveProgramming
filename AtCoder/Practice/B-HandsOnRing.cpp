#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n, q;

int steps(int from, int to, int x) {
    if(from > to) {
        swap(from, to);
    }

    if(x > from && x < to) {
        return n - (to - from);
    }
    else {
        return to - from;
    }
}

void solve() {
    cin >> n >> q;
    int l = 1, r = 2;
    ll ans = 0;

    
    while(q--) {
        char c;
        int t;
        cin >> c >> t;

        if(c == 'R') {
            ans += steps(r, t, l);
            r = t;
        }
        else {
            ans += steps(l, t, r);
            l = t;
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