#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

void solve() {
    int n, p; cin >> n >> p;
    vector<ll> a(n);
    vector<ll> b(n);

    loop(i, n)  cin >> a[i];
    loop(i, n)  cin >> b[i];

    if(n == 1) {
        cout << p <<endl;
        return;
    }

    vector<pair<ll, ll>> vp;
    loop(i, n) {
        vp.push_back({b[i], a[i]});
    }
    sort(vp.begin(), vp.end());
   
    ll cost = p;
    ll number = 1;
    bool check = false;
    loop(i, n) {
        if(vp[i].second > p) {
            check = true;
            break;
        }

        if(vp[i].second > n) {
            cost += (vp[i].first * (n - number));
            number += (n - number);
        }
        else  {
            cost += ((ll)(vp[i].first) * (ll)(vp[i].second));
            number += (vp[i].second);
        }

        if(number >= n) {
            cost -= ((number - n) * vp[i].first);
            break;
        }
    }

    if(check) {
        cost += ((n - number) * p);
    }
    cout << cost << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    
    return 0;
}
