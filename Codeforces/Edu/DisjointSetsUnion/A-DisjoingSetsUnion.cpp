#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

class DisjointSetsUnion {
    private:
        vector<int> parent;
        vector<int> height;
    
    public: 
        DisjointSetsUnion(int n) {
            parent.resize(n), height.resize(n);
            for(int i = 0; i < n; i++) {
                parent[i] = i;
                height[i] = 0;
            }
        }
    

        void unite(int x, int y) {
            int root1 = get(x), root2 = get(y);

            if(height[root1] > height[root2]) {
                parent[root2] = root1;
                height[root1] = max(height[root1], height[root2] + 1);
            }
            else {
                parent[root1] = root2;
                height[root2] = max(height[root2], height[root1] + 1);
            }
        }

        int get(int x) {
            if(parent[x] != x) {
                return parent[x] = get(parent[x]);
            }
            return parent[x];
        }

        bool isConnected(int x, int y) {
            return get(x) == get(y);
        }

        void display() {
            cout << "Parents: " << "\n";
            for(auto x: parent) {
                cout << x << " ";
            }
            cout << "\n";

            cout << "Heights: " << "\n";
            for(auto x: height) {
                cout << x << " ";
            }
            cout << "\n";
        }
};

int n, m;
void solve() {
    cin >> n >> m;
    DisjointSetsUnion dsu(n);

    while(m--) {
        string s;
        int x, y;
        cin >> s >> x >> y;
        x-- ,y--;
        if(s == "union") {
            dsu.unite(x, y);
        }
        else {
            cout << (dsu.isConnected(x, y) ? "YES\n": "NO\n");
        }

        // dsu.display();
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