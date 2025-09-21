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

    vector<int> adj[2 * m + 1], adj_t[2 * m + 1];    

    auto _negate = [&](int a) -> int {
        return a <= m ? a + m : a - m;
    };

    auto add_edge = [&](int a, bool n_a, int b, bool n_b) -> void {
        a = n_a ? _negate(a) : a;
        b = n_b ? _negate(b) : b;
        int not_a = _negate(a), not_b = _negate(b);
        
        // a V b, then edges:
        adj[not_b].push_back(a); // not b -> a
        adj[not_a].push_back(b); // not a -> b
        
        adj_t[b].push_back(not_a); 
        adj_t[a].push_back(not_b); 
    };
    
    for (int i = 0; i < n; i++) {
        char ch;
        int x;
        cin >> ch >> x;
        int a = x, n_a = ch == '-';
        cin >> ch >> x;
        int b = x, n_b = ch == '-';
        add_edge(a, n_a, b, n_b);
    }


    stack<int> st;
    vector<bool> vis(2 * m + 1);

    std::function<void(int)> dfs_1 = [&](int u) {
        vis[u] = true;
        for (int &v: adj[u]) {
            if (!vis[v]) {
                dfs_1(v);
            }
        }
        st.push(u);
    };

    for (int i = 1; i <= 2 * m; i++) {
        if (!vis[i]) {
            dfs_1(i);
        }
    }

    vector<int> compo(2 * m + 1);

    vis.assign(2 * m + 1, false);

    int scc = 0;
    std::function<void(int, int)> dfs_2 = [&](int u, int scc) {
        vis[u] = true;
        compo[u] = scc;
        for (int &v: adj_t[u]) {
            if (!vis[v]) {
                dfs_2(v, scc);
            }
        }
    };

    while (!st.empty()) {
        int u = st.top();
        st.pop();

        if (!vis[u]) {
            dfs_2(u, ++scc);
        }
    }


    vector<bool> ans(m + 1, false);
    for (int i = 1; i <= m; i++) {
        if (compo[i] == compo[_negate(i)]) {
            cout << "IMPOSSIBLE\n";
            return;
        }
        ans[i] = compo[i] > compo[_negate(i)];
    }

    for (int i = 1; i <= m; i++) {
        cout << (ans[i] ? '+' : '-') << " \n"[i == m];
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