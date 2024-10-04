#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n, q;
vector<ll> a;
void solve() {
    cin >> n >> q;
    a.resize(n);
    for(auto &x: a) {
        cin >> x;
    }

    vector<int> ind[31];
    for(int i = 1; i <= 30; i++) {
        for(int j = 0; j < n; j++) {
            ll pw = (1 << i);
            if(a[j] % pw == 0) {
                ind[i].push_back(j);
            }
        }
    }

    ll mn = 31;

    while(q--) {
        ll x;
        cin >> x;
        if(ind[x].empty()) {
            continue;
        }
        if(x < mn) {
            ll temp = (1 << (x - 1));
            mn = min(x, mn);
            for(auto idx: ind[x]) {
                a[idx] += temp;
            }
        }
    }

    for(auto x: a) {
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