#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

class DisjointSetUnion {
    private:
        vector<int> parents;
        vector<int> height;

    public:
        DisjointSetUnion(int n) {
            parents.resize(n), height.resize(n);
            for(int i = 0; i < n; i++) {
                parents[i] = i;
                height[i] = 0;
            }
        }

        int find(int node) {
            if(parents[node] != node) {
                parents[node] = find(parents[node]);
            }
            return parents[node];
        } 

        void connect(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);

            if(height[rootX] > height[rootY]) {
                parents[rootY] = rootX;
                height[rootX] = max(height[rootX], height[rootY] + 1);
            }
            else {
                parents[rootX] = rootY;
                height[rootY] = max(height[rootY], height[rootX] + 1);
            }
        }

        bool isConnected(int x, int y) {
            return find(x) == find(y);
        }
};


void solve() {
    int n, q;
    cin >> n >> q;

    DisjointSetUnion dsu(n);

    while(q--) {
        int t, x, y;
        cin >> t >> x >> y;

        if(t == 0) {
            dsu.connect(x, y);
        }
        else {
            cout << dsu.isConnected(x, y) << "\n";
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