#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n, k, ans;
vector<set<int>> adj;
set<int> v;


void solve() {
    cin >> n >> k;
    adj.resize(n + 1);
    for(int i = 0, a, b; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }    
    ans = n;
    for(int i = 0, x; i < k; i++) {
        cin >> x;
        v.insert(x);
    }

    vector<int> vertices;
    for(int i = 1; i <= n; i++) {
        if(adj[i].size() == 1) {
            vertices.push_back(i);
        }
    }    

    for(int i = 0; i < vertices.size(); i++) {
        int vertex = vertices[i];

        if(v.find(vertex) == v.end()) {
            ans--;
            int i = *adj[vertex].begin();
            adj[i].erase(vertex);
            if(adj[i].size() == 1) {
                vertices.push_back(i);
            }
        } 
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