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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    vector<int> indegree(n + 1);

    auto outdegree = [&](int x) -> int {
        return (int) adj[x].size();
    }; 

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;        
    }

    for (int i = 2; i < n; i++) {
        if (indegree[i] != (int) outdegree(i)) {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }
    
    if ((outdegree(1) - indegree[1] != 1) || (outdegree(n) - indegree[n] != -1)) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    stack<int> st;
    st.push(1);

    vector<int> ans;
    while (!st.empty()) {
        int u = st.top();

        if (indegree[u] == 0 && outdegree(u) == 0) {
            ans.push_back(u);
            st.pop();
        } else {
            int v = adj[u].back();
            adj[u].pop_back();
            st.push(v);
            indegree[v]--;
        }
    }

    if (ans.size() != m + 1) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << " \n"[i == 0];
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