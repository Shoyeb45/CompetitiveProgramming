#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

void solve() {
    int n, k;
    cin >> n >> k;
    
    unordered_map<int, vector<pair<int, int>>> mp;
    
    for (int i = 0; i < k; i++) {
        int l, r, m;
        cin >> l >> r >> m;
        mp[m].push_back(make_pair(l - 1, r));
    }
    
    vector<int> a(n, 1);
    
    for (int i = 1; i <= n; i++) {
        auto x = mp[i];
        
        for (auto p: x) {
            int mn = *min_element(a.begin() + p.first, a.begin() + p.second);
            if (mn == i) {
                for (int k = p.first; k < p.second; k++) {
                    a[k] = i + 1; 
                }
            }
        }
    }
    
    for (auto x: a) {
        if (x == n + 1) {
            cout << -1 << "\n";
            return;
        }
    }
    
    for (auto x: a) {
        cout << x << " ";
    }
    cout << "\n";
    
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