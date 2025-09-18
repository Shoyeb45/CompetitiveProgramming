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
const int MAX_N = (int)2e5 + 1;
int n;

int succ[MAX_N], len[MAX_N];
vector<int> pred[MAX_N];
bool vis[MAX_N];

void propagate_ans(int u, int cycle_len) {
    queue<pair<int, int>> q;
    q.push({u, 1});
    
    while (!q.empty()) {
        auto x = q.front();
        int u = x.first, dist = x.second;
        q.pop();

        for (int &v: pred[u]) {
            if (len[v] == -1) {
                len[v] = cycle_len + dist;
                q.push({v, dist + 1});
            } 
        }
    }
}

void dfs(int start) {
    vector<int> path;
    int cur = start;

    // Walk until we find a visited node
    while (!vis[cur]) {
        vis[cur] = true;
        path.push_back(cur);
        cur = succ[cur];
    }

    // Now cur is visited. Check if it's in current path → cycle found
    auto it = find(path.begin(), path.end(), cur);
    if (it != path.end()) {
        // Cycle detected
        int cycle_start_index = it - path.begin();
        int cycle_len = path.size() - cycle_start_index;

        // Set cycle nodes' len
        for (int i = cycle_start_index; i < path.size(); i++) {
            len[path[i]] = cycle_len;
        }

        // Propagate from each cycle node
        for (int i = cycle_start_index; i < path.size(); i++) {
            propagate_ans(path[i], cycle_len);
        }
    }
    // If cur is visited but not in current path, then no cycle in this component.
    // All nodes in path lead into a previously processed component.
    // Their answers will be set via propagation from elsewhere — nothing to do here.
}

void solve() {
    cin >> n;

    memset(len, -1, sizeof len);
    for (int i = 1; i <= n; i++) {
        pred[i].clear();
        vis[i] = false;
    }

    for (int i = 1; i <= n; i++) {
        cin >> succ[i];
        pred[succ[i]].push_back(i);
    }    

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }
   
    for (int i = 1; i <= n; i++) {
        cout << len[i] << " \n"[i == n];
    }
}

int main() {
    NFS
    #ifndef ONLINE_JUDGE
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\input.in", "r", stdin);
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\output.out", "w", stdout);
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\error.out", "w", stderr);
    #endif
    int tt = 1;
    while (tt--) {
        solve();
    }
    return 0;
}