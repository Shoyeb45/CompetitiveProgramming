#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n;
// taken from https://github.com/Shoyeb45/DataStructureAndAlgorithm/blob/main/Algorithms/Graph/DSU/DisjointSetUnion.cpp, my implementation
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
    cin >> n;

    map<int, vector<int>> mp;
    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++) {
        int k; 
        cin >> k;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            a[i].push_back(x);
            mp[x].push_back(i);
        }
    }

    vector<pair<pair<int, int>, int>> vp;

    DisjointSetUnion dsu(n);

    for (int i = 0; i < n; i++) {
        bool ok = false;
        for (int x: a[i]) {
            if (a[i].size() == 1 && mp[x].size() == 1) {
                cout << "impossible\n";
                return;
            }
            bool ok1 = false; 
            for (auto idx: mp[x]) {
                if (idx != i && !dsu.isConnected(idx, i)) {
                    dsu.connect(idx, i);
                    vp.push_back({{idx, i}, x});
                    if (vp.size() == n - 1) {
                        ok1 = true;
                        break;
                    }
                }
            }
            if (ok1) {
                ok = true;
                break;
            }
        }
        if (ok) {
            break;
        }
    }


    for (int i = 0; i < vp.size(); i++) {
        cout << vp[i].first.first + 1 << " " << vp[i].first.second + 1 << " " << vp[i].second << "\n";
    }
    cout << "\n";
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