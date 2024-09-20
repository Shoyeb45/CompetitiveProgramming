#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n, m;
int ans;

void dfs(vector<int> adj[], int cnt, int curr, int prev, vector<bool> &cat) {
    cnt += cat[curr];
    // cout << "curR: " << curr << " " << cnt << "\n";
    if(adj[curr].size() == 1 && prev == adj[curr].back() && cnt <= m) {
        ans++;  
    }
    if(!cat[curr]) {
        cnt = 0;
    }
    for(auto node: adj[curr]) {
        if(prev != node && cnt <= m) {
            dfs(adj, cnt, node, curr, cat);
        }
    }
}

void solve() {
    cin >> n >> m;
    vector<bool> cats(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        cats[i] = a;
    }

    vector<int> adj[n + 1];

    for(int i = 1; i <= n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b); 
        adj[b].push_back(a); 
    }

    ans = 0;
    dfs(adj, 0, 1, -1, cats);
    cout << ans << '\n';
}

int main() {
    NFS
    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}
