#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int dx[] = {2, 1, -1, -2, -2, -1, 1,   2};
int dy[] = {1, 2,  2,  1, -1, -2, -2, -1};

int n, m;
void solve() {
    map<pair<ll, ll>, bool> dangerCell; 
    cin >> n >> m;
    ll ans = 1LL * n * n;
    ll cnt = 0;

    while(m--) {
        ll x, y;
        cin >> x >> y;
        dangerCell[{x, y}] = true;

        for(int i = 0; i < 8; i++) {
            ll nx = dx[i] + x, ny = dy[i] + y;
            if(nx >= 1 && ny >= 1 && nx <= n && ny <= n) {
                dangerCell[{nx, ny}] = true;        
            }
        }
    }
    ans -= static_cast<ll> (dangerCell.size());
    cout << (ll)(ans) << "\n";
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