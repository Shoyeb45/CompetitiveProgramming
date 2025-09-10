#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;


int n, m;
vector<vector<pair<int, ll>>> adj;

// IMP: in cpp, for equal elements compartor should always return false
// If we don't implement this, then we might get MLE or TLE 
struct cmp {
    bool operator()(pair<ll, int> &p1, pair<ll, int> &p2) {
        return p1.first > p2.first;
    }
};

void solve() {
    cin >> n >> m;
    adj.resize(n + 1);
    while (m--) {
        int a, b;
        ll w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
    }

    
    priority_queue<
        pair<ll, int>, 
        vector<pair<ll, int>>, 
        cmp
    > pq;

    pq.push({0, 1});
    vector<ll> dist(n + 1, LLONG_MAX);
    dist[1] = 0;

    while (!pq.empty()) {
        pair<ll, int> p = pq.top();
        int u = p.second;
        pq.pop();

        // IMP: Remove stale nodes, this condition means it's not updated
        if (p.first != dist[u]) {
            continue;
        }
        for (auto x: adj[u]) {
            int v = x.first;
            ll w = x.second;

            if ((ll)(dist[u] + w) < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << "\n";
}

int main() {
    NFS
     #ifndef ONLINE_JUDGE
        freopen("C:\\Users\\SHOYEB ANSARI\\Downloads\\test_input.txt", "r", stdin);
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