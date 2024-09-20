#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n, m, k, w;
ll prefixSol(vector<ll> &h) {
    vector<ll> row(n + 1, 0);
    for(int i = 1; i <= max(n - k + 1, 0); i++) {
        row[i]++;
        if(i + k <= n) {
            row[i + k]--;
        }
    }

    vector<ll> col(m + 1, 0);
    for(int i = 1; i <= max(m - k + 1, 0); i++) {
        col[i]++;
        if(i + k <= m) {
            col[i + k]--;
        }
    }

    for(int i = 1; i <= n; i++) {
        row[i] += row[i - 1];
    }

    for(int i = 1; i <= m; i++) {
        col[i] += col[i - 1];
    }

    vector<ll> repeat;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            repeat.push_back(1LL * row[i] * col[j]);
        }
    }

    sort(repeat.rbegin(), repeat.rend());

    ll ans = 0;
    for(int i = 0; i < h.size(); i++) {
        ans += h[i] * repeat[i];
    }
    return ans;
}


ll mathSol(vector<ll> &h) {
    ll ans = 0;

    vector<ll> repeat;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            repeat.push_back( (min(1LL * i, 1LL * (n - k)) - max(-1 * 1LL, 1LL * (i - k))) * (min(1LL *  j, 1LL * (m - k )) - max(-1 * 1LL, 1LL * (j - k))) );
        }
    }
    sort(repeat.rbegin(), repeat.rend());

    for(int i = 0; i < h.size(); i++) {
        ans += h[i] * repeat[i];
    }

    return ans;
}

void solve() {
    cin >> n >> m >> k >> w;
    vector<ll> h(w);
    for(auto &x: h) {
        cin >> x;
    }

    sort(h.rbegin(), h.rend());
    // ll ans = prefixSol(h);   // prefix sum solution
    ll ans = mathSol(h);        // Math solution

    cout << ans << '\n';
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
