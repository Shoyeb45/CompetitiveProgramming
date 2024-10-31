#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n, k;
vector<vector<int>> adj;

void solve() {
    cin >> n >> k;
    adj.resize(n + 1);
    for(int i = 0, a, b, sA, sB; i < k; i++) {
        cin >> a >> b >> sA >> sB;
        if(sA > sB) {
            adj[a].push_back(b);
        }
        else {
            adj[b].push_back(a);
        }
    }    

    vector<bool> isCycle(n + 1, 0);

    for(int i = 1; i <= n; i++) {
        int curr = i;
        bool is = false;
        queue<int> q;
        q.push(curr);

        bool vis[n + 1] = {0};
        vis[curr] = 1;
        while(!q.empty()) {
            int x = q.front();
            q.pop();

            for(auto node: adj[x]) {
                if(node == curr) {
                    is = true;
                    break;
                }
                if(!vis[node]) {
                    vis[node] = true;
                    q.push(node);

                }
            }
        }    
        isCycle[i] = is;
    }

    cout << count(range(isCycle), true);
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