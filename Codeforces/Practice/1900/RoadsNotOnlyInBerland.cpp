#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

vector<set<int>> adj;
vector<pair<int, int>> delEdge;
vector<int> addEdge;
vector<bool> vis;
map<pair<int, int> , bool> mp;
int n;

void bfs(int start) {
    queue<pair<int, int>> q;
    q.push({start, -1});

    while (!q.empty()) {
        int currNode = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto node : adj[currNode]) {
            if (!vis[node]) {
                vis[node] = 1;
                q.push({node, currNode});
            }
            else if (node != parent && mp.find({node, currNode}) == mp.end() && mp.find({currNode, node}) == mp.end()) {
                delEdge.push_back({node, currNode});
                mp[{node, currNode}] = true;
                mp[{currNode, node}] = true;
            }
        }
    }
}
void solve() {
    cin >> n;
    adj.resize(n + 1);

    for (int i = 0, a, b; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    
    vis.resize(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            bfs(i);
            addEdge.push_back(i);
        }
    }

    cout << addEdge.size() - 1 << "\n";

    for (int i = 1; i < addEdge.size(); i++) {
        cout << delEdge[i - 1].first << " " << delEdge[i - 1].second << " " << addEdge[0] << " " << addEdge[i] << "\n";
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