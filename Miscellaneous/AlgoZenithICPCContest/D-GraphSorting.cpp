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

    int get(int x) {
        if (parent[x] == x) {
            return x;
        }

        return parent[x] = get(parent[x]); 
    }

    void unite(int x, int y) {
        x = get(x), y = get(y);

        if (x == y) {
            return;
        }

        if (size[x] < size[y]) {
            swap (x, y);
        }
        size[x] += size[y];
        parent[y] = x;
    }

    bool checkSame(int x, int y) {
        return get(x) == get(y);
    }
};

class Edge {
public:
    int u, v, w;
    
    Edge (string i) {
        cin >> u >> v >> w;
    }

    Edge () {}
};

int n, m;
vector<int> p;
vector<Edge> edges;

bool check(int mid) {
    DSU dsu(n);

    for (auto e : edges) {
        if (e.w >= mid) {
            dsu.unite(e.u, e.v);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!dsu.checkSame(i, p[i])) {
            return false;
        }
    }
    return true;
}

void solve() {
    cin >> n >> m;

    p.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }    
    for (int i = 0; i < m; i++) {
        Edge e("in");
        edges.push_back(e);
    }

    bool sorted = 1;
    for (int i = 1; i <= n; i++) {
        if (p[i] != i) {
            sorted = 0;
            break;
        }
    }
    if (sorted) {
        cout << -1 << "\n";
        return;
    }
    
    int low = 1, high = 1e9, ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (check(mid)) {
            ans = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    cout << ans << '\n';
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