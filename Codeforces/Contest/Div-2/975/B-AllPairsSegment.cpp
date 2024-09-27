#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n, q;
vector<ll> a;
void solve() {
    cin >> n >> q;
    a.resize(n);

    for(auto &x: a) {
        cin >> x;
    }

    vector<ll> occur;
    map<ll, ll> mp;

    ll prev = 0;
    for(int i = 0; i <= n / 2; i++) {
        if(i == n / 2 && n % 2 == 0) {
            continue;
        }
        if(i == 0) {
            occur.push_back(n - 1);
            prev = n - 1;
        }
        else if(i == 1) {
            ll curr = prev + (n - (i + 1));
            prev = curr;
            occur.push_back(curr);
        }
        else {
            ll curr = (n - i - 1) + (prev - (i - 1));
            prev = curr;
            occur.push_back(curr);
        }
    }

    int i = n / 2 - 1;
   

    for(; i >= 0; i--) {
        occur.push_back(occur[i]);
    }


    for(i = 0 ; i < n - 1; i++) {
        mp[occur[i]]++;
        mp[occur[i] - i] += a[i + 1] - a[i] - 1;
    }

    mp[occur.back()]++;
  

    while(q--) {
        ll x;
        cin >> x;

        if(mp.find(x) != mp.end()) {
            cout << mp[x] << " ";
        }
        else {
            cout << 0 << " ";
        }
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