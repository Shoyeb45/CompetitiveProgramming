#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;


void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> prefSum(n + 1);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        prefSum[i + 1] += prefSum[i] + a[i];
    }

    for(int i = 1; i <= n; i++) {
        prefSum[i] %= 7;
    } 

    unordered_map<ll, ll> mp;
    for(int i = n; i >= 1; i--) {
        mp[prefSum[i]] = i;
    }

    ll ans = 0;

    for(ll i = n; i >= 1; i--) {
        if(prefSum[i] == 0) {
            ans = max(ans, i);
        } 
        else {
            ans = max(ans, i - mp[prefSum[i]]);
        }
    }    
    cout << ans << '\n';
}

int main() {
    freopen("div7.in", "r", stdin);
	// the following line creates/overwrites the output file
	freopen("div7.out", "w", stdout);

    NFS
    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}
