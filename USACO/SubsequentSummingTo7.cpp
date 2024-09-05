#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

ll binarySearch(vector<ll> &a, ll low, ll high, ll target) {
    while(low < high) {
        ll mid = low + (high - low) / 2;
        // cout << "a[mid] : " << a[mid] << "\n";
        // cout << "mid: " << mid << '\n';
        if(a[mid] == target) {
            return mid;
        }
        else if(a[mid] > target) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }

    }
    return -1;
}

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> prefSum(n + 1);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        prefSum[i + 1] += prefSum[i] + a[i];
    }
    
    ll ans = 0;
    for(ll i = n; i >= 1; i--) {
        if(prefSum[i] % 7 == 0) {
            ans = max(ans, i);
        } 
        else {
            ll req = prefSum[i] - (prefSum[i] - (prefSum[i] % 7));
            ll x = binarySearch(prefSum, 1, i - 1, req);
            
            if(x != -1) {
                ans = max(ans, i - (x - 1) - 1);
            }
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
