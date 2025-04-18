#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n, q;
void solve() {
    cin >> n;
    vector<int> adj[n + 1];
    for(int i = 1, a, b; i <= n - 1; i++) {
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cin >> q;
    vector<int> numOfLeaves(n + 1, 0);

    std::function<void(int, int)> dfs = [&](int start, int prev) {
        // Leaf Node
        if(adj[start].size() == 1 && adj[start].front() == prev) {
            numOfLeaves[start] = 1;
        }

        for(int node : adj[start]) {
            if(node != prev) {
                dfs(node, start);
                numOfLeaves[start] += numOfLeaves[node];
            }
        }
    };

    dfs(1, -1);

    while(q--) {
        int a, b;
        cin >> a >> b;
        cout << (ll)(1LL * numOfLeaves[a] * numOfLeaves[b]) << "\n";
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
    cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}