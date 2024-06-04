#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

bool check(vector<ll> &ing, vector<ll> &n, vector<ll> &p, ll mid, ll r) {
    vector<ll> ind = ing;
    loop(i, 3) 
        ind[i] *= mid;
    
    // loop(i, 3) {
    //     cout << "O - ind: " << i + 1 << " is " << ind[i] << '\n';
    // }
    loop(i, 3) {
        if(ind[i] <= n[i]) {
            ind[i] = 0;
        } else {
            ind[i] -= n[i];
        }
    }
    // loop(i, 3) {
    //     cout << "ind: " << i + 1 << " is " << ind[i] << '\n';
    // }
    ll cost = 0;
    loop(i, 3) {
        cost += (p[i] * ind[i]);
    }
    // cout << "Cost: " << cost << '\n';
    return (cost <= r);
    
}

vector<ll> ingredients(string s) {
    vector<ll> a(3, 0);
    loop(i, s.size()) {
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
    string s;
    cin >> s;
    vector<ll> n(3, 0), p(3, 0);
    cin >> n[0] >> n[1] >> n[2];
    cin >> p[0] >> p[1] >> p[2];
    ll r;
    cin >> r;

    vector<ll> ingredient = ingredients(s);

    ll low = 0, high = 1;
    while(check(ingredient, n, p, high, r)) {
        high *= 2;
    }
    ll ans =  high;
    while(low <= high) {
        ll mid = low + (high - low)/2;
        // cout << "Check: " << check(ingredient, n, p, (low+high)/2, r) << '\n';
        if(check(ingredient, n, p, mid, r)) {
            ans = mid;
            // cout << "Mid " << mid << '\n';
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    // cout << check(ingredient, n, p, 499999999998, r) << '\n';
    // cout << "LOW: " << low << " High: " << high << '\n';
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}
