#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n;
void solve() {
    cin >> n;
    vector<int> p(n), a(n), b(n);
    for(auto &x: p) {
        cin >> x;
    }
    for(auto &x: a) {
        cin >> x;
        x--;
    }
    for(auto &x: b) {
        cin >> x;
        x--;
    }

    set<pair<int, int>> st[3];

    for(int i = 0; i < n; i++) {
        st[a[i]].insert(make_pair(p[i], b[i]));
        st[b[i]].insert(make_pair(p[i], a[i]));
    }

    int m;
    cin >> m;

    while(m--) {
        int x;
        cin >> x;
        x--;

        if(st[x].empty()) {
            cout << -1 << " ";
            continue;
        }

        int ans = st[x].begin() -> first;
        cout << ans << " "; 

        int b = st[x].begin() -> second;
        st[x].erase({ans, b});
        st[b].erase({ans, x});
    }
}

int main() {
    NFS
    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}