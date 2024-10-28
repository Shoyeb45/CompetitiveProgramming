#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n;
vector<vector<int>> adj;

vector<int> calcSubordinate() {
    vector<int> ans(n + 1, 0);

    std:: function<void(int, int)> dfs = [&](int start, int prev) {
        ans[start] = 1;
        for(auto node: adj[start]) {
            if(node == prev) {
                continue;
            }
            dfs(node, start);

            ans[start] += ans[node];
        }
    };
    dfs(1, -1);
    return ans;
}

void solve() {
    cin >> n;
    adj.resize(n + 1);
    for(int i = 2, j; i <= n; i++) {
        cin >> j;
        adj[i].push_back(j);
        adj[j].push_back(i);
    }

    vector<int> ans = calcSubordinate();

    for(int i = 1; i < n + 1; i++) {
        cout << ans[i] - 1 << " ";
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
    // cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}