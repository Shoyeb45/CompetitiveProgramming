#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

class Point {
    public:
        int x;
        int y;
};

int n, m;
vector<Point> cowPos;
vector<vector<int>> adj;
vector<bool> vis;
int xMax = 0, xMin = 0, yMax = 0, yMin = 0;

void bfs(int start) {
    vis[start] = 1;
    xMax = max(cowPos[start].x, xMax), xMin = min(cowPos[start].x, xMin);
    yMax = max(cowPos[start].y, yMax), yMin = min(cowPos[start].y, yMin);

    queue<int> q;
    q.push(start);

    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        for(auto node: adj[curr]) {
            if(!vis[node]) {
                vis[node] = 1;
                xMax = max(cowPos[node].x, xMax), xMin = min(cowPos[node].x, xMin);
                yMax = max(cowPos[node].y, yMax), yMin = min(cowPos[node].y, yMin);
                q.push(node);
            }
        }
    }
}
void solve() {
    cin >> n >> m;
    cowPos.resize(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> cowPos[i].x >> cowPos[i].y;
    }

    adj.resize(n + 1);
    for(int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vis.resize(n + 1, 0);

    ll ans = INT_MAX;
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            xMax = yMax = INT_MIN;
            yMin = xMin = INT_MAX;
            bfs(i);
            cerr << i << " \n" << "(xmax, xmin) = " << xMax  << " " << xMin << "\n(ymax, ymin) " << yMax << " " << yMin << "\n";  
            ll temp = 2LL * ((xMax - xMin) + (yMax - yMin));
            ans = min(ans, temp);
        }
    }

    cout << ans << "\n";
}

int main() {
    NFS
    //  #ifndef ONLINE_JUDGE
    //     freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\input.in", "r", stdin);
    //     freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\output.out", "w", stdout);
    //     freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\error.out", "w", stderr);
    // #endif
        freopen("fenceplan.in", "r", stdin);
        freopen("fenceplan.out", "w", stdout);
    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}