#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n, ans;

int dfs(int src, vector<int> adj[], string s) {
    int white = (s[src - 1] == 'B') ? -1: 1;
    if(adj[src].empty()) {
        return white;
    }
    for(auto x: adj[src]) {
        white += dfs(x, adj, s);
    }
    if(white == 0) {
        ans++;
    }
    return white;
}
void solve() {
    cin >> n;
    vector<int> adj[n + 2];

    for(int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        adj[x].push_back(i);
    }

    string s;
    cin >> s;
    ans = 0;
    dfs(1, adj, s);
    cout << ans << "\n";
}

int main() {
    NFS
    #ifndef ONLINE_JUDGE
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\input.in", "r", stdin);
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\output.out", "w", stdout);
    #endif

    int tt;
    tt = 1;
    cin >> tt;

    while (tt--) {
        solve();
    }


    return 0;
}