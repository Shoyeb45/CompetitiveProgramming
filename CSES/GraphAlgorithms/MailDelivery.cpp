#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using max_heap = priority_queue<T>;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;


// Here, we had to find the euler path, 
// Read: https://cp-algorithms.com/graph/euler_path.html

int n, m;
void solve() {
    cin >> n >> m;
    vector<set<int>> adj(n + 1);
    vector<ll> deg(n + 1, 0);
    int k = m;
    while (k--) {
        int a, b;
        cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
        deg[a]++, deg[b]++;
    }

    for (int i = 1; i <= n; i++) {
        if ((deg[i] % 2 == 1)) {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }

    stack<int> st;
    st.push(1);

    vector<int> ans;
    while (!st.empty()) {
        int u = st.top();

        int v = adj[u].begin() != adj[u].end() ? *adj[u].begin() : n + 1;
        
        if (v == n + 1) {
            ans.push_back(u);
            st.pop();
        } else {
            adj[u].erase(v);
            adj[v].erase(u);
            st.push(v);
        }
    }

    if (ans.size() != m + 1) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " \n"[i == ans.size() - 1];
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