#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

// Main idea
// I thought of Djikstra but the problem was to explore the finite path but still exploring all the valid k paths.
// For that we can keep count that how many times particular node is added in min heap.
// We'll keep processing for the node if that node didn't added k times.
// And if we find end vertex n, then we'll update the answer.
// As soon as we found k distances for n, we'll break the loop, as Djikstra will give  
// us smallest distances.

int n, m, k;
vector<vector<pair<int, ll>>> adj;

void solve() {
    cin >> n >> m >> k;
    adj.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, 1});

    vector<ll> ans;
    // taken[i] -> number of times ith node added in min heap
    vector<int> taken(n + 1, 0);

    while (!pq.empty()) {
        auto x = pq.top();
        pq.pop();
        ll d = x.first;
        int u = x.second;
        
        taken[u]++;

        if (n == u) {
            ans.push_back(d);
            if ((int) ans.size() == k) {
                break;
            }
        }

        if (taken[u] > k) {  // don't explore for any more path, k paths are done.
            continue;
        }
        
        for (auto node: adj[u]) {
            int v = node.first;
            ll w = node.second;
            pq.push({w + d, v});
        }
    }

    sort(range(ans));
    for (int i = 0; i < (int) ans.size(); i++) {
        cout << ans[i] << " \n"[i == k - 1];
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