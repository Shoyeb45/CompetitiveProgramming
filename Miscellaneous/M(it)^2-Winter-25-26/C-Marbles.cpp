#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define rrange(x) (x).rbegin(), (x).rend()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    string ans = "";
    for (int i = 1; i <= n + 1; i++)
        ans += 'i';

    map<char, char> mp;
    mp['R'] = 'G';
    mp['G'] = 'R';
    
    vector<int> adj[n + 1];

    for (int i = 1; i <= n; i++) {
        adj[i].push_back(a[i]);
        // adj[a[i]].push_back(i);
    }

    vector<bool> vis(n + 1, false);

    std::function<void(int, int)> dfs = [&](int u, int p) -> void {
        vis[u] = true;
        for (int& v: adj[u]) {
            if (!vis[v]) {
                ans[v] = mp[ans[u]];
                dfs(v, u);
            } else if (v != p) {
                ans[v] = 'B';
            }
        }
    };

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            ans[i] = 'R';
            dfs(i, -1);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i];
    }
    cout << "\n";
}   



int main() {
    NFS
  
    int tt;
    tt = 1;
    cin >> tt;

    for (int i = 1; i <= tt; i++) {
        solve();
    }

    return 0;
}