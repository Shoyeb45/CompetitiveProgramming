#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n, x;
int bob = 0;
vector<vector<int>> adj;

ll dist[2][(int)(2e5 + 1)] = {0};

void dfs(int curr, int parent, int isAlice) {
    for(auto node: adj[curr]) {
        if(node != parent) {
            dist[isAlice][node] = dist[isAlice][curr] + 1;
            dfs(node, curr, isAlice);
        }
    }
}

void solve() {
    cin >> n >> x;
    adj.resize(n + 1);

    for(int i = 0, a = 0, b = 0; i < n - 1 ; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }   

    dfs(1, -1, 1);
    dfs(x, -1, 0);

    ll ans = 0;

    for(int i = 1; i <= n; i++) {
        if(dist[0][i] < dist[1][i]) {
            ans = max(ans, dist[1][i] * 2);
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