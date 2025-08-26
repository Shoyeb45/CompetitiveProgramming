#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

class DSU {
public:
    vector<int> parent, size;

    DSU (int n) {
        parent.resize(n + 1), size.resize(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    int get (int x) {
        if (parent[x] == x) {
            return x;
        }

        return parent[x] = get (parent[x]);
    }

    void unite (int x, int y) {
        x = get(x), y = get(y);

        if (x == y) {
            return;
        }
        if (size[x] < size[y]) {
            swap(x, y);
        } 

        size[x] += size[y];
        parent[y] = x;
    }

    int getComponents (int n) {
        for (int i = 1; i <= n; i++) {
            get(i);
        }
        set<int> s;
        for (int i = 1; i <= n; i++) {
            s.insert(parent[i]);
        }
        return s.size();
    }
};

int n, m;
void solve() {
    cin >> n >> m;
    DSU dsu(n);
    
    while (m--) {
        int a, d, k;
        cin >> a >> d >> k;

        int prev = a;
        for (int i = 1; i <= k; i++) {
            int curr = a + d * i;
            dsu.unite(prev, curr);
            prev = curr;
        }
    }
    cout << dsu.getComponents(n) << "\n";
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