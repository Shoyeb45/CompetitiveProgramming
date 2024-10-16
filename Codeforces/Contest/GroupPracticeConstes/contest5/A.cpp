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
    vector<pair<int, int>> vp;
    for(int i = 0; i < m; i++) {
        int x, w;
        cin >> x >> w;
        vp.push_back({x, w});
    }
    sort(range(vp));
    ll sum = 0;
    for(int i = 0; i < m / 2; i++) {
        sum += vp[i].second + vp[m - i - 1].second;
    }
    // cout << sum << '\n';
    for(auto x: vp) {
        cout << x.first << " " << x.second << "\n";
    }
    cout << "\n";
}

int main() {
    NFS
    #ifndef ONLINE_JUDGE
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\input.in", "r", stdin);
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\output.out", "w", stdout);
    #endif

    int tt;
    tt = 1;
    cin >> tt;

    while (tt--) {
        solve();
    }


    return 0;
}