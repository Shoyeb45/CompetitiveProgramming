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
    vector<ll> a(n, 0);
    ll mx = 0, mn = 1e9 + 1;
    for(auto &x: a) {
        cin >> x;
        mx = max(mx, x);
        mn = min(mn, x);
    } 

    vector<ll> ans(m, 0);

    for(int i = 0; i < m; i++) {
        char c;
        ll l, r;
        cin >> c >> l >> r;

        if((mn >= l && mn <= r) && (mx >= l && mx <= r)) {
            if(c == '+') {
                mn++;
                mx++;
            }
            else {
                mn--;
                mx--;
            }
        } 
        else if((mn >= l && mn <= r)) {
            if(c == '+') {
                mn++;
            }
            else {
                mn--;
            }
        }
        else if((mx >= l && mx <= r)) {
            if(c == '+') {
                mx++;
            }
            else {
                mx--;
            }
        }

        ans[i] = mx;
    }

    for(auto x: ans) {
        cout << x << " " ;
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
