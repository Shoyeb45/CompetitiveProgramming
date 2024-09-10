#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

ll n;
bool allZero(unordered_map<ll, int> &mp) {
    for(auto x: mp) {
        if(x.second != 0) {
            return false;
        }
    }
    return true;
}
void solve() {
    cin >> n;
    unordered_map<ll, int> mp;

    if(n == 2) {
        cout << n << '\n';
        return;
    }
    ll temp = n;
    for(int i = 2; 1LL * i * i <= temp; i++) {
        while(n % i == 0) {
            mp[i]++;
            n /= i;
        }
    }
    if(n > 2) {
        mp[n]++;
    }
    
    ll ans = 0;
    // for(auto x: mp) {
    //     cout << x.first << " " << x.second << "\n";
    // }
    while(!allZero(mp)) {
        ll temp = 1;
        int pw = INT_MAX;
        for(auto &x: mp) {
            if(x.second > 0) {
                temp *= x.first;
                pw = min(pw, x.second);
            }
        }
        // cout << temp << " " << pw << "\n";
        for(auto it = mp.begin(); it != mp.end(); it++) {
            it -> second = max(it -> second - pw, 0);
        }
        ans += temp * pw;
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
