#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n;
ll x, y;


void solve() {
    cin >> n >> x >> y;
    vector<pair<ll, ll>> vp(n);
    for(auto &x : vp) {
        cin >> x.first;
    }
    for(auto &x : vp) {
        cin >> x.second;
    }

    sort(vp.rbegin(), vp.rend());

    ll sumX = 0, sumY = 0;
    int ans = n;
    for(int i = 0; i < n; i++) {
        sumX += vp[i].first, sumY += vp[i].second;
        if(sumX > x || sumY > y) {
            ans = i + 1;
            break;
        }
    }
    
    
    sort(vp.begin(), vp.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    });

    sumX = sumY = 0;
    for(int i = 0; i < n; i++) {
        sumX += vp[i].first, sumY += vp[i].second;
        if(sumX > x || sumY > y) {
            ans = min(ans, i + 1);
            break;
        }
    }

    cout << ans << "\n";
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