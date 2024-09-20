#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n, q;
vector<pair<ll, int>> a;
int lowerBound(ll k) {
    int low = 0, high = n - 1;
    int ans = n;
    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(a[mid].first > k) {
            ans = a[mid].second;
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
        cin >> a[i].first;
        a[i].second = i;
    }

    vector<ll> prefix(n + 1, 0);

    for(int i = 1; i <= n; i++) {
        prefix[i] += prefix[i - 1] + a[i - 1].first;
    }

    sort(range(a));
    
    while(q--) {
        ll k;
        cin >> k;
        int ind = lowerBound(k);
        cout << prefix[ind] << ' ';
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
