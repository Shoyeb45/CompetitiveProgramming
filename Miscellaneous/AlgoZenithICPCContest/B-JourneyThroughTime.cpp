#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

// Nice question 
int n;
ll eta;

void solve() {
    cin >> n >> eta;

    vector<pair<ll, ll>> a(n);
    for (auto &it : a) {
        cin >> it.first >> it.second;
    }    

    sort(range(a));

    priority_queue<pair<ll, ll>> pq;

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        while (!pq.empty() && (a[i].first - pq.top().second) > eta) {  // pop out which does not satisfy the condition 
            pq.pop();
        }

        if (!pq.empty()) {
            ll curr = pq.top().first + a[i].first + a[i].second;  
            ans = max (ans, curr); 
        }
        pq.push({a[i].second - a[i].first, a[i].first});
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