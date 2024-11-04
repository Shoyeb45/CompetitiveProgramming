#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n, m, q;

int dx[] = {-1, +1, 0, 0};
int dy[] = {0, 0, -1, +1};
void solve() {
    cin >> n >> m >> q;

    vector<set<int>> g1(n), g2(m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            g1[i].insert(j);
            g2[j].insert(i);
        }
    }

    std::function<void(int, int)> erase = [&](int x, int y) {
        g1[x].erase(y);
        g2[y].erase(x);
    };

    for (int i = 0, x, y; i < q; i++) {
        cin >> x >> y;
        x--, y--;

        auto it1 = g1[x].lower_bound(y);
        if (it1 != g1[x].end() && *it1 == y) {
            erase(x, y);
            continue;
        }

        // left 
        auto it = g1[x].lower_bound(y);
        if (it != g1[x].begin()) {
            erase(x, *prev(it));
        }

        // right
        it = g1[x].lower_bound(y);
        if (it != g1[x].end()) {
            erase(x, *it);
        }

        // up
        it = g2[y].lower_bound(x);
        if(it != g2[y].begin()) {
            erase(*prev(it), y);
        }

        // down
        it = g2[y].lower_bound(x);
        if(it != g2[y].end()) {
            erase(*it, y);
        }
    }

    int ans = 0;

    for(auto x: g1) {
        ans += x.size();
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