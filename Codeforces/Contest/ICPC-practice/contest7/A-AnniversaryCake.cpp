#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int w, h, xa, ya, xb, yb;
void solve() {
    cin >> w >> h >> xa >> ya >> xb >> yb;

    ll dist = (1LL * (xa - xb) * (xa - xb)) + (1LL * (ya - yb) * (ya - yb));
    // debug("dist", dist);
    if(dist <= 2) {
        if(ya == yb || (1LL * (ya - yb) * (xa - xb) == -1)) {
            cout << min(xa, xb) << " " << 0 << " " << max(xa, xb)  << " " << h << "\n";
        }
        else if(xa == xb || (1LL * (ya - yb) * (xa - xb) == 1)) {
            cout << 0 << " " << max(ya, yb) << " " << w << " " << min(ya, yb)<< "\n";
        }
    }
    else {
        if(xa == xb) {
            cout << 0 << " " << max(yb, ya) - 1 << " " << w << " " << max(yb, ya) - 1 << "\n";
        }
        else {
            cout << max(xb, xa) - 1 << " " << 0 << " " << max(xb, xa) - 1 << " " << h << "\n";
        }
    }
}

int main() {
    NFS
    //  #ifndef ONLINE_JUDGE
    //     freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\input.in", "r", stdin);
    //     freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\output.out", "w", stdout);
    //     freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\error.out", "w", stderr);
    // #endif
        freopen("anniversary.in", "r", stdin);
        freopen("anniversary.out", "w", stdout);
    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}