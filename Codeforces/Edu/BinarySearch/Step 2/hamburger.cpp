#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

bool check(vector<ll> &ing, vector<ll> &n, vector<ll> &p, ll mid, ll r) {
    loop(i, 3) 
        ing[i] *= mid;
    
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

    vector<ll> ingredient(3, 0) = ingredients(s);

    ll low = 0, high = 1e12, ans = 0;
    while(low <= high) {
        ll mid = low + (high - low)/2;
        if(check()) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
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
