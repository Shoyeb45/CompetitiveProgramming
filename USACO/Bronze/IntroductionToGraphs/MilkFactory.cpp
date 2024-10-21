#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n, m;
bool canWeReachTo(vector<int> adj[], int target, int src) {
    if(src == target) {
        return true;
    }
    if(adj[src].empty()) {
        return false;
    }
    for(auto node: adj[src]) {
        return canWeReachTo(adj, target, node);
    }
}

void solve() {
    cin >> n;
    m = n - 1;
    vector<int> adj[n + 1];
    while(m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for(int i = 1; i <= n; i++) {
        bool chk = 1;
        for(int j = 1; j <= n; j++) {
            if(i == j) {
                continue;
            }
            else {
                if(!canWeReachTo(adj, i, j)) {
                    chk = 0;
                    break;
                }
            }
        }

        if(chk) {
            cout << i << "\n";
            return;
        }
    }
    cout << -1 << '\n'; 
}

int main() {
    NFS
    // #ifndef ONLINE_JUDGE
    //     freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\input.in", "r", stdin);
    //     freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\output.out", "w", stdout);
    // #endif
        freopen("factory.in", "r", stdin);
        freopen("factory.out", "w", stdout);

    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solve();
    }


    return 0;
}