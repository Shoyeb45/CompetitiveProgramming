#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n;
vector<ll> a;
void solve() {
    cin >> n;
    a.resize(n);
    for(auto &x: a) {
        cin >> x;
    }

    ll pref = 0, suff = 0;
    int left = 0, right = n - 1; 
    int ans = 0;

    while(left < right) {
        if(pref + a[left] < suff + a[right]) {
            pref += a[left++];
        }
        else if(pref + a[left] > suff + a[right]) {
            suff += a[right--];
        }
        else if(pref + a[left] == suff + a[right]){
            ans = max(ans, (left + 1) + (n - right));
            pref += a[left++], suff += a[right--];
        }
        else {
            pref += a[left++], suff += a[right--];
        }
    }

    cout << ans << "\n";
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