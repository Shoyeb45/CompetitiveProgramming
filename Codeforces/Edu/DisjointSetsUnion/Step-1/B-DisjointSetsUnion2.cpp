#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;


class DisjointSetUnion {
public:
    vector<int> size;
    vector<int> parent;
    vector<int> mx;
    vector<int> mn;

    DisjointSetUnion(int n) {
        size.resize(n, 1), parent.resize(n), mx.resize(n), mn.resize(n);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
            mx[i] = mn[i] = i;
        }
    }

    int get(int x) {
        if(parent[x] == x) {
            return parent[x];
        }

        return parent[x] = get(parent[x]);
    }

    void unite(int x, int y) {
        int parentX = get(x), parentY = get(y);

        if (parentX == parentY) {
            return;
        }
        if (size[parentX] >= size[parentY]) {
            parent[parentY] = parentX;
            mx[parentX] = max (mx[parentX], mx[parentY]);
            mn[parentX] = min (mn[parentX], mn[parentY]);
            size[parentX] += size[parentY];
        }
        else {
            parent[parentX] = parentY;
            mx[parentY] = max (mx[parentY], mx[parentX]);
            mn[parentY] = min (mn[parentY], mn[parentX]);
            size[parentY] += size[parentX];
        }
    }

    bool checkSame(int x, int y) {
        return get(x) == get(y);
    }

    void disp() {
        cout << "Size\n";
        for (int i = 0; i < size.size(); i++) {
            cout << size[i] << " ";
        }
        cout << "\n";
    }
};

void solve() {
    int n, m;
    cin >> n >> m;

    DisjointSetUnion dsu(n);

    while(m--) {
        string s;
        cin >> s;

        if (s == "get") {
            int x;
            cin >> x;
            x--;
            x = dsu.get(x);
            cout << dsu.mn[x] + 1 << " " << dsu.mx[x] + 1 << " " << dsu.size[x] << "\n";
        }
        else {
            int x, y;
            cin >> x >> y;
            x--, y--;
            dsu.unite(x, y);
        }
    }    
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