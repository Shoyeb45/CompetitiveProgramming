#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

vector<vector<int>> adj;
int n, m;

void solve() {
    cin >> n >> m;
    adj.resize(n + 1);

    for(int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int a = 0, b = 0, c = 0;

    for(int i = 1; i <= n; i++) {
        if(adj[i].size() == 1) {
            a++;
        }
        else if(adj[i].size() == n - 1) {
            c++;
        }
        else if(adj[i].size() == 2) {
            b++;
        }
    }

    if(a == 2 && b == n - 2) {
        cout << "bus topology\n";
    }
    else if(a == 0 && b == n) {
        cout << "ring topology\n";
    }
    else if(c == 1 && a == n - 1) {
        cout << "star topology\n";
    }
    else {
        cout << "unknown topology\n";
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