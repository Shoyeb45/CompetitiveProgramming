#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n, q;
vector<ll> a;
int lowerBound(vector<ll> &a, ll k) {
    int low = 1, high = n;
    int ans = n + 1;
    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(a[mid] > k) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return ans;
}

void solve() {
    cin >> n >> q;
    a.resize(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<ll> prefix(n + 1, 0);
    vector<ll> prefixMax(n + 1, 0);

    for(int i = 1; i <= n; i++) {
        prefix[i] += prefix[i - 1] + a[i - 1];
        prefixMax[i] = max(prefixMax[i - 1], a[i - 1]);
    }
    
    while(q--) {
        ll k;
        cin >> k;
      
        int ind = lowerBound(prefixMax, k);
        cout << prefix[ind - 1] << " ";
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
