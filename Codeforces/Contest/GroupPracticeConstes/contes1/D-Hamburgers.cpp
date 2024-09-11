#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

string s;
vector<ll> n, p;
ll r;

bool f(ll mid, vector<ll> &ing) {
    vector<ll> ind = ing;
    // cout <<"mid:  " << mid << "\n";
    // cout << "ing: " << "\n";
    for(int i = 0; i < 3; i++) {
        ind[i] *= mid;
        // cout << ind[i] << " ";
    }
    // cout << endl;
     for(int i = 0; i < 3; i++) {
        if(ind[i] <= n[i]) {
            ind[i] = 0;
        } else {
            ind[i] -= n[i];
        }
    }

    ll cost = 0;
    for(int i = 0; i < 3; i++) {
        cost += (p[i] * ind[i]);
    }
    // cout << "cost: " << cost << "\n";
    return cost <= r;
}
vector<ll> ingredients(string s) {
    vector<ll> a(3, 0);
    for(int i = 0; i < s.size() ; i++) {
        if(s[i] == 'S') 
            a[1]++;
        else if(s[i] == 'B')
            a[0]++;
        else    
            a[2]++;
    }
    return a;
}

void solve() {
    cin >> s;
    n.resize(3);
    p.resize(3);
    for(int i = 0; i < 3; i++) {
        cin >> n[i];
    }
    for(int i = 0; i < 3; i++) {
        cin >> p[i];
    }
    cin >> r;

    vector<ll> ing = ingredients(s);
    // cout << "ingered: " << "\n";
    // for(auto x: ing) {
    //     cout << x << " ";
        
    // }
    // cout << "\n";
    ll low = 0, high = 1;
    while(f(high, ing)) {
        high *= 2;
    }
    ll ans = high;

    while(low <= high) {
        ll mid = low + (high - low) / 2;
        if(f(mid, ing)) {
            ans = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    } 
    // cout << f(3, ing) << "\n";
    cout << ans << '\n';
}

int main() {
    NFS
    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}
