#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n;
void solve() {
    cin >> n;
    vector<int> adj[n + 1];

    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<int> q;
    q.push(1);
    int mxDeg = 1;
    vector<bool> visited(n + 1, false);
    visited[1] = true;
    while(!q.empty()) {
        int curr = q.front();
        visited[curr] = true;
        q.pop();

        int temp = 0;
        for(auto node: adj[curr]) {
            if(!visited[node]) {
                q.push(node);
            }
            temp++;
        }
        mxDeg = max(mxDeg, temp);
    }

    cout << mxDeg + 1 << '\n';
}

int main() {
    freopen("planting.in", "r", stdin);
    freopen("planting.out", "w", stdout);
    NFS
    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}
