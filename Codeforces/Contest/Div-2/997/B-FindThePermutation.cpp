#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

vector<set<int>> constructAdjList(vector<string> &a) {
    int n = a.size();
    vector<set<int>> adj(n + 1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == '1') {
                if (i > j) {
                    adj[j + 1].insert(i + 1);
                }
                else {
                    adj[i + 1].insert(j + 1);
                }
            }
        }
    }
    return adj;
}

void topologicalSortUtil(int v, vector<set<int>> &adj, vector<bool> &visited, stack<int> &st) {
    visited[v] = true;

    for (int i : adj[v]) {
        if (!visited[i]) {
            topologicalSortUtil(i, adj, visited, st);
        }
    }

    st.push(v);
}

vector<int> topologicalSort(vector<set<int>> &adj, int V) {
    vector<int> ans;
    stack<int> st;
    vector<bool> visited(V + 1, false);

    for (int i = 1; i <= V; i++) {
        if (!visited[i]) {
            topologicalSortUtil(i, adj, visited, st);
        }
    }

    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<string> a(n);
    for (auto &s: a) {
        cin >> s;
    }   
    vector<set<int>> adj = constructAdjList(a);

    vector<int> ans = topologicalSort(adj, n);
    if (ans.empty()) {
        for (int i = 1; i <= n; i++) {
            cout << i << " \n"[i == n];
        }
        return;
    }

    for (auto x : ans) {
        cout << x << " ";
    }
    cout << "\n";
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