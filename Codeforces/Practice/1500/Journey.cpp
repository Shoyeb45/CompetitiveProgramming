#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;
using ld = long double;
int n;
long double sum = 0;
vector<vector<int>> adj;

void dfs(int start, long double probability, int prev = -1, int dist = 0) {
    if(adj[start].size() == 1 && adj[start].front() == prev) {
        sum += probability * dist;
    }

    for(int node : adj[start]) {
        if(node != prev) {
            int x = adj[node].size() == 1 ? 1 : adj[node].size() - 1;
            dfs(node, probability / (ld)x, start, dist + 1);
        }
    }
}
void solve() {
    cin >> n;
    adj.resize(n + 1);
    for(int i = 0, a, b; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }    

    // for(auto x: adj[1]) {
        dfs(1, (1.0 / (adj[1].size())));
    // }

    cout << fixed << setprecision(20) << (sum ) << "\n";
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