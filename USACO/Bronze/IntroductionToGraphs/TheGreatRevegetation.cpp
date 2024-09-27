#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n, m;
void solve() {
    cin >> n >> m;
    vector<int> adj[n + 1];

    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    
}

int main() {
    NFS
    int tt;
    tt = 1;

    while (tt--) {
        solve();
    }
    
    return 0;
}
