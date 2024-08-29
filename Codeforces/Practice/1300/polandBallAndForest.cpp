#include<bits/stdc++.h>

using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
#define range(x) (x).begin(), (x).end()
typedef long long ll;
const ll mod = 1000000007;

auto init = []() { 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

int n;
void dfs(int node, vector<int> adj[], vector<bool> &visited) {
    for(auto child: adj[node]) {
        if(!visited[child]) {
            visited[child] = 1;
            dfs(child, adj, visited);
        }
    }
}   
void solve() {
    cin >> n;
    vector<int> adj[n + 1];

    for(int i = 1; i < n + 1; i++) {
        int x;
        cin >> x;
        adj[i].push_back(x);
        adj[x].push_back(i);
    }

    vector<bool> visited(n + 1, 0);


    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            ans++;
            visited[i] = 1;
            dfs(i, adj, visited);
        }
    }
    cout << ans << "\n";
}

int main() {
    int tt;
    tt = 1;
    // cin >> tt;
    
    while (tt--) {
        solve();
    }
    
    return 0;
}
