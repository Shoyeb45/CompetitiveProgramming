#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n;
void solve() {
    cin >> n;
    vector<int> adj[n + 1];
    for(int i = 0, a, b; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> nodeColor(n + 1, 0);  // Color of node, we can do without it also
    vector<bool> vis(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            queue<int> q;
            q.push(i);

            
            nodeColor[i] = 1; // Color first node
            vis[i] = 1; // Mark as visited
            while(!q.empty()) {
                int x = q.front();
                q.pop();

                for(auto node: adj[x]) {
                    if(!vis[node]) {
                        vis[node] = 1;
                        nodeColor[node] = !nodeColor[x]? 1: 0; // Mark according to parent node
                        q.push(node);
                    }
                }
            }
        }
    } 

    // --------------- IGNORE -------------------------
    // set<int> st[2];
    // for(int i = 1; i <= n; i++) {
    //     st[nodeColor[i]].insert(i);
    // }

    // ll ans = 0;
    // for(auto it: st[0]) {
    //     int temp = 0;
    //     for(auto node: adj[it]) {
    //         if(st[1].find(node) != st[1].end()) {
    //             temp++;
    //         }
    //     }
    //     ans += (ll)(st[1].size() - temp);
    // }
    // --------------------------------------------------

    ll color[2] = {0};  // Number of nodes with 0 or 1 color
    for(int i = 1; i <= n; i++) {
        color[(int)(nodeColor[i])]++;
    }

    // Output final answer, i.e., n_r * n_b  - (n - 1)
    cout << (ll)(1LL * color[0] * color[1] - (n - 1)) << "\n";
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