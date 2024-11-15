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
    vector<int> parent; 
    vector<int> size;
    vector<int> points;
    vector<int> extraPoints;

    DSU(int n) {
        size.resize(n, 1), points.resize(n), extraPoints.resize(n), parent.resize(n);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int get(int x) {
        if (parent[x] == x) {
            return x;
        }

        return get(parent[x]);
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
        extraPoints[y] = points[x];
    } 

    void add(int x, int pointss) {
        int t = get(x);
        points[t] += pointss;
    }

    int getPoints(int x) {
        int p = points[x];

        if (parent[x] == x) {
            return p;
        }

        p += getPoints(parent[x]) - extraPoints[x];
        return p;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;

    DSU dsu(n);
    while(q--) {
        string s;
        cin >> s;

        if (s == "join") {
            int x, y;
            cin >> x >> y;
            dsu.unite(--x, --y);
        }
        else if (s == "add") {
            int x, points;
            cin >> x >> points;
            dsu.add(--x, points);
        }
        else {
            int x;
            cin >> x;

            cout << dsu.getPoints(--x) << "\n";
        }
    }
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