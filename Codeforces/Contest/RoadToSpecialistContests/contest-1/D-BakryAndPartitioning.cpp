#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
#define range(x) (x).begin(), (x).end()
#define rrange(x) (x).rbegin(), (x).rend()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;


int ask(vector<int> &query) {
    if (query.size() < 2) return -1;

    cout << "? " << query.size() << " ";
    for (int &v: query) cout << v << " ";

    cout << endl;

    int mx;
    cin >> mx;
    return mx;
}

void solve() {
    int n;
    cin >> n;
    vector<int> adj[n + 1];

    for (int i = 0, u, v; i < n - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> trav;

    queue<pair<int, int>> q;
    
    q.push({1, -1});
    trav.push_back(1);
    vector<int> parent(n + 1);
    parent[1] = -1;

    while (!q.empty()) {
        int u = q.front().first;
        int p = q.front().second;
        q.pop();

        for (int& v: adj[u]) {
            if (v != p) {
                trav.push_back(v);
                q.push({v, u});
                parent[v] = u;
            }
        }
    }
    int mx = ask(trav);

    int low = 1, high = trav.size() - 1;
    int ans = 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        
        vector<int> temp;
        for (int i = 0; i <= mid; i++) temp.push_back(trav[i]);

        if (ask(temp) < mx) {
            low = mid + 1;
        } else {
            ans = mid;
            high = mid - 1;
        }
    }

    cout << "! " << trav[ans] << " " << parent[trav[ans]] << endl;
}   



int main() {
    NFS
    // #ifndef ONLINE_JUDGE
    //     freopen("/home/shoyeb45/Codes/CompetitiveProgramming/stdin-stdout-stderr/in.txt", "r", stdin);
    //     freopen("/home/shoyeb45/Codes/CompetitiveProgramming/stdin-stdout-stderr/out.txt", "w", stdout);
    //     freopen("/home/shoyeb45/Codes/CompetitiveProgramming/stdin-stdout-stderr/err.txt", "w", stderr);
    // #endif
    int tt;
    tt = 1;
    // cin >> tt;

    for (int i = 1; i <= tt; i++) {
        solve();
    }

    return 0;
}