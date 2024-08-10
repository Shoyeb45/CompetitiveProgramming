#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;


int n, m;
void solve() {
    cin >> n >> m;
    vector<int> adj[n + 1];

    loop(i, n) {
        adj[i + 1].push_back(i + 2);
    }
    loop(i, m) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
}

int main() {
    NFS
    int tt;
    tt = 1;
    cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}
